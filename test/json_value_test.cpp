//
// Created by guozhenxiong on 2022-06-02.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

TEST(JsonValueTest, JsonValueTest001)
{
    std::string testJson = "true";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsBool());
    EXPECT_TRUE(value->GetBool());
}

TEST(JsonValueTest, JsonValueTest002)
{
    std::string testJson = "false";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsBool());
    EXPECT_FALSE(value->GetBool());
}

TEST(JsonValueTest, JsonValueTest003)
{
    std::string testJson = "-1";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNumber());
    EXPECT_EQ(value->GetInt(), -1);
}

/**
 * @tc.name: JsonValueTest004
 * @tc.desc: Check json wrapper function for double value
 */
TEST(JsonValueTest, JsonValueTest004)
{
    std::string testJson = "888.888";
    double doubleValue = 888.888;

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsNumber());
    EXPECT_EQ(value->GetDouble(), doubleValue);
}

/**
 * @tc.name: JsonValueTest005
 * @tc.desc: Check json wrapper function for string value
 */
TEST(JsonValueTest, JsonValueTest005)
{
    std::string testJson = "\"string\"";
    std::string strValue = "string";

    auto value = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(value);
    EXPECT_TRUE(value->IsString());
    EXPECT_EQ(value->GetString(), strValue);
}

/**
 * @tc.name: JsonValueTest006
 * @tc.desc: Check json wrapper function for object value
 */
TEST(JsonValueTest, JsonValueTest006)
{
    std::string testJson = R"({"JsonValueTest": "JsonValueTest006"})";
    std::string key = "JsonValueTest";
    std::string value = "JsonValueTest006";

    auto object = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(object);
    EXPECT_TRUE(object->IsObject());
    EXPECT_TRUE(object->Contains(key));
    EXPECT_FALSE(object->Contains(value));
    //ASSERT_TRUE(object->GetValue(key));
    //EXPECT_EQ(object->GetValue(key)->GetString(), value);
    //EXPECT_EQ(value->GetString(), value);
}