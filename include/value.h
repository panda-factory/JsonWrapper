//
// Created by guozhenxiong on 2022-06-02.
//

#ifndef JSONWRAPPER_VALUE_H
#define JSONWRAPPER_VALUE_H

#include <string>
#include <memory>

namespace wtf {
class Value {
public:
    virtual ~Value() = default;

    virtual bool IsVoid() const = 0;

    virtual bool IsNumber() const = 0;

    virtual bool IsBool() const = 0;

    virtual bool IsString() const = 0;

    virtual bool GetBool() const = 0;

    virtual int32_t GetInt() const = 0;

    virtual double GetDouble() const = 0;

    virtual std::string GetString() const = 0;

};
} // wtf

#endif //JSONWRAPPER_VALUE_H
