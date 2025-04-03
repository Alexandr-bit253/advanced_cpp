#include "..\include\SyntaxValidator.hpp"

#include <algorithm>
#include <cctype>

#include "..\include\Exceptions.hpp"

bool isAllowedNameChar(char c) {
    return std::isalnum(c) || c == '_' || c == '-' || c == '.';
}

