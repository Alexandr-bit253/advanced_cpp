#pragma once


#include "..\include\IFileReader.hpp"


class StdFileReader : public IFileReader {
public:
    StdFileReader() = default;
    std::vector<std::string> readLines(const std::string& fileName) override;

private:
    void processLine(std::string& line);
};