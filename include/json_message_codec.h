//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_MESSAGE_CODEC_H
#define JSONWRAPPER_JSON_MESSAGE_CODEC_H

#include "message_codec.h"
#include "json_value.h"
namespace wtf {
class JsonMessageCodec : public MessageCodec<JsonValue> {
public:
    static const JsonMessageCodec& GetInstance();

    std::unique_ptr<JsonValue> DecodeMessage(const std::string& binary_message) const {
        size_t size = binary_message.size();
        const char* data = binary_message.c_str();
        return std::move(DecodeMessageInternal(reinterpret_cast<const uint8_t*>(data), size));
    }

//    std::string EncodeMessage(const JsonValue& message) const {
//        return std::move(EncodeMessageInternal(message));
//    }

};
} // namespace wtf

#endif //JSONWRAPPER_JSON_MESSAGE_CODEC_H
