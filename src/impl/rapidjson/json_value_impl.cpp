//
// Created by guozhenxiong on 2022-06-03.
//

#include "json_value_impl.h"
#include "json_message_codec_impl.h"

namespace wtf {

std::unique_ptr<JsonValue> JsonValue::Create(bool value, bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetBool(value);
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(int32_t num, bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetInt(num);
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(double num, bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetDouble(num);
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(const char *str, bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetString(str, strlen(str));
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::Create(const std::string &str, bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetString(str.c_str(), str.size());
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::CreateObject(bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetObject();
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

std::unique_ptr<JsonValue> JsonValue::CreateArray(bool isRoot)
{
    auto json = std::make_unique<rapidjson::Document>();
    json->SetArray();
    return std::make_unique<JsonValueImpl>(json.release(), isRoot);
}

JsonValueImpl::JsonValueImpl(rapidjson::Document *document)
    : document_(document), value_(document), isRoot_(false)
{}

JsonValueImpl::JsonValueImpl(rapidjson::Value *value)
    : document_(nullptr), value_(value), isRoot_(false)
{}

JsonValueImpl::JsonValueImpl(rapidjson::Document *document, bool isRoot)
    : document_(document), value_(document), isRoot_(isRoot)
{}

JsonValueImpl::JsonValueImpl(rapidjson::Document* document, rapidjson::Value* value)
    : document_(document), value_(value), isRoot_(false)
{}

JsonValueImpl::~JsonValueImpl()
{
    if (document_ != nullptr && isRoot_) {
        delete document_;
    }
    document_ = nullptr;
}

bool JsonValueImpl::IsVoid() const
{
    return false;
}

bool JsonValueImpl::IsNumber() const
{
    return value_->IsNumber();
}

bool JsonValueImpl::IsBool() const
{
    return value_->IsBool();
}

bool JsonValueImpl::IsString() const
{
    return value_->IsString();
}

bool JsonValueImpl::IsArray() const
{
    return value_->IsArray();
}

bool JsonValueImpl::IsObject() const
{
    return value_->IsObject();
}

bool JsonValueImpl::IsNull() const
{
    return (document_ == nullptr) || (value_->IsNull());
}

bool JsonValueImpl::IsValid() const
{
    return document_ != nullptr;
}

bool JsonValueImpl::GetBool() const
{
    return value_->GetBool();
}

int32_t JsonValueImpl::GetInt() const
{
    return value_->GetInt();
}

double JsonValueImpl::GetDouble() const
{
    return value_->GetDouble();
}

std::string JsonValueImpl::GetString() const
{
    return ((value_ == nullptr) || !value_->IsString()) ? "" : value_->GetString();
}

std::unique_ptr<JsonValue> JsonValueImpl::GetValue(const std::string &key) const
{
    rapidjson::Value::MemberIterator itr = value_->FindMember(key.c_str());
    return std::make_unique<JsonValueImpl>(document_, &itr->value);
}

size_t JsonValueImpl::GetArraySize() const
{
    return value_->GetArray().Size();
}

std::unique_ptr<JsonValue> JsonValueImpl::GetArrayItem(int32_t index) const
{
    auto itr = value_->GetArray().Begin() + index;
    return std::make_unique<JsonValueImpl>(document_, itr);
}

bool JsonValueImpl::Contains(const std::string &key) const
{
    return value_->HasMember(key.c_str());
}

int JsonValueImpl::Put(const char* key, bool value)
{
    value_->AddMember(rapidjson::Value(key, document_->GetAllocator()).Move(),
                      rapidjson::Value(value).Move(),
                      document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Put(const char* key, int32_t value)
{
    value_->AddMember(rapidjson::Value(key, document_->GetAllocator()).Move(),
                      rapidjson::Value(value).Move(),
                      document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Put(const char* key, double value)
{
    value_->AddMember(rapidjson::Value(key, document_->GetAllocator()).Move(),
                      rapidjson::Value(value).Move(),
                      document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Put(const char *key, const char *value)
{
    value_->AddMember(rapidjson::Value(key, document_->GetAllocator()).Move(),
                      rapidjson::Value(value, document_->GetAllocator()).Move(),
                      document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Put(const char* key, const std::unique_ptr<JsonValue>& value)
{
    rapidjson::Value* jsonValue = reinterpret_cast<rapidjson::Value*>(value->GetJsonData());
    value_->AddMember(rapidjson::Value(key, document_->GetAllocator()).Move(),
                      jsonValue->Move(),
                      document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Push(bool value)
{
    value_->PushBack(rapidjson::Value(value).Move(),
                     document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Push(int32_t value)
{
    value_->PushBack(rapidjson::Value(value).Move(),
                     document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Push(double value)
{
    value_->PushBack(rapidjson::Value(value).Move(),
                     document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Push(const char* value)
{
    value_->PushBack(rapidjson::Value(value, document_->GetAllocator()).Move(),
                     document_->GetAllocator());
    return 0;
}

int JsonValueImpl::Push(const std::unique_ptr<JsonValue>& value)
{
    rapidjson::Value* jsonValue = reinterpret_cast<rapidjson::Value*>(value->GetJsonData());
    value_->PushBack(jsonValue->Move(),
                     document_->GetAllocator());
    return 0;
}

Iterator JsonValueImpl::begin () const
{
    auto begin = value_->GetArray().begin();
    return Iterator(std::make_unique<JsonValueImpl>(begin));
}

Iterator JsonValueImpl::end () const
{
    auto end = value_->GetArray().end();
    return Iterator(std::make_unique<JsonValueImpl>(end));
}

std::string JsonValueImpl::ToString()
{
    return std::move(JsonMessageCodecImpl::GetInstance().EncodeMessage(*this));
}
} // namespace wtf