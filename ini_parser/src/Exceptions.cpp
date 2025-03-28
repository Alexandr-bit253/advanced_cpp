#include <sstream>

#include "..\include\Exceptions.hpp"


FileError::FileError(const std::string& filename, const std::string& message)
    : IniException("File error in '" + filename + "': " + message),
    m_filename(filename) {}