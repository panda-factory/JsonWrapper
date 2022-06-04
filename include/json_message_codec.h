//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_MESSAGE_CODEC_H
#define JSONWRAPPER_JSON_MESSAGE_CODEC_H

#include "json_value.h"
namespace wtf {
class JsonMessageCodec {
public:
    static const JsonMessageCodec& GetInstance();

    std::unique_ptr<JsonValue> DecodeMessage(const std::string& msg) const {
        return std::move(DecodeMessageInternal(msg));
    }

    std::string EncodeMessage(const JsonValue& message) const {
        return std::move(EncodeMessageInternal(message));
    }

protected:
    virtual std::unique_ptr<JsonValue> DecodeMessageInternal(const std::string& msg) const = 0;

    virtual std::string EncodeMessageInternal(const JsonValue& message) const = 0;
};
} // namespace wtf

#endif //JSONWRAPPER_JSON_MESSAGE_CODEC_H
