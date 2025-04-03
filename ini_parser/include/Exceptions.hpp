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