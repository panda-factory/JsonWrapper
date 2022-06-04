//
// Created by guozhenxiong on 2022-06-03.
//

#include "json_message_codec_impl.h"

#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "json_value_impl.h"

namespace wtf {

const JsonMessageCodec& JsonMessageCodec::GetInstance()
{
    static const JsonMessageCodecImpl instance;
    return instance;
}

std::unique_ptr<JsonValue> JsonMessageCodecImpl::DecodeMessageInternal(const std::string& msg) const
{
    auto json = std::make_unique<rapidjson::Document>();
    rapidjson::ParseResult result = json->Parse(msg.c_str(), msg.size());
    if (result.IsError()) {
        std::cerr << "Unable to parse JSON message:" << std::endl
                  << rapidjson::GetParseError_En(result.Code()) << std::endl;
        json = nullptr;
    }
    return std::make_unique<JsonValueImpl>(json.release(), true);
}

std::string JsonMessageCodecImpl::EncodeMessageInternal(
        const JsonValue& msg) const
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    reinterpret_cast<rapidjson::Document*>(msg.GetJsonData())->Accept(writer);
    return buffer.GetString();
}
} // namespace wtf