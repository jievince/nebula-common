/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_STORAGE_RESPONSECOMMONOPS_H_
#define COMMON_STORAGE_RESPONSECOMMONOPS_H_

#include "common/base/Base.h"

#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/gen/module_types_tcc.h>
#include <thrift/lib/cpp2/protocol/ProtocolReaderStructReadState.h>

#include "common/storage/Response.h"
#include "common/storage/StorageCpp2Ops.h"

namespace apache {
namespace thrift {

/**************************************
 *
 * Ops for class ResponseCommon
 *
 *************************************/
namespace detail {

template <>
struct TccStructTraits<::nebula::ResponseCommon> {
    static void translateFieldName(MAYBE_UNUSED folly::StringPiece _fname,
                                   MAYBE_UNUSED int16_t& fid,
                                   MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
        if (false) {
        } else if (_fname == "code") {
            fid = 1;
            _ftype = apache::thrift::protocol::T_I32;
        } else if (_fname == "part_id") {
            fid = 2;
            _ftype = apache::thrift::protocol::T_I32;
        } else if (_fname == "leader") {
            fid = 3;
            _ftype = apache::thrift::protocol::T_STRUCT;
        }
    }
};

}   // namespace detail

inline constexpr apache::thrift::protocol::TType Cpp2Ops<::nebula::ResponseCommon>::thriftType() {
    return apache::thrift::protocol::T_STRUCT;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::ResponseCommon>::write(Protocol* proto,
                                                  ::nebula::ResponseCommon const* obj) {
    uint32_t xfer = 0;
    xfer += proto->writeStructBegin("ResponseCommon");
    xfer += proto->writeFieldBegin("failed_parts", apache::thrift::protocol::T_LIST, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>,
        std::vector<nebula::PartitionResult>>::write(*proto, obj->failedParts);
    xfer += proto->writeFieldEnd();
    xfer += proto->writeFieldBegin("latency_in_us", apache::thrift::protocol::T_I32, 2);
    xfer +=
        ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral,
                                                       int32_t>::write(*proto, obj->latencyInUs);
    xfer += proto->writeFieldEnd();
    xfer += proto->writeFieldStop();
    xfer += proto->writeStructEnd();
    return xfer;
}

template <class Protocol>
void Cpp2Ops<::nebula::ResponseCommon>::read(Protocol* proto, ::nebula::ResponseCommon* obj) {
    apache::thrift::detail::ProtocolReaderStructReadState<Protocol> _readState;

    _readState.readStructBegin(proto);

    using apache::thrift::TProtocolException;

    bool isset_failed_parts = false;
    bool isset_latency_in_us = false;

    if (UNLIKELY(!_readState.advanceToNextField(proto, 0, 1, apache::thrift::protocol::T_LIST))) {
        goto _loop;
    }
_readField_failed_parts : {
    obj->failedParts = std::vector<nebula::PartitionResult>();
    ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>,
        std::vector<nebula::PartitionResult>>::read(*proto, obj->failedParts);
    isset_failed_parts = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 1, 2, apache::thrift::protocol::T_I32))) {
        goto _loop;
    }
_readField_latency_in_us : {
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral,
                                                   int32_t>::read(*proto, obj->latencyInUs);
    isset_latency_in_us = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 2, 0, apache::thrift::protocol::T_STOP))) {
        goto _loop;
    }

_end:
    _readState.readStructEnd(proto);

    if (!isset_failed_parts) {
        TProtocolException::throwMissingRequiredField("failed_parts", "ResponseCommon");
    }
    if (!isset_latency_in_us) {
        TProtocolException::throwMissingRequiredField("latency_in_us", "ResponseCommon");
    }
    return;

_loop:
    if (_readState.fieldType == apache::thrift::protocol::T_STOP) {
        goto _end;
    }
    if (proto->kUsesFieldNames()) {
        apache::thrift::detail::TccStructTraits<nebula::ResponseCommon>::translateFieldName(
            _readState.fieldName(), _readState.fieldId, _readState.fieldType);
    }

    switch (_readState.fieldId) {
        case 1: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_LIST)) {
                goto _readField_failed_parts;
            } else {
                goto _skip;
            }
        }
        case 2: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I32)) {
                goto _readField_latency_in_us;
            } else {
                goto _skip;
            }
        }
        default: {
        _skip:
            proto->skip(_readState.fieldType);
            _readState.readFieldEnd(proto);
            _readState.readFieldBeginNoInline(proto);
            goto _loop;
        }
    }
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::ResponseCommon>::serializedSize(Protocol const* proto,
                                                           ::nebula::ResponseCommon const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("ResponseCommon");
    xfer += proto->serializedFieldSize("failed_parts", apache::thrift::protocol::T_LIST, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>,
        std::vector<nebula::PartitionResult>>::
        serializedSize<false>(*proto, obj->failedParts);
    xfer += proto->serializedFieldSize("latency_in_us", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::
        protocol_methods<::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(
            *proto, obj->latencyInUs);
    xfer += proto->serializedSizeStop();
    return xfer;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::ResponseCommon>::serializedSizeZC(Protocol const* proto,
                                                             ::nebula::ResponseCommon const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("ResponseCommon");
    xfer += proto->serializedFieldSize("failed_parts", apache::thrift::protocol::T_LIST, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>,
        std::vector<nebula::PartitionResult>>::
        serializedSize<false>(*proto, obj->failedParts);
    xfer += proto->serializedFieldSize("latency_in_us", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::
        protocol_methods<::apache::thrift::type_class::integral, int32_t>::serializedSize<false>(
            *proto, obj->latencyInUs);
    xfer += proto->serializedSizeStop();
    return xfer;
}

}   // namespace thrift
}   // namespace apache
#endif   // COMMON_STORAGE_RESPONSECOMMONOPS_H_
