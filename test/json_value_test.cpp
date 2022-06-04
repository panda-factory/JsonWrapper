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

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(jsonValue);
    EXPECT_TRUE(jsonValue->IsObject());
    EXPECT_TRUE(jsonValue->Contains(key));
    EXPECT_FALSE(jsonValue->Contains(value));
    ASSERT_TRUE(jsonValue->GetValue(key));
    ASSERT_TRUE(jsonValue->GetValue(key)->IsString());
    EXPECT_EQ(jsonValue->GetValue(key)->GetString(), value);
}

/**
 * @tc.name: JsonValueTest007
 * @tc.desc: Check json wrapper function for array value
 */
TEST(JsonValueTest, JsonValueTest007)
{
    std::string testJson = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
    size_t size = 10;
    int32_t testArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(jsonValue);
    EXPECT_TRUE(jsonValue->IsArray());
    EXPECT_TRUE(jsonValue->GetArraySize() == size);
    for(int i = 0; i < jsonValue->GetArraySize(); i++) {
        EXPECT_TRUE(jsonValue->GetArrayItem(i)->GetInt() == testArray[i]);
    }
}

/**
 * @tc.name: JsonValueTest008
 * @tc.desc: Check json wrapper function for array value
 */
TEST(JsonValueTest, JsonValueTest008)
{
    std::string testJson = "[]";

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(jsonValue);
    EXPECT_TRUE(jsonValue->IsArray());
    EXPECT_TRUE(jsonValue->GetArraySize() == 0);
}

/**
 * @tc.name: JsonValueTest009
 * @tc.desc: Check json wrapper function for array value
 */
TEST(JsonValueTest, JsonValueTest009)
{
    std::string testJson = R"([null, true, false, -1, 8.88, {"JsonValueTest": "JsonValueTest009"}])";

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(jsonValue);
    EXPECT_TRUE(jsonValue->IsArray());
    EXPECT_TRUE(jsonValue->GetArrayItem(0)->IsNull());
    EXPECT_TRUE(jsonValue->GetArrayItem(1)->GetBool() == true);
    EXPECT_TRUE(jsonValue->GetArrayItem(2)->GetBool() == false);
    EXPECT_TRUE(jsonValue->GetArrayItem(3)->GetInt() == -1);
    EXPECT_TRUE(jsonValue->GetArrayItem(4)->GetDouble() == 8.88);
    EXPECT_TRUE(jsonValue->GetArrayItem(5)->GetValue("JsonValueTest")->GetString() == "JsonValueTest009");
}