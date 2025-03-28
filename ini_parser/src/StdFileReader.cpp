#include <fstream>

#include "..\include\StdFileReader.hpp"
#include "..\include\Exceptions.hpp"


std::vector<std::string> StdFileReader::readLines(const std::string& fileName) {
    std::fstream file(fileName);
    if (!file.is_open()) {
        throw FileError(fileName, "Faild to open file");
    }

    std::vector<std::string> lines{};

    return lines;
}