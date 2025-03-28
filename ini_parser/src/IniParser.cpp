#include <algorithm>
#include <sstream>
#include <utility>

#include "..\include\IniParser.hpp"


constexpr char SECTION_START = '[';
constexpr char SECTION_END = ']';
constexpr char COMMENT = ';';
constexpr char EQUAL = '=';


IniParser::IniParser() {
    
}