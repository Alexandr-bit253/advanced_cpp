#pragma once

#include <string>
#include <vector>


class IFileReader{
public:
    virtual ~IFileReader() = default;
    virtual std::vector<std::string> readLines(const std::string& filename) = 0;

    IFileReader(const IFileReader&) = delete;
    IFileReader& operator=(const IFileReader&) = delete;

protected:
    IFileReader() = default;
};