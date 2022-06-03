//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_JSON_OBJECT_IMPL_H
#define JSONWRAPPER_JSON_OBJECT_IMPL_H

#include "cJSON.h"

#include "json_object.h"

namespace wtf {
class JsonObjectImpl : public JsonObject{
public:
    JsonObjectImpl() = default;

    explicit JsonObjectImpl(cJSON* object);

    ~JsonObjectImpl() = default;

private:
    cJSON* object_ = nullptr;
};
} // namespace wtf

#endif //JSONWRAPPER_JSON_OBJECT_IMPL_H
