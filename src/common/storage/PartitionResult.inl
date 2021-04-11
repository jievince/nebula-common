/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_STORAGE_PARTITIONRESULTOPS_H_
#define COMMON_STORAGE_PARTITIONRESULTOPS_H_

#include <memory>

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
 * Ops for class PartitionResult
 *
 *************************************/
namespace detail {

template <>
struct TccStructTraits<nebula::PartitionResult> {
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

inline constexpr apache::thrift::protocol::TType Cpp2Ops<::nebula::PartitionResult>::thriftType() {
    return apache::thrift::protocol::T_STRUCT;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::PartitionResult>::write(Protocol* proto,
                                                   ::nebula::PartitionResult const* obj) {
    uint32_t xfer = 0;
    xfer += proto->writeStructBegin("PartitionResult");
    xfer += proto->writeFieldBegin("code", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::enumeration,
        ::nebula::ErrorCode>::write(*proto, obj->code);
    xfer += proto->writeFieldEnd();
    xfer += proto->writeFieldBegin("part_id", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::integral,
        ::nebula::cpp2::PartitionID>::write(*proto, obj->partId);
    xfer += proto->writeFieldEnd();
    if (obj->leader != nullptr) {
        xfer += proto->writeFieldBegin("leader", apache::thrift::protocol::T_STRUCT, 3);
        xfer += ::apache::thrift::Cpp2Ops<nebula::HostAddr>::write(proto, obj->leader.get());
        xfer += proto->writeFieldEnd();
    }
    xfer += proto->writeFieldStop();
    xfer += proto->writeStructEnd();
    return xfer;
}

template <class Protocol>
void Cpp2Ops<::nebula::PartitionResult>::read(Protocol* proto, ::nebula::PartitionResult* obj) {
    apache::thrift::detail::ProtocolReaderStructReadState<Protocol> _readState;

    _readState.readStructBegin(proto);

    using apache::thrift::TProtocolException;

    bool isset_code = false;
    bool isset_part_id = false;

    if (UNLIKELY(!_readState.advanceToNextField(proto, 0, 1, apache::thrift::protocol::T_I32))) {
        goto _loop;
    }
_readField_code : {
    ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::enumeration,
        ::nebula::ErrorCode>::read(*proto, obj->code);
    isset_code = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 1, 2, apache::thrift::protocol::T_I32))) {
        goto _loop;
    }
_readField_part_id : {
    ::apache::thrift::detail::pm::protocol_methods<::apache::thrift::type_class::integral,
                                                   ::nebula::cpp2::PartitionID>::read(*proto,
                                                                                      obj->partId);
    isset_part_id = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 2, 3, apache::thrift::protocol::T_STRUCT))) {
        goto _loop;
    }
_readField_leader : {
    ::apache::thrift::Cpp2Ops<nebula::HostAddr>::read(proto, obj->leader.get());
    // this->__isset.leader = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 3, 0, apache::thrift::protocol::T_STOP))) {
        goto _loop;
    }

_end:
    _readState.readStructEnd(proto);

    if (!isset_code) {
        TProtocolException::throwMissingRequiredField("code", "PartitionResult");
    }
    if (!isset_part_id) {
        TProtocolException::throwMissingRequiredField("part_id", "PartitionResult");
    }
    return;

_loop:
    if (_readState.fieldType == apache::thrift::protocol::T_STOP) {
        goto _end;
    }
    if (proto->kUsesFieldNames()) {
        apache::thrift::detail::TccStructTraits<nebula::PartitionResult>::translateFieldName(
            _readState.fieldName(), _readState.fieldId, _readState.fieldType);
    }

    switch (_readState.fieldId) {
        case 1: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I32)) {
                goto _readField_code;
            } else {
                goto _skip;
            }
        }
        case 2: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_I32)) {
                goto _readField_part_id;
            } else {
                goto _skip;
            }
        }
        case 3: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_STRUCT)) {
                goto _readField_leader;
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
uint32_t Cpp2Ops<::nebula::PartitionResult>::serializedSize(Protocol const* proto,
                                                            ::nebula::PartitionResult const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("PartitionResult");
    xfer += proto->serializedFieldSize("code", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::enumeration,
        ::nebula::ErrorCode>::serializedSize<false>(*proto, obj->code);
    xfer += proto->serializedFieldSize("part_id", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::integral,
        ::nebula::cpp2::PartitionID>::serializedSize<false>(*proto, obj->partId);
    if (obj->leader != nullptr) {
        xfer += proto->serializedFieldSize("leader", apache::thrift::protocol::T_STRUCT, 3);
        xfer +=
            ::apache::thrift::Cpp2Ops<nebula::HostAddr>::serializedSize(proto, obj->leader.get());
    }
    xfer += proto->serializedSizeStop();
    return xfer;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::PartitionResult>::serializedSizeZC(
    Protocol const* proto,
    ::nebula::PartitionResult const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("PartitionResult");
    xfer += proto->serializedFieldSize("code", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::enumeration,
        ::nebula::ErrorCode>::serializedSize<false>(*proto, obj->code);
    xfer += proto->serializedFieldSize("part_id", apache::thrift::protocol::T_I32, 2);
    xfer += ::apache::thrift::detail::pm::protocol_methods<
        ::apache::thrift::type_class::integral,
        ::nebula::cpp2::PartitionID>::serializedSize<false>(*proto, obj->partId);
    if (obj->leader != nullptr) {
        xfer += proto->serializedFieldSize("leader", apache::thrift::protocol::T_STRUCT, 3);
        xfer +=
            ::apache::thrift::Cpp2Ops<nebula::HostAddr>::serializedSizeZC(proto, obj->leader.get());
    }
    xfer += proto->serializedSizeStop();
    return xfer;
}

}   // namespace thrift
}   // namespace apache
#endif   // COMMON_STORAGE_PARTITIONRESULTOPS_H_
