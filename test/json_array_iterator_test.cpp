//
// Created by guozhenxiong on 2022-06-04.
//


#include "gtest/gtest.h"

#include "json_message_codec.h"

/**
 * @tc.name: JsonArrayPutTest001
 * @tc.desc: Check json wrapper function for array iterator
 */
TEST(JsonArrayIteraotrTest, JsonArrayIteraotrTest001)
{
    std::string testJson = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
    int32_t testArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    int i = 0;
    for (wtf::Iterator itr = jsonValue->begin(); itr != jsonValue->end(); ++itr) {
        EXPECT_TRUE(itr->GetInt() == testArray[i++]);
    }
}

/**
 * @tc.name: JsonArrayPutTest002
 * @tc.desc: Check json wrapper function for array range for
 */
TEST(JsonArrayIteraotrTest, JsonArrayIteraotrTest002)
{
    std::string testJson = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]";
    int32_t testArray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto jsonValue = wtf::JsonMessageCodec::GetInstance().DecodeMessage(testJson);
    int i = 0;
    for (auto itr : *jsonValue) {
        EXPECT_TRUE(itr->GetInt() == testArray[i++]);
    }
}