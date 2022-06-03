//
// Created by guozhenxiong on 2021-11-05.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

/**
 * @tc.name: JsonTypeTest001
 * @tc.desc: Check json wrapper function for bool type
 */
TEST(JsonTypeTest, JsonTypeTest001)
{
    std::string testJson = "true";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest002
 * @tc.desc: Check json wrapper function for number type
 */
TEST(JsonTypeTest, JsonTypeTest002)
{
    std::string testJson = "123";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNumber());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest003
 * @tc.desc: Check json wrapper function for string type
 */
TEST(JsonTypeTest, JsonTypeTest003)
{
    std::string testJson = "\"string\"";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsString());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest004
 * @tc.desc: Check json wrapper function for object type
 */
TEST(JsonTypeTest, JsonTypeTest004)
{
    std::string testJson = "{}";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest005
 * @tc.desc: Check json wrapper function for array type
 */
TEST(JsonTypeTest, JsonTypeTest005)
{
    std::string testJson = "[]";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsArray());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest006
 * @tc.desc: Check json wrapper function for null type
 */
TEST(JsonTypeTest, JsonTypeTest006)
{
    std::string testJson = "null";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNull());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
}

/**
 * @tc.name: JsonValueTest007
 * @tc.desc: Check json wrapper function for illegal value
 */
TEST(JsonTypeTest, JsonTypeTest007)
{
    std::string testJson = "{illegal}";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNull());
}

/**
 * @tc.name: JsonValueTest008
 * @tc.desc: Check json wrapper function for illegal value
 */
TEST(JsonTypeTest, JsonTypeTest008)
{
    auto value = wtf::JsonValue::Create(true, true);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest009
 * @tc.desc: Check json wrapper function for number type
 */
TEST(JsonTypeTest, JsonTypeTest009)
{
//    auto value = wtf::JsonValue::Create(123, true);
//    ASSERT_TRUE(value);
//    EXPECT_TRUE(value->IsNumber());
//    EXPECT_FALSE(value->IsBool());
//    EXPECT_FALSE(value->IsObject());
//    EXPECT_FALSE(value->IsArray());
//    EXPECT_FALSE(value->IsString());
//    EXPECT_FALSE(value->IsVoid());
//    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest010
 * @tc.desc: Check json wrapper function for number type
 */
TEST(JsonTypeTest, JsonTypeTest010)
{
    auto value = wtf::JsonValue::Create(88.8, true);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNumber());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest011
 * @tc.desc: Check json wrapper function for string type
 */
TEST(JsonTypeTest, JsonTypeTest011)
{
    auto value = wtf::JsonValue::Create("string", true);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsString());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest012
 * @tc.desc: Check json wrapper function for object type
 */
TEST(JsonTypeTest, JsonTypeTest012)
{
    auto value = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsObject());
    EXPECT_FALSE(value->IsArray());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}

/**
 * @tc.name: JsonTypeTest013
 * @tc.desc: Check json wrapper function for array type
 */
TEST(JsonTypeTest, JsonTypeTest013)
{
    auto value = wtf::JsonValue::CreateArray();
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsArray());
    EXPECT_FALSE(value->IsObject());
    EXPECT_FALSE(value->IsBool());
    EXPECT_FALSE(value->IsNumber());
    EXPECT_FALSE(value->IsString());
    EXPECT_FALSE(value->IsVoid());
    EXPECT_FALSE(value->IsNull());
}