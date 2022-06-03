//
// Created by guozhenxiong on 2022-06-03.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

/**
 * @tc.name: JsonObjectPutTest001
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest001)
{
    std::string key = "JsonObjectPutTest";
    std::string value = "JsonObjectPutTest001";

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    object->Put(key.c_str(), value.c_str());
    EXPECT_TRUE(object->Contains(key));
}