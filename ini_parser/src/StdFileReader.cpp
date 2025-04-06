#include "..\include\StdFileReader.hpp"

#include <algorithm>
#include <fstream>

#include "..\include\Exceptions.hpp"
#include "..\include\IniSymbols.hpp"

std::string trimWhitespace(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

std::vector<std::string> StdFileReader::readLines(const std::string& fileName) {
    std::fstream file(fileName);
    if (!file.is_open()) {
        throw FileError(fileName, "Faild to open file");
    }

    std::vector<std::string> lines{};
    std::string line{};

    while (std::getline(file, line)) {
        processLine(line);
        if (!line.empty()) {
            lines.push_back(std::move(line));
        }
    }

    return lines;
}

void StdFileReader::processLine(std::string& line) {
    // удаление комментариев
    size_t commetn_pos = line.find(COMMENT);
    if (commetn_pos != std::string::npos) {
        line.resize(commetn_pos);
    }

    trimWhitespace(line);
}