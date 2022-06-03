//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_VALUE_H
#define JSONWRAPPER_JSON_VALUE_H

#include "value.h"

namespace wtf {
class JsonValue : public Value {
public:
    virtual ~JsonValue() = default;

    virtual bool IsArray() const = 0;

    virtual bool IsObject() const = 0;

    virtual bool IsNull() const = 0;

    virtual bool Contains(const std::string& key) const = 0;

    virtual std::unique_ptr<JsonValue> GetValue(const std::string& key) const = 0;

    virtual int Put(const char* key, const char* value) = 0;

    static std::unique_ptr<JsonValue> Create(bool value, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(int32_t number, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(double number, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(const char* str, bool isRoot = false);

    static std::unique_ptr<JsonValue> CreateObject(bool isRoot = false);

    static std::unique_ptr<JsonValue> CreateArray(bool isRoot = false);
};
} // namespace wtf
#endif //JSONWRAPPER_JSON_VALUE_H
