#include <algorithm>
#include <fstream>

#include "..\include\StdFileReader.hpp"
#include "..\include\Exceptions.hpp"


void trim(std::string& line) {
    constexpr char whitespace[] = " \t";
    line.erase(0, line.find_first_not_of(whitespace));
    line.erase(line.find_last_not_of(whitespace) + 1);
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
    size_t commetn_pos = line.find(';');
    if (commetn_pos != std::string::npos) {
        line.resize(commetn_pos);
    }
    
    trim(line);
}