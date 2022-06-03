//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_MESSAGE_CODEC_H
#define JSONWRAPPER_MESSAGE_CODEC_H

#include <memory>
#include <string>
#include <vector>

namespace wtf {

template <typename T>
class MessageCodec {
public:
    MessageCodec() = default;

    virtual ~MessageCodec() = default;

    std::unique_ptr<T> DecodeMessage(const uint8_t* binary_message,
                                     const size_t message_size) const {
        return std::move(DecodeMessageInternal(binary_message, message_size));
    }

    std::unique_ptr<T> DecodeMessage(const std::vector<uint8_t>& binary_message) const {
        size_t size = binary_message.size();
        const uint8_t* data = size > 0 ? &binary_message[0] : nullptr;
        return std::move(DecodeMessageInternal(data, size));
    }

    std::unique_ptr<std::vector<uint8_t>> EncodeMessage(const T& message) const {
        return std::move(EncodeMessageInternal(message));
    }

protected:
    virtual std::unique_ptr<T> DecodeMessageInternal(const uint8_t* binary_message,
                                                     const size_t message_size) const = 0;

    virtual std::unique_ptr<std::vector<uint8_t>> EncodeMessageInternal(const T& message) const = 0;
};

} // namespace wtf

#endif //JSONWRAPPER_MESSAGE_CODEC_H
