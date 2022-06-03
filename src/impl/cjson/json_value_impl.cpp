//
// Created by guozhenxiong on 2022-06-02.
//

#include "json_value_impl.h"
#include "json_object_impl.h"

namespace wtf {
JsonValueImpl::JsonValueImpl(cJSON* object)
    : object_(object)
{}

JsonValueImpl::~JsonValueImpl()
{
    if (object_ != nullptr) {
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

bool JsonValueImpl::Contains(const std::string& key) const
{
    return cJSON_HasObjectItem(object_, key.c_str());
}

std::unique_ptr<JsonValue> JsonValueImpl::GetValue(const std::string& key) const
{
    return std::make_unique<JsonValueImpl>(cJSON_GetObjectItem(object_, key.c_str()));
}
std::unique_ptr<JsonObject> JsonValueImpl::GetObject() const
{
    if (IsObject()) {
        return std::make_unique<JsonObjectImpl>(object_);
    }
    return std::make_unique<JsonObjectImpl>();
}
} // namespace wtf