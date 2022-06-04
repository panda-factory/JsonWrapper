//
// Created by guozhenxiong on 2022-06-02.
//

#include "json_value_impl.h"
#include "json_message_codec_impl.h"

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

bool JsonValueImpl::IsValid() const
{
    return (object_ != nullptr) && !cJSON_IsInvalid(object_);
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

size_t JsonValueImpl::GetArraySize() const
{
    return cJSON_GetArraySize(object_);
}

std::unique_ptr<JsonValue> JsonValueImpl::GetArrayItem(int32_t index) const
{
    return std::make_unique<JsonValueImpl>(cJSON_GetArrayItem(object_, index));
}

bool JsonValueImpl::Contains(const std::string& key) const
{
    return cJSON_HasObjectItem(object_, key.c_str());
}

int JsonValueImpl::Put(const char* key, bool value)
{
    if (key == nullptr) {
        return -1;
    }

    cJSON* child = cJSON_CreateBool(value);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToObject(object_, key, child);
    return 0;
}

int JsonValueImpl::Put(const char* key, int32_t value)
{
    if (key == nullptr) {
        return -1;
    }

    cJSON* child = cJSON_CreateNumber(static_cast<double>(value));
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToObject(object_, key, child);
    return 0;
}

int JsonValueImpl::Put(const char* key, double value)
{
    if (key == nullptr) {
        return -1;
    }

    cJSON* child = cJSON_CreateNumber(value);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToObject(object_, key, child);
    return 0;
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

int JsonValueImpl::Put(const char* key, const std::unique_ptr<JsonValue>& value)
{
    if (!value || !key) {
        return -1;
    }
    cJSON* jsonObject = cJSON_Duplicate(reinterpret_cast<const cJSON*>(value->GetJsonData()), true);
    if (jsonObject == nullptr) {
        return -1;
    }

    cJSON_AddItemToObject(object_, key, jsonObject);
    return 0;
}

int JsonValueImpl::Push(bool value)
{
    cJSON* child = cJSON_CreateBool(value);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToArray(object_, child);
    return 0;
}

int JsonValueImpl::Push(int32_t value)
{
    return Push(static_cast<double>(value));
}

int JsonValueImpl::Push(double value)
{
    cJSON* child = cJSON_CreateNumber(value);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToArray(object_, child);
    return 0;
}

int JsonValueImpl::Push(const char* value)
{
    cJSON* child = cJSON_CreateString(value);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToArray(object_, child);
    return 0;
}

int JsonValueImpl::Push(const std::unique_ptr<JsonValue>& value)
{
    cJSON* child = cJSON_Duplicate(reinterpret_cast<cJSON*>(value->GetJsonData()), true);
    if (child == nullptr) {
        return -1;
    }
    cJSON_AddItemToArray(object_, child);
    return 0;
}

Iterator JsonValueImpl::begin () const
{
    return Iterator(std::make_unique<JsonValueImpl>(object_));
}

Iterator JsonValueImpl::end () const
{
    return Iterator(std::make_unique<JsonValueImpl>(nullptr));
}

std::string JsonValueImpl::ToString()
{
    return std::move(JsonMessageCodecImpl::GetInstance().EncodeMessage(*this));
}
} // namespace wtf