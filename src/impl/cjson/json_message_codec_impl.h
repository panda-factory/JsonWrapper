//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H
#define JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H

#include "json_message_codec.h"

#include "cJSON.h"

namespace wtf {
class JsonMessageCodecImpl : public JsonMessageCodec {
public:

protected:
    std::unique_ptr<JsonValue> DecodeMessageInternal(const uint8_t* binaryMessage,
                                                     const size_t messageSize) const override;

    std::unique_ptr<std::vector<uint8_t>> EncodeMessageInternal(
            const JsonValue& message) const override;
};
} // namespace wtf

#endif //JSONWRAPPER_JSON_MESSAGE_CODEC_IMPL_H
