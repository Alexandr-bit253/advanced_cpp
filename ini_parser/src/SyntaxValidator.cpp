#include "..\include\SyntaxValidator.hpp"

#include <algorithm>
#include <cctype>

#include "..\include\Exceptions.hpp"
#include "..\include\IniSymbols.hpp"

bool isAllowedNameChar(char c) {
    return std::isalnum(c) || c == '_' || c == '-' || c == '.';
}

void SyntaxValidator::trimLine(std::string& line) {
    // удаление пробелов в начале и конце
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](int ch) {
                   return !std::isspace(ch);
               }));

    line.erase(std::find_if(line.rbegin(), line.rend(),
                            [](int ch) { return !std::isspace(ch); })
                   .base(),
               line.end());
}

bool SyntaxValidator::isCommentOrEmpty(const std::string& line) noexcept {
    return line.empty() || line[0] == COMMENT;
}

void SyntaxValidator::validateSectionName(const std::string& name,
                                          size_t line_num) {
    if (name.empty()) {
        throw SyntaxError(line_num, "Empty section name");
    }

    if (!std::all_of(name.begin(), name.end(), isAllowedNameChar)) {
        throw SyntaxError(line_num, "Invalid characters in section name");
    }
}

void SyntaxValidator::validateKey(const std::string& key, size_t line_num) {
    if (key.empty()) {
        throw SyntaxError(line_num, "Empty key name");
    }

    if (!std::all_of(key.begin(), key.end(), isAllowedNameChar)) {
        throw SyntaxError(line_num, "Invalid characters in key name");
    }
}

void SyntaxValidator::validateValue(const std::string& value, size_t line_num) {
    if (value.find('\n') != std::string::npos) {
        throw SyntaxError(line_num, "Multiline values are not supported");
    }
}

void SyntaxValidator::validateSectionLine(const std::string& line,
                                          size_t line_num) {
    std::string trimmed = line;
    trimLine(trimmed);

    if (trimmed.empty() || trimmed.front() != SECTION_START) {
        throw SyntaxError(line_num, "Ivalid section declaration");
    }

    size_t end_pos = trimmed.find(SECTION_END);
    if (end_pos == std::string::npos) {
        throw SyntaxError(line_num, "Unclosed section header");
    }

    std::string section_name = trimmed.substr(1, end_pos - 1);
    trimLine(section_name);

    validateSectionName(section_name, line_num);
}

void SyntaxValidator::validateKeyValueLine(const std::string& line,
                                           size_t line_num) {
    std::string trimmed = line;
    trimLine(trimmed);

    size_t equal_pos = trimmed.find(EQUAL);
    if (equal_pos == std::string::npos) {
        throw SyntaxError(line_num, "Missing '=' in key-value pair");
    }

    std::string key = trimmed.substr(0, equal_pos);
    trimLine(key);
    validateKey(key, line_num);

    std::string value = trimmed.substr(equal_pos + 1);
    trimLine(value);
    validateValue(value, line_num);
}