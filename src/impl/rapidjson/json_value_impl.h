//
// Created by guozhenxiong on 2022-06-03.
//

#ifndef JSONWRAPPER_JSON_VALUE_IMPL_H
#define JSONWRAPPER_JSON_VALUE_IMPL_H

#include <rapidjson/document.h>

#include "json_value.h"

namespace wtf {
class JsonValueImpl : public JsonValue {
public:
    JsonValueImpl() = default;

    explicit JsonValueImpl(rapidjson::Document* document);

    explicit JsonValueImpl(rapidjson::Value* value);

    JsonValueImpl(rapidjson::Document* document, bool isRoot);

    JsonValueImpl(rapidjson::Document* document, rapidjson::Value* value);

    ~JsonValueImpl();

    bool IsVoid() const override;

    bool IsNumber() const override;

    bool IsBool() const override;

    bool IsString() const override;

    bool IsArray() const override;

    bool IsObject() const override;

    bool IsNull() const override;

    bool IsValid() const override;

    bool GetBool() const override;

    int32_t GetInt() const override;

    double GetDouble() const override;

    std::string GetString() const override;

    std::unique_ptr<JsonValue> GetValue(const std::string& key) const override;

    size_t GetArraySize() const override;

    std::unique_ptr<JsonValue> GetArrayItem(int32_t index) const override;

    bool Contains(const std::string& key) const override;

    int Put(const char* key, bool value) override;

    int Put(const char* key, int32_t value) override;

    int Put(const char* key, double value) override;

    int Put(const char* key, const char* value) override;

    int Put(const char* key, const std::unique_ptr<JsonValue>& value) override;

    int Push(bool value) override;

    int Push(int32_t value) override;

    int Push(double value) override;

    int Push(const char* value) override;

    int Push(const std::unique_ptr<JsonValue>& value) override;

    Iterator begin () const override;

    Iterator end () const override;

    std::string ToString() override;

    void* GetJsonData() const {return value_;}

private:
    rapidjson::Document* document_ = nullptr;

    rapidjson::Value* value_ = nullptr;

    rapidjson::Value::ValueIterator itr_ = nullptr;

    bool isRoot_ = false;
};
} // namespace wtf

#endif //JSONWRAPPER_JSON_VALUE_IMPL_H
