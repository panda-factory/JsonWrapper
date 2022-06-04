//
// Created by guozhenxiong on 2022-06-02.
//

#include "json_message_codec_impl.h"

#include "json_value_impl.h"

namespace wtf {

const JsonMessageCodec& JsonMessageCodec::GetInstance()
{
    static const JsonMessageCodecImpl instance;
    return instance;
}

std::unique_ptr<JsonValue> JsonMessageCodecImpl::DecodeMessageInternal(const std::string& msg) const
{
    return std::make_unique<JsonValueImpl>(cJSON_ParseWithOpts(msg.c_str(),
                                                               nullptr,
                                                               true),
                                           true);
}


std::string JsonMessageCodecImpl::EncodeMessageInternal(
        const JsonValue& msg) const
{
    std::string result;
    cJSON* json = reinterpret_cast<cJSON*>(msg.GetJsonData());
    if (!json) {
        return result;
    }

    char* unformatted = cJSON_PrintUnformatted(json);
    if (unformatted != nullptr) {
        result = unformatted;
        cJSON_free(unformatted);
    }
    return result;
}
} // namespace wtf