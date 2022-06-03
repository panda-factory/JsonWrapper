//
// Created by guozhenxiong on 2022-06-02.
//

#include "json_value_impl.h"

namespace wtf {

std::unique_ptr<JsonValue> JsonValue::Create(bool value, bool isRoot)
{
    if (value) {
        return std::make_unique<JsonValueImpl>(cJSON_CreateTrue(), isRoot);
    } else {
        return std::make_unique<JsonValueImpl>(cJSON_CreateFalse(), isRoot);
    }
}

std::unique_ptr<JsonValue> JsonValue::Create(int32_t num, bool isRoot)
{
    return JsonValue::Create(num, isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(double num, bool isRoot)
{
    return std::make_unique<JsonValueImpl>(cJSON_CreateNumber(num), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(const char* str, bool isRoot)
{
    return std::make_unique<JsonValueImpl>(cJSON_CreateString(str), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::CreateObject(bool isRoot)
{
    return std::make_unique<JsonValueImpl>(cJSON_CreateObject(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::CreateArray(bool isRoot)
{
    return std::make_unique<JsonValueImpl>(cJSON_CreateArray(), isRoot);
}

JsonValueImpl::JsonValueImpl(cJSON* object)
    : object_(object)
{}

JsonValueImpl::JsonValueImpl(cJSON* object, bool isRoot)
    : object_(object), isRoot_(isRoot)
{}

JsonValueImpl::~JsonValueImpl()
{
    if (object_ != nullptr && isRoot_) {
        cJSON_Delete(object_);
    }
    object_ = nullptr;
}

bool JsonValueImpl::IsVoid() const
{
    return false;
}

bool JsonValueImpl::IsNumber() const
{
    return cJSON_IsNumber(object_);
}

bool JsonValueImpl::IsBool() const
{
    return cJSON_IsBool(object_);
}

bool JsonValueImpl::IsString() const
{
    return cJSON_IsString(object_);
}

bool JsonValueImpl::IsArray() const
{
    return cJSON_IsArray(object_);
}

bool JsonValueImpl::IsObject() const
{
    return cJSON_IsObject(object_);
}

bool JsonValueImpl::IsNull() const
{
    return (object_ == nullptr) || cJSON_IsNull(object_);
}

bool JsonValueImpl::GetBool() const
{
    return cJSON_IsTrue(object_) != 0;
}

int32_t JsonValueImpl::GetInt() const
{
    return static_cast<int32_t>((object_ == nullptr) ? 0 : object_->valuedouble);
}

double JsonValueImpl::GetDouble() const
{
    return (object_ == nullptr) ? 0.0 : object_->valuedouble;
}

std::string JsonValueImpl::GetString() const
{
    return ((object_ == nullptr) || (object_->valuestring == nullptr)) ? "" : std::string(object_->valuestring);
}

std::unique_ptr<JsonValue> JsonValueImpl::GetValue(const std::string& key) const
{
    return std::make_unique<JsonValueImpl>(cJSON_GetObjectItem(object_, key.c_str()));
}

bool JsonValueImpl::Contains(const std::string& key) const
{
    return cJSON_HasObjectItem(object_, key.c_str());
}

int JsonValueImpl::Put(const char* key, const char* value)
{
    if (!value || !key) {
        return false;
    }

    cJSON* child = cJSON_CreateString(value);
    if (child == nullptr) {
        return false;
    }
    cJSON_AddItemToObject(object_, key, child);
    return true;
}
} // namespace wtf