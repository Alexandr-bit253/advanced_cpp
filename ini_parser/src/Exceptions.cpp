#include "..\include\Exceptions.hpp"

#include <sstream>

std::string format_suggestions(const std::vector<std::string>& suggestions) {
    if (suggestions.empty()) return "";

    std::ostringstream oss;
    oss << " Did you mean: ";
    for (size_t i = 0; i < suggestions.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << "'" << suggestions[i] << "'";
    }
    return oss.str();
}

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

ValueNotFound::ValueNotFound(const std::string& section, const std::string& key,
                             std::vector<std::string> suggestions)
    : IniException([&section, &key, &suggestions] {
          std::ostringstream oss;
          oss << "Value '" << key << "' not found in section '" << section
              << "'." << format_suggestions(suggestions);
          return oss.str();
      }()),
      m_section(section),
      m_key(key),
      m_suggestions(std::move(suggestions)) {}