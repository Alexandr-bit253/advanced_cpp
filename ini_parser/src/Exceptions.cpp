#include "..\include\Exceptions.hpp"

#include <sstream>

FileError::FileError(const std::string& filename, const std::string& message)
    : IniException("File error in '" + filename + "': " + message),
      m_filename(filename) {}

SyntaxError::SyntaxError(size_t line_num, const std::string& details)
    : IniException([line_num, &details] {
          std::ostringstream oss;
          oss << "Syntax error at line " << line_num << ": " << details;
          return oss.str();
      }()),
      m_line_num(line_num) {}