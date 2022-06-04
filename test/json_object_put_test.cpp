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
    EXPECT_FALSE(object->Contains(key));
    EXPECT_FALSE(object->Contains(value));
    object->Put(key.c_str(), value.c_str());
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->GetString(), value);
}

/**
 * @tc.name: JsonObjectPutTest002
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest002)
{
    std::string key = "JsonObjectPutTest";
    bool value = true;

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    EXPECT_FALSE(object->Contains(key));
    object->Put(key.c_str(), value);
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->GetBool(), value);
}

/**
 * @tc.name: JsonObjectPutTest003
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest003)
{
    std::string key = "JsonObjectPutTest";
    int value = -1;

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    EXPECT_FALSE(object->Contains(key));
    object->Put(key.c_str(), value);
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->GetInt(), value);
}

/**
 * @tc.name: JsonObjectPutTest004
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest004)
{
    std::string key = "JsonObjectPutTest";
    double value = 8.88;

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    EXPECT_FALSE(object->Contains(key));
    object->Put(key.c_str(), value);
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->GetDouble(), value);
}

/**
 * @tc.name: JsonObjectPutTest005
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest005)
{
    std::string key = "JsonObjectPutTest";
    std::string testJson = R"({"JsonObjectPutTest":"JsonValueTest005"})";
    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    EXPECT_FALSE(object->Contains(key));
    object->Put(key.c_str(), jsonValue);
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->ToString(), testJson);
}

/**
 * @tc.name: JsonObjectPutTest006
 * @tc.desc: Check json wrapper function for object put
 */
TEST(JsonObjectPutTest, JsonObjectPutTest006)
{
    std::string key = "JsonObjectPutTest";
    std::string testJson = "[0,1,2,3,4,5,6,7,8,9]";
    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);

    auto object = wtf::JsonValue::CreateObject(true);
    ASSERT_TRUE(object);
    EXPECT_FALSE(object->Contains(key));
    object->Put(key.c_str(), jsonValue);
    EXPECT_TRUE(object->Contains(key));
    EXPECT_EQ(object->GetValue(key)->ToString(), testJson);
}