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

std::unique_ptr<JsonValue> JsonMessageCodecImpl::DecodeMessageInternal(const uint8_t* binaryMessage,
                                                                       const size_t messageSize) const
{
    return std::make_unique<JsonValueImpl>(cJSON_ParseWithOpts(reinterpret_cast<const char*>(binaryMessage), nullptr, true));
}


std::unique_ptr<std::vector<uint8_t>> JsonMessageCodecImpl::EncodeMessageInternal(
        const JsonValue& message) const
{
    return nullptr;
}
} // namespace wtf