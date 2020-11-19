#include "duckdb/function/scalar/string_functions.hpp"

#include "duckdb/common/algorithm.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/common/vector_operations/vector_operations.hpp"
#include "duckdb/common/vector_operations/ternary_executor.hpp"
#include "duckdb/storage/statistics/string_statistics.hpp"
#include "duckdb/planner/expression/bound_function_expression.hpp"
#include "utf8proc.hpp"

using namespace std;

namespace duckdb {

string_t substring_empty_string(Vector &result) {
	auto result_string = StringVector::EmptyString(result, 0);
	result_string.Finalize();
	return result_string;
}

string_t substring_slice(Vector &result, const char *input_data, int64_t offset, int64_t length) {
	auto result_string = StringVector::EmptyString(result, length);
	auto result_data = result_string.GetDataWriteable();
	memcpy(result_data, input_data + offset, length);
	result_string.Finalize();
	return result_string;
}

// compute start and end characters from the given input size and offset/length
bool substring_start_end(int64_t input_size, int64_t offset, int64_t length, int64_t &start, int64_t &end) {
	if (length == 0) {
		return false;
	}
	if (offset > 0) {
		// positive offset: scan from start
		start = MinValue<int64_t>(input_size, offset - 1);
	} else if (offset < 0) {
		// negative offset: scan from end (i.e. start = end + offset)
		start = MaxValue<int64_t>(input_size + offset, 0);
	} else {
		// offset = 0: special case, we start 1 character BEHIND the first character
		start = 0;
		length--;
		if (length <= 0) {
			return false;
		}
	}
	if (length > 0) {
		// positive length: go forward (i.e. end = start + offset)
		end = MinValue<int64_t>(input_size, start + length);
	} else {
		// negative length: go backwards (i.e. end = start, start = start + length)
		end = start;
		start = MaxValue<int64_t>(0, end + length);
	}
	if (start == end) {
		return false;
	}
	D_ASSERT(start < end);
	return true;
}

string_t substring_ascii_only(Vector &result, string_t input, int64_t offset, int64_t length) {
	auto input_data = input.GetDataUnsafe();
	auto input_size = input.GetSize();

	int64_t start, end;
	if (!substring_start_end(input_size, offset, length, start, end)) {
		return substring_empty_string(result);
	}
	return substring_slice(result, input_data, start, end - start);
}

string_t SubstringFun::substring_scalar_function(Vector &result, string_t input, int32_t offset, int32_t length) {
	auto input_data = input.GetDataUnsafe();
	auto input_size = input.GetSize();

	// we don't know yet if the substring is ascii, but we assume it is (for now)
	// first get the start and end as if this was an ascii string
	int64_t start, end;
	if (!substring_start_end(input_size, offset, length, start, end)) {
		return substring_empty_string(result);
	}

	// now check if all the characters between 0 and end are ascii characters
	// note that we scan one further to check for a potential combining diacritics (e.g. i + diacritic is ï)
	bool is_ascii = true;
	idx_t ascii_end = MinValue<idx_t>(end + 1, input_size);
	for(idx_t i = 0; i < ascii_end; i++) {
		if (input_data[i] & 0x80) {
			// found a non-ascii character: eek
			is_ascii = false;
			break;
		}
	}
	if (is_ascii) {
		// all characters are ascii, we can just slice the substring
		return substring_slice(result, input_data, start, end - start);
	}
	// if the characters are not ascii, we need to scan grapheme clusters
	// first figure out which direction we need to scan
	// offset = 0 case is taken care of in substring_start_end
	if (offset < 0) {
		// negative offset, this case is more difficult
		// we first need to count the number of characters in the string
		idx_t num_characters = 0;
		utf8proc_grapheme_callback(input_data, input_size, [&](size_t start, size_t end) {
			num_characters++;
			return true;
		});
		// now call substring start and end again, but with the number of unicode characters this time
		substring_start_end(num_characters, offset, length, start, end);
	}

	// now scan the graphemes of the string to find the positions of the start and end characters
	int64_t current_character = 0;
	idx_t start_pos = INVALID_INDEX, end_pos = input_size;
	utf8proc_grapheme_callback(input_data, input_size, [&](size_t gstart, size_t gend) {
		if (current_character == start) {
			start_pos = gstart;
		} else if (current_character == end) {
			end_pos = gstart;
			return false;
		}
		current_character++;
		return true;
	});
	if (start_pos == INVALID_INDEX) {
		return substring_empty_string(result);
	}
	// after we have found these, we can slice the substring
	return substring_slice(result, input_data, start_pos, end_pos - start_pos);
}

static void substring_function(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &input_vector = args.data[0];
	auto &offset_vector = args.data[1];
	if (args.column_count() == 3) {
		auto &length_vector = args.data[2];

		TernaryExecutor::Execute<string_t, int32_t, int32_t, string_t>(
			input_vector, offset_vector, length_vector, result, args.size(),
			[&](string_t input_string, int32_t offset, int32_t length) {
				return SubstringFun::substring_scalar_function(result, input_string, offset, length);
			});
	} else {
		BinaryExecutor::Execute<string_t, int32_t, string_t, true>(input_vector, offset_vector, result, args.size(),
			[&](string_t input_string, int32_t offset) {
				return SubstringFun::substring_scalar_function(result, input_string, offset, numeric_limits<int32_t>::max());
			});
	}
}

static void substring_function_ascii(DataChunk &args, ExpressionState &state, Vector &result) {
	auto &input_vector = args.data[0];
	auto &offset_vector = args.data[1];
	if (args.column_count() == 3) {
		auto &length_vector = args.data[2];

		TernaryExecutor::Execute<string_t, int32_t, int32_t, string_t>(
			input_vector, offset_vector, length_vector, result, args.size(),
			[&](string_t input_string, int32_t offset, int32_t length) {
				return substring_ascii_only(result, input_string, offset, length);
			});
	} else {
		BinaryExecutor::Execute<string_t, int32_t, string_t, true>(input_vector, offset_vector, result, args.size(),
			[&](string_t input_string, int32_t offset) {
				return substring_ascii_only(result, input_string, offset, numeric_limits<int32_t>::max());
			});
	}
}

static unique_ptr<BaseStatistics> substring_propagate_stats(
	ClientContext &context,
	BoundFunctionExpression &expr,
	FunctionData *bind_data,
	vector<unique_ptr<BaseStatistics>> &child_stats) {
	// can only propagate stats if the children have stats
	if (!child_stats[0]) {
		return nullptr;
	}
	// we only care about the stats of the first child (i.e. the string)
	auto &sstats = (StringStatistics &) *child_stats[0];
	if (!sstats.has_unicode) {
		expr.function.function = substring_function_ascii;
	}
	return nullptr;
}

void SubstringFun::RegisterFunction(BuiltinFunctions &set) {
	ScalarFunctionSet substr("substring");
	substr.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER, LogicalType::INTEGER},
	                               LogicalType::VARCHAR, substring_function, false, nullptr, nullptr, substring_propagate_stats));
	substr.AddFunction(ScalarFunction({LogicalType::VARCHAR, LogicalType::INTEGER},
	                               LogicalType::VARCHAR, substring_function, false, nullptr, nullptr, substring_propagate_stats));
	set.AddFunction(substr);
	substr.name = "substr";
	set.AddFunction(substr);
}

} // namespace duckdb
