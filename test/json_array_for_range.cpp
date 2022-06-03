//
// Created by guozhenxiong on 2022-06-03.
//

#include "gtest/gtest.h"

#include "json_message_codec.h"

/**
 * @tc.name: JsonArrayForRangeTest001
 * @tc.desc: Check json wrapper function for bool type
 */
TEST(JsonArrayForRangeTest, JsonArrayForRangeTest001)
{
    std::string testJson = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
    size_t size = 10;
    int32_t testArrayIndex = 5;
    int32_t testArrayValue = 5;

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    ASSERT_TRUE(jsonValue);
    EXPECT_TRUE(jsonValue->IsArray());

}