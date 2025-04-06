#pragma once

#include <stdexcept>
#include <string>

#include "..\include\Exceptions.hpp"

inline void checkFullConversion(const std::string& value, size_t pos) {
    if (pos != value.size()) {
        throw ConversionError("Extra characters in value: " + value);
    }
}

template <typename T>
class ValueConverter {
   public:
    static T convert(const std::string& value);
};

// специализации для базовых типов
template <>
class ValueConverter<int> {
   public:
    static int convert(const std::string& value) {
        try {
            size_t pos;
            int result = std::stoi(value, &pos);
            checkFullConversion(value, pos);
            return result;
        } catch (const std::exception&) {
            throw ConversionError("INvalid integer value: " + value);
        }
    }
};

template <>
class ValueConverter<double> {
   public:
    static double convert(const std::string& value) {
        try {
            size_t pos;
            double result = std::stod(value, &pos);
            checkFullConversion(value, pos);
            return result;
        } catch (const std::exception&) {
            throw ConversionError("Invalid double value: " + value);
        }
    }
};

template <>
class ValueConverter<std::string> {
   public:
    static std::string convert(const std::string& value) { return value; }
};

template <>
class ValueConverter<bool> {
   public:
    static bool convert(const std::string& value) {
        const std::string lower = toLower(value);
        if (lower == "true" || lower == "1" || lower == "on") return true;
        if (lower == "false" || lower == "0" || lower == "off") return false;
        throw ConversionError("Invalid boolean value: " + value);
    }

   private:
    static std::string toLower(const std::string& str) {
        std::string result;
        result.reserve(str.size());
        for (char c : str) {
            result += static_cast<char>(std::tolower(c));
        }
        return result;
    }
};