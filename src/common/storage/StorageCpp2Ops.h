/* Copyright (c) 2021 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_STORAGE_CPP2OPS_H_
#define COMMON_STORAGE_CPP2OPS_H_
#include "common/thrift/ThriftCpp2OpsHelper.h"

namespace nebula {
struct PartitionResult;
struct ResponseCommon;
struct ScanEdgeResponse;
struct ScanVertexResponse;
}   // namespace nebula

namespace apache::thrift {

SPECIALIZE_CPP2OPS(nebula::PartitionResult);
SPECIALIZE_CPP2OPS(nebula::ResponseCommon);
SPECIALIZE_CPP2OPS(nebula::ScanEdgeResponse);
SPECIALIZE_CPP2OPS(nebula::ScanVertexResponse);

}   // namespace apache::thrift

#endif   // COMMON_STORAGE_CPP2OPS_H_
