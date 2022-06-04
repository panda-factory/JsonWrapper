//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_VALUE_H
#define JSONWRAPPER_JSON_VALUE_H

#include "value.h"
#include "iterator.h"

namespace wtf {
class JsonValue : public Value {
public:
    virtual ~JsonValue() = default;

    virtual bool IsArray() const = 0;

    virtual bool IsObject() const = 0;

    virtual bool IsNull() const = 0;

    virtual bool IsValid() const = 0;

    virtual bool Contains(const std::string& key) const = 0;

    virtual std::unique_ptr<JsonValue> GetValue(const std::string& key) const = 0;

    virtual size_t GetArraySize() const = 0;

    virtual std::unique_ptr<JsonValue> GetArrayItem(int32_t index) const = 0;

    virtual int Put(const char* key, bool value) = 0;

    virtual int Put(const char* key, int32_t value) = 0;

    virtual int Put(const char* key, double value) = 0;

    virtual int Put(const char* key, const char* value) = 0;

    virtual int Put(const char* key, const std::unique_ptr<JsonValue>& value) = 0;

    virtual int Push(bool value) = 0;

    virtual int Push(int32_t value) = 0;

    virtual int Push(double value) = 0;

    virtual int Push(const char* value) = 0;

    virtual int Push(const std::unique_ptr<JsonValue>& value) = 0;

    // begin_expr and end_expr
    virtual Iterator begin () const = 0;

    virtual Iterator end () const = 0;

    virtual std::string ToString() = 0;

    virtual void* GetJsonData() const = 0;

    static std::unique_ptr<JsonValue> Create(bool value, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(int32_t number, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(double number, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(const char* str, bool isRoot = false);

    static std::unique_ptr<JsonValue> Create(const std::string& str, bool isRoot = false);

    static std::unique_ptr<JsonValue> CreateObject(bool isRoot = false);

    static std::unique_ptr<JsonValue> CreateArray(bool isRoot = false);
};
} // namespace wtf
#endif //JSONWRAPPER_JSON_VALUE_H
