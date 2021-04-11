/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_GRAPH_RESPONSE_H
#define COMMON_GRAPH_RESPONSE_H

#include <algorithm>
#include <memory>
#include <unordered_map>
#include <vector>

#include "common/datatypes/DataSet.h"
#include "common/datatypes/HostAddr.h"

namespace nebula {

enum class ErrorCode {
    SUCCEEDED = 0,

    // RPC Failure
    E_DISCONNECTED = -1,
    E_FAILED_TO_CONNECT = -2,
    E_RPC_FAILURE = -3,

    // storage failures
    E_LEADER_CHANGED = -11,
    E_KEY_HAS_EXISTS = -12,
    E_SPACE_NOT_FOUND = -13,
    E_PART_NOT_FOUND = -14,
    E_KEY_NOT_FOUND = -15,
    E_CONSENSUS_ERROR = -16,
    E_DATA_TYPE_MISMATCH = -17,
    E_INVALID_FIELD_VALUE = -18,
    E_REBUILD_INDEX_FAILED = -19,
    E_INVALID_OPERATION = -20,
    E_NOT_NULLABLE = -21,          // Not allowed to be null
    E_FIELD_UNSET = -22,           // The field neither can be NULL, nor has a default value
    E_OUT_OF_RANGE = -23,          // Value exceeds the range of type
    E_ATOMIC_OP_FAILED = -24,      // Atomic operation failed
    E_DATA_CONFLICT_ERROR = -25,   // data conflict, for index write without toss.

    // meta failures
    E_EDGE_PROP_NOT_FOUND = -31,
    E_TAG_PROP_NOT_FOUND = -32,
    E_IMPROPER_DATA_TYPE = -33,
    E_EDGE_NOT_FOUND = -34,
    E_TAG_NOT_FOUND = -35,
    E_INVALID_SPACEVIDLEN = -36,
    E_INDEX_NOT_FOUND = -37,

    // Invalid request
    E_INVALID_FILTER = -41,
    E_INVALID_UPDATER = -42,
    E_INVALID_STORE = -43,
    E_INVALID_PEER = -44,
    E_RETRY_EXHAUSTED = -45,
    E_TRANSFER_LEADER_FAILED = -46,
    E_INVALID_STAT_TYPE = -47,
    E_INVALID_VID = -48,
    E_NO_TRANSFORMED = -49,

    // meta client failed
    E_LOAD_META_FAILED = -51,

    // checkpoint failed
    E_FAILED_TO_CHECKPOINT = -60,
    E_CHECKPOINT_BLOCKED = -61,

    // backup failed
    E_BACKUP_FAILED = -65,

    // partial result, used for kv interfaces
    E_PARTIAL_RESULT = -71,

    // Filter out
    E_FILTER_OUT = -81,
    E_INVALID_DATA = -82,

    // transaction
    E_MUTATE_EDGE_CONFLICT = -85,
    E_OUTDATED_LOCK = -86,

    // task manager failed
    E_INVALID_TASK_PARA = -90,
    E_USER_CANCEL = -99,

    E_UNKNOWN = -100,
};

template <typename T>
bool inline checkPointer(const T *lhs, const T *rhs) {
    if (lhs == rhs) {
        return true;
    } else if (lhs != nullptr && rhs != nullptr) {
        return *lhs == *rhs;
    } else {
        return false;
    }
}

struct PartitionResult {
    void __clear() {
        code = ErrorCode::SUCCEEDED;
        partId = -1;
        leader = nullptr;
    }

    void clear() {
        __clear();
    }

    bool operator==(const PartitionResult &rhs) const {
        if (code != rhs.code) {
            return false;
        }
        if (partId != rhs.partId) {
            return false;
        }
        return checkPointer(leader.get(), rhs.leader.get());
    }

    bool operator<(const PartitionResult &rhs) const {
        if (!(code == rhs.code)) {
            return code < rhs.code;
        }
        if (partId != rhs.partId) {
            return partId < rhs.partId;
        }
        bool hasLeader = leader != nullptr;
        bool rhsHasLeader = rhs.leader != nullptr;
        if (hasLeader != rhsHasLeader) {
            return hasLeader < rhsHasLeader;
        }
        if (hasLeader) {
            return *leader < *rhs.leader;
        }
        return false;
    }

    ErrorCode code;
    int32_t partId;
    std::unique_ptr<nebula::HostAddr> leader{nullptr};
};

struct ResponseCommon {
    void __clear() {
        failedParts.clear();
        latencyInUs = 0;
    }

    void clear() {
        __clear();
    }

    bool operator==(const ResponseCommon &rhs) const {
        if (failedParts != rhs.failedParts) {
            return false;
        }
        return latencyInUs == rhs.latencyInUs;
    }

    bool operator<(const ResponseCommon &rhs) const {
        if (!(failedParts == rhs.failedParts)) {
            return failedParts < rhs.failedParts;
        }
        return latencyInUs < rhs.latencyInUs;
    }

    std::vector<PartitionResult> failedParts;
    int32_t latencyInUs;
};

// TODO(shylock) use optional for optional in thrift instead of pointer

struct ScanEdgeResponse {
    void __clear() {
        result.clear();
        edgeData.clear();
        hasNext = false;
        nextCursor = nullptr;
    }

    void clear() {
        __clear();
    }

    bool operator==(const ScanEdgeResponse &rhs) const;

    ResponseCommon result;
    nebula::DataSet edgeData;
    bool hasNext;
    std::unique_ptr<std::string> nextCursor{nullptr};
};

struct ScanVertexResponse {
    void __clear() {
        result.clear();
        vertexData.clear();
        hasNext = false;
        nextCursor = nullptr;
    }

    void clear() {
        __clear();
    }

    bool operator==(const ScanVertexResponse &rhs) const;

    ResponseCommon result;
    nebula::DataSet vertexData;
    bool hasNext;
    std::unique_ptr<std::string> nextCursor{nullptr};
};

}   // namespace nebula

#endif   // COMMON_GRAPH_RESPONSE_H
