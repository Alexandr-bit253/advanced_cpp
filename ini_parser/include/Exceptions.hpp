#pragma once

#include <stdexcept>
#include <string>
#include <vector>

class IniException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class FileError : public IniException {
   public:
    FileError(const std::string& filename, const std::string& message);
    const std::string& get_filename() const noexcept { return m_filename; }

   private:
    std::string m_filename{};
};

class SyntaxError : public IniException {
   public:
    SyntaxError(size_t line_num, const std::string& details);
    size_t line_number() const noexcept { return m_line_num; }

   private:
    size_t m_line_num{};
};

class ValueNotFound : public IniException {
   public:
    ValueNotFound(const std::string& section, const std::string& key,
                  std::vector<std::string> suggestions);
    const std::string& section() const noexcept { return m_section; }
    const std::string& key() const noexcept { return m_key; }
    const std::vector<std::string>& suggestions() const noexcept {
        return m_suggestions;
    }

   private:
    std::string m_section;
    std::string m_key;
    std::vector<std::string> m_suggestions;
};

class ConversionError : public IniException {
   public:
    explicit ConversionError(const std::string& message)
        : IniException("Conversion error: " + message) {}
};