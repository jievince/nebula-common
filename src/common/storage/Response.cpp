/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "common/storage/Response.h"

namespace nebula {

bool ScanEdgeResponse::operator==(const ScanEdgeResponse &rhs) const {
    if (!(result == rhs.result)) {
        return false;
    }
    if (edgeData != rhs.edgeData) {
        return false;
    }
    if (hasNext != rhs.hasNext) {
        return false;
    }
    return checkPointer(nextCursor.get(), rhs.nextCursor.get());
}

bool ScanVertexResponse::operator==(const ScanVertexResponse &rhs) const {
    if (!(result == rhs.result)) {
        return false;
    }
    if (vertexData != rhs.vertexData) {
        return false;
    }
    if (hasNext != rhs.hasNext) {
        return false;
    }
    return checkPointer(nextCursor.get(), rhs.nextCursor.get());
}

}  // namespace nebula

