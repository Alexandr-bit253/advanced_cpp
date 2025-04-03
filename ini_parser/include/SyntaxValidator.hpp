#pragma once
#include <string>

#include "..\include\Exceptions.hpp"

class SyntaxValidator {
   public:
    static void validateSectionLine(const std::string& line, size_t line_num);
    static void validateKeyValueLine(const std::string& line, size_t line_num);
    static bool isCommentOrEmpty(const std::string& line) noexcept;
    static void trimLine(std::string& line);

   private:
    static void validateSectionName(const std::string& name, size_t line_num);
    static void validateKey(const std::string& key, size_t line_num);
    static void validateValue(const std::string& value, size_t line_num);
};