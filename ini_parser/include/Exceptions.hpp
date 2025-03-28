#pragma once

#include <stdexcept>
#include <vector>
#include <string>

class IniException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};


class FileError : public IniException {
public:
    FileError(const std::string& filename, const std::string& message);
    const std::string& get_filename () const noexcept{ return m_filename; }

private:
    std::string m_filename{};
};