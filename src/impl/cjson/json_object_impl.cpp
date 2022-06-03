//
// Created by guozhenxiong on 2022-06-02.
//

#include "json_object_impl.h"

namespace wtf {

JsonObjectImpl::JsonObjectImpl(cJSON* object)
    : object_(object)
{
}

} // namespace wtf