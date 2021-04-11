# Copyright (c) 2020 vesoft inc. All rights reserved.
#
# This source code is licensed under Apache 2.0 License,
# attached with Common Clause Condition 1.0, found in the LICENSES directory.

nebula_add_test(
    NAME
        scan_response_encode_decode_test
    SOURCES
        ResponseEncodeDecodeTest.cpp
    OBJECTS
        $<TARGET_OBJECTS:base_obj>
        $<TARGET_OBJECTS:storage_obj>
        $<TARGET_OBJECTS:storage_thrift_obj>
        $<TARGET_OBJECTS:common_thrift_obj>
        $<TARGET_OBJECTS:meta_thrift_obj>
        $<TARGET_OBJECTS:datatypes_obj>
    LIBRARIES
        gtest
        gtest_main
        ${THRIFT_LIBRARIES}
)
