/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include <gtest/gtest.h>
#include <thrift/lib/cpp2/protocol/Serializer.h>
#include <vector>

#include "common/storage/Response.h"
#include "common/storage/StorageCpp2Ops.h"

namespace nebula {

using serializer = apache::thrift::CompactSerializer;

TEST(ResponseEncodDecodeTest, Basic) {
    // partition result
    {
        std::vector<PartitionResult> prs;
        prs.emplace_back(PartitionResult{});
        prs.emplace_back(PartitionResult{storage::ErrorCode::SUCCEEDED, 174});
        prs.emplace_back(PartitionResult{
            storage::ErrorCode::E_LEADER_CHANGED, 174, std::unique_ptr<nebula::HostAddr>()});
        for (const auto &pr : prs) {
            std::string buf;
            buf.reserve(128);
            serializer::serialize(pr, &buf);
            PartitionResult copy;
            std::size_t s = serializer::deserialize(buf, copy);
            ASSERT_EQ(s, buf.size());
            EXPECT_EQ(pr, copy);
        }
    }
    // response common
    {
        std::vector<ResponseCommon> rcs;
        rcs.emplace_back(ResponseCommon{});
        rcs.emplace_back(ResponseCommon{std::vector<PartitionResult>{}, 496});
        for (const auto &rc : rcs) {
            std::string buf;
            buf.reserve(128);
            serializer::serialize(rc, &buf);
            ResponseCommon copy;
            std::size_t s = serializer::deserialize(buf, copy);
            ASSERT_EQ(s, buf.size());
            EXPECT_EQ(rc, copy);
        }
    }
    // scan edge response
    {
        std::vector<ScanEdgeResponse> resps;
        resps.emplace_back(ScanEdgeResponse{});
        resps.emplace_back(ScanEdgeResponse{ResponseCommon(), nebula::DataSet(), false});
        resps.emplace_back(ScanEdgeResponse{
            ResponseCommon(), nebula::DataSet(), true, std::make_unique<std::string>("A next.")});
        for (const auto &resp : resps) {
            std::string buf;
            buf.reserve(128);
            serializer::serialize(resp, &buf);
            ScanEdgeResponse copy;
            std::size_t s = serializer::deserialize(buf, copy);
            ASSERT_EQ(s, buf.size());
            EXPECT_EQ(resp, copy);
        }
    }
    // scan vertex response
    {
        std::vector<ScanVertexResponse> resps;
        resps.emplace_back(ScanVertexResponse{});
        resps.emplace_back(ScanVertexResponse{ResponseCommon(), nebula::DataSet(), false});
        resps.emplace_back(ScanVertexResponse{
            ResponseCommon(), nebula::DataSet(), true, std::make_unique<std::string>("A next.")});
        for (const auto &resp : resps) {
            std::string buf;
            buf.reserve(128);
            serializer::serialize(resp, &buf);
            ScanVertexResponse copy;
            std::size_t s = serializer::deserialize(buf, copy);
            ASSERT_EQ(s, buf.size());
            EXPECT_EQ(resp, copy);
        }
    }
}

}   // namespace nebula
