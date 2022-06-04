//
// Created by guozhenxiong on 2022-06-04.
//

#include "iterator.h"
#include "json_value_impl.h"

namespace wtf {
Iterator::Iterator(std::unique_ptr<JsonValue> addr)
    : addr_(std::move(addr))
{}

bool Iterator::operator!=(const Iterator &that) const
{
    return (addr_->GetJsonData() != (*that)->GetJsonData());
}

// *
std::unique_ptr<JsonValue> Iterator::operator*() const
{
    return std::make_unique<JsonValueImpl>(reinterpret_cast<cJSON*>(addr_->GetJsonData()));
}

JsonValue* Iterator::operator->() const
{
    return addr_.get();
}

// ++
const Iterator& Iterator::operator++()
{
    cJSON* next = reinterpret_cast<cJSON*>(addr_->GetJsonData())->next;
    addr_ = std::make_unique<JsonValueImpl>(next);

    return *this;
}
} // namespace wtf