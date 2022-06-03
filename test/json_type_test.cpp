//
// Created by guozhenxiong on 2021-11-05.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

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