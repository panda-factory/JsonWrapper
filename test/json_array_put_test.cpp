//
// Created by guozhenxiong on 2022-06-03.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

/**
 * @tc.name: JsonArrayRangeForTest001
 * @tc.desc: Check json wrapper function for bool type
 */
TEST(JsonArrayRangeForTest, JsonArrayRangeForTest001)
{
    bool testBool1 = true;
    bool testBool2 = false;
    int32_t testInt = -1;
    double testDouble = 8.88;
    const char* testStr = "JsonArrayPutTest001";
    std::string testJson = R"({"JsonValueTest": "JsonValueTest006"})";
    const char* verifyStr = R"([true,false,-1,8.88,"JsonArrayPutTest001",{"JsonValueTest":"JsonValueTest006"}])";
    auto testJsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);

    auto array = wtf::JsonValue::CreateArray(true);
    ASSERT_TRUE(array);
    array->Push(testBool1);
    array->Push(testBool2);
    array->Push(testInt);
    array->Push(testDouble);
    array->Push(testStr);
    array->Push(testJsonValue);
    EXPECT_EQ(array->ToString(), verifyStr);
}