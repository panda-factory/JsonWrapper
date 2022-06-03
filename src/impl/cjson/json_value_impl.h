//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_VALUE_IMPL_H
#define JSONWRAPPER_JSON_VALUE_IMPL_H

#include "cJSON.h"

#include "json_value.h"
#include "json_object.h"

namespace wtf {
class JsonValueImpl : public JsonValue {
public:
    JsonValueImpl() = default;

    explicit JsonValueImpl(cJSON* object);

    ~JsonValueImpl();

    bool IsVoid() const override;

    bool IsNumber() const override;

    bool IsBool() const override;

    bool IsString() const override;

    bool IsArray() const override;

    bool IsObject() const override;

    bool IsNull() const override;

    bool GetBool() const override;

    int32_t GetInt() const override;

    double GetDouble() const override;

    std::string GetString() const override;

    bool Contains(const std::string& key) const override;

    std::unique_ptr<JsonValue> GetValue(const std::string& key) const override;

    std::unique_ptr<JsonObject> GetObject() const override;

    //JsonValue& operator [](const std::string key) const override;

private:
    cJSON* object_ = nullptr;
};
} // namespace wtf

#endif //JSONWRAPPER_JSON_VALUE_IMPL_H
