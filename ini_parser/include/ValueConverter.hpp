#pragma once

#include <stdexcept>
#include <string>

#include "..\include\Exceptions.hpp"

template <typename T>
class ValueConverter {
   public:
    static T convert(const std::string& value);
}