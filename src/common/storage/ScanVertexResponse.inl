/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef COMMON_STORAGE_SCANVERTEXRESPONSEOPS_H_
#define COMMON_STORAGE_SCANVERTEXRESPONSEOPS_H_

#include "common/base/Base.h"

#include <thrift/lib/cpp2/GeneratedCodeHelper.h>
#include <thrift/lib/cpp2/gen/module_types_tcc.h>
#include <thrift/lib/cpp2/protocol/ProtocolReaderStructReadState.h>
#include <memory>

#include "common/storage/Response.h"
#include "common/storage/StorageCpp2Ops.h"

namespace apache {
namespace thrift {

/**************************************
 *
 * Ops for class ScanVertexResponse
 *
 *************************************/
namespace detail {

template <>
struct TccStructTraits<nebula::ScanVertexResponse> {
    static void translateFieldName(MAYBE_UNUSED folly::StringPiece _fname,
                                   MAYBE_UNUSED int16_t& fid,
                                   MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
        if (false) {
        } else if (_fname == "result") {
            fid = 1;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "vertex_data") {
            fid = 2;
            _ftype = apache::thrift::protocol::T_STRUCT;
        } else if (_fname == "has_next") {
            fid = 3;
            _ftype = apache::thrift::protocol::T_BOOL;
        } else if (_fname == "next_cursor") {
            fid = 4;
            _ftype = apache::thrift::protocol::T_STRING;
        }
    }
};

}   // namespace detail

inline constexpr apache::thrift::protocol::TType
Cpp2Ops<::nebula::ScanVertexResponse>::thriftType() {
    return apache::thrift::protocol::T_STRUCT;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::ScanVertexResponse>::write(Protocol* proto,
                                                      ::nebula::ScanVertexResponse const* obj) {
    uint32_t xfer = 0;
    xfer += proto->writeStructBegin("nebula::ScanVertexResponse");
    xfer += proto->writeFieldBegin("result", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::Cpp2Ops<nebula::ResponseCommon>::write(proto,
                                                                                      &obj->result);
    xfer += proto->writeFieldEnd();
    xfer += proto->writeFieldBegin("vertex_data", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::Cpp2Ops<nebula::DataSet>::write(proto, &obj->vertexData);
    xfer += proto->writeFieldEnd();
    xfer += proto->writeFieldBegin("has_next", apache::thrift::protocol::T_BOOL, 3);
    xfer += proto->writeBool(obj->hasNext);
    xfer += proto->writeFieldEnd();
    if (obj->nextCursor != nullptr) {
        xfer += proto->writeFieldBegin("next_cursor", apache::thrift::protocol::T_STRING, 4);
        xfer += proto->writeBinary(*obj->nextCursor);
        xfer += proto->writeFieldEnd();
    }
    xfer += proto->writeFieldStop();
    xfer += proto->writeStructEnd();
    return xfer;
}

template <class Protocol>
void Cpp2Ops<::nebula::ScanVertexResponse>::read(Protocol* proto,
                                                 ::nebula::ScanVertexResponse* obj) {
    apache::thrift::detail::ProtocolReaderStructReadState<Protocol> _readState;

    _readState.readStructBegin(proto);

    using apache::thrift::TProtocolException;

    bool isset_result = false;

    if (UNLIKELY(!_readState.advanceToNextField(proto, 0, 1, apache::thrift::protocol::T_STRUCT))) {
        goto _loop;
    }
_readField_result : {
    ::apache::thrift::Cpp2Ops<nebula::ResponseCommon>::read(proto, &obj->result);
    isset_result = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 1, 2, apache::thrift::protocol::T_STRUCT))) {
        goto _loop;
    }
_readField_vertex_data : {
    ::apache::thrift::Cpp2Ops<nebula::DataSet>::read(proto, &obj->vertexData);
    // this->__isset.vertex_data = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 2, 3, apache::thrift::protocol::T_BOOL))) {
        goto _loop;
    }
_readField_has_next : {
    proto->readBool(obj->hasNext);
    // this->__isset.has_next = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 3, 4, apache::thrift::protocol::T_STRING))) {
        goto _loop;
    }
_readField_next_cursor : {
    proto->readBinary(*obj->nextCursor);
    // this->__isset.next_cursor = true;
}

    if (UNLIKELY(!_readState.advanceToNextField(proto, 4, 0, apache::thrift::protocol::T_STOP))) {
        goto _loop;
    }

_end:
    _readState.readStructEnd(proto);

    if (!isset_result) {
        TProtocolException::throwMissingRequiredField("result", "ScanVertexResponse");
    }
    return;

_loop:
    if (_readState.fieldType == apache::thrift::protocol::T_STOP) {
        goto _end;
    }
    if (proto->kUsesFieldNames()) {
        apache::thrift::detail::TccStructTraits<nebula::ScanVertexResponse>::translateFieldName(
            _readState.fieldName(), _readState.fieldId, _readState.fieldType);
    }

    switch (_readState.fieldId) {
        case 1: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_STRUCT)) {
                goto _readField_result;
            } else {
                goto _skip;
            }
        }
        case 2: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_STRUCT)) {
                goto _readField_vertex_data;
            } else {
                goto _skip;
            }
        }
        case 3: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_BOOL)) {
                goto _readField_has_next;
            } else {
                goto _skip;
            }
        }
        case 4: {
            if (LIKELY(_readState.fieldType == apache::thrift::protocol::T_STRING)) {
                goto _readField_next_cursor;
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
uint32_t Cpp2Ops<::nebula::ScanVertexResponse>::serializedSize(Protocol const* proto,
                                            ::nebula::ScanVertexResponse const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("nebula::ScanVertexResponse");
    xfer += proto->serializedFieldSize("result", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::Cpp2Ops<nebula::ResponseCommon>::serializedSize(
        proto, &obj->result);
    xfer += proto->serializedFieldSize("vertex_data", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::Cpp2Ops<nebula::DataSet>::serializedSize(proto, &obj->vertexData);
    xfer += proto->serializedFieldSize("has_next", apache::thrift::protocol::T_BOOL, 3);
    xfer += proto->serializedSizeBool(obj->hasNext);
    if (obj->nextCursor != nullptr) {
        xfer += proto->serializedFieldSize("next_cursor", apache::thrift::protocol::T_STRING, 4);
        xfer += proto->serializedSizeBinary(obj->nextCursor);
    }
    xfer += proto->serializedSizeStop();
    return xfer;
}

template <class Protocol>
uint32_t Cpp2Ops<::nebula::ScanVertexResponse>::serializedSizeZC(Protocol const* proto,
                                              ::nebula::ScanVertexResponse const* obj) {
    uint32_t xfer = 0;
    xfer += proto->serializedStructSize("ScanVertexResponse");
    xfer += proto->serializedFieldSize("result", apache::thrift::protocol::T_STRUCT, 1);
    xfer += ::apache::thrift::Cpp2Ops<nebula::ResponseCommon>::serializedSizeZC(
        proto, &obj->result);
    xfer += proto->serializedFieldSize("vertex_data", apache::thrift::protocol::T_STRUCT, 2);
    xfer += ::apache::thrift::Cpp2Ops<nebula::DataSet>::serializedSizeZC(proto, &obj->vertexData);
    xfer += proto->serializedFieldSize("has_next", apache::thrift::protocol::T_BOOL, 3);
    xfer += proto->serializedSizeBool(obj->hasNext);
    if (obj->nextCursor != nullptr) {
        xfer += proto->serializedFieldSize("next_cursor", apache::thrift::protocol::T_STRING, 4);
        xfer += proto->serializedSizeZCBinary(*obj->nextCursor);
    }
    xfer += proto->serializedSizeStop();
    return xfer;
}

}   // namespace thrift
}   // namespace apache
#endif   // COMMON_STORAGE_SCANVERTEXRESPONSEOPS_H_
