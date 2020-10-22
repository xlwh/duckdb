//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/execution/partitionable_hashtable.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/execution/aggregate_hashtable.hpp"

namespace duckdb {

struct RadixPartitionInfo {
	RadixPartitionInfo(idx_t _n_partitions_upper_bound);
	idx_t radix_partitions;
	idx_t radix_bits;
	hash_t radix_mask;
	constexpr static idx_t RADIX_SHIFT = 24;
};

typedef vector<unique_ptr<GroupedAggregateHashTable>> HashTableList;

class PartitionableHashTable {
public:
	PartitionableHashTable(BufferManager &_buffer_manager, RadixPartitionInfo &_partition_info,
	                       vector<LogicalType> _group_types, vector<LogicalType> _payload_types,
	                       vector<BoundAggregateExpression *> _bindings);

	idx_t AddChunk(DataChunk &groups, DataChunk &payload, bool do_partition);
	void Partition();
	bool IsPartitioned();

	HashTableList GetPartition(idx_t partition);
	HashTableList GetUnpartitioned();

private:
	BufferManager &buffer_manager;
	vector<LogicalType> group_types;
	vector<LogicalType> payload_types;
	vector<BoundAggregateExpression *> bindings;

	bool is_partitioned;
	RadixPartitionInfo &partition_info;
	vector<SelectionVector> sel_vectors;
	vector<idx_t> sel_vector_sizes;
	DataChunk group_subset, payload_subset;
	Vector hashes, hashes_subset;

	HashTableList unpartitioned_hts;
	unordered_map<hash_t, HashTableList> radix_partitioned_hts;
};

} // namespace duckdb
