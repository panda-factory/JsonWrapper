//
// Created by guozhenxiong on 2022-06-04.
//

#ifndef JSONWRAPPER_ITERATOR_H
#define JSONWRAPPER_ITERATOR_H

#include <memory>

namespace wtf {
class JsonValue;
class Iterator {
public:
    explicit Iterator(std::unique_ptr<JsonValue> addr);

    // !=
    bool operator!=(const Iterator &that) const;

    // *
    std::unique_ptr<JsonValue> operator*() const;

    // ->
    JsonValue* operator->() const;

    // ++
    const Iterator &operator++();

private:
    std::unique_ptr<JsonValue> addr_;
};
} // namespace wtf
#endif //JSONWRAPPER_ITERATOR_H
