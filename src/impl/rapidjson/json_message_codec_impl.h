//
// Created by guozhenxiong on 2022-06-03.
//

#ifndef JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H
#define JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H

#include "json_message_codec.h"

namespace wtf {
class JsonMessageCodecImpl : public JsonMessageCodec {
protected:
    std::unique_ptr<JsonValue> DecodeMessageInternal(const std::string& msg) const override;

    std::string EncodeMessageInternal(
            const JsonValue& msg) const override;
};
} // namespace wtf


#endif //JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H
