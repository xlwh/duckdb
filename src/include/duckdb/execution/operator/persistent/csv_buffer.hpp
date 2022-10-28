//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/execution/operator/persistent/csv_buffer.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/common/constants.hpp"
#include "duckdb/execution/operator/persistent/csv_file_handle.hpp"

namespace duckdb {

class CSVBuffer {
public:
	//! Initial buffer read size; can be extended for long lines
	static constexpr idx_t INITIAL_BUFFER_SIZE = 16384;
	//! Larger buffer size for non disk files
	static constexpr idx_t INITIAL_BUFFER_SIZE_LARGE = 10000000; // 10MB
	//! Colossal buffer size for multi-threading
	static constexpr idx_t INITIAL_BUFFER_SIZE_COLOSSAL = 32000000; // 32MB

	//! Constructor for Initial Buffer
	CSVBuffer(idx_t buffer_size_p, CSVFileHandle &file_handle);

	//! Constructor for `Next()` Buffers
	CSVBuffer(unique_ptr<char[]> buffer_p, idx_t buffer_size_p, idx_t actual_size_p);

	//! Creates a new buffer with the next part of the CSV File
	unique_ptr<CSVBuffer> Next(CSVFileHandle &file_handle);

	//! Gets the buffer actual size
	idx_t GetBufferSize();

	//! Gets the start position of the buffer, only relevant for the first time it's scanned
	idx_t GetStart();

	//! If it's the first buffer and the first time we are reading it.
	bool FirstCSVRead();

	//! The actual buffer
	unique_ptr<char[]> buffer;

private:
	//! The allocated size of the buffer
	idx_t buffer_size;
	//! Actual size can be smaller than the buffer size in case we allocate it too optimistically.
	idx_t actual_size;
	//! We need to check for Byte Order Mark, to define the start position of this buffer
	//! https://en.wikipedia.org/wiki/Byte_order_mark#UTF-8
	idx_t start_position = 0;
	//! If this is the first buffer of the file
	bool first_buffer = false;

	//	bool large_buffers = mode == ParserMode::PARSING && !file_handle->OnDiskFile() && file_handle->CanSeek();
	//	//	idx_t buffer_read_size = large_buffers ? INITIAL_BUFFER_SIZE_LARGE : INITIAL_BUFFER_SIZE;
	//	idx_t buffer_read_size = bytes_per_thread;
};
} // namespace duckdb
