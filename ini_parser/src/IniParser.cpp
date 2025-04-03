#include "..\include\IniParser.hpp"

#include <algorithm>
#include <sstream>
#include <utility>

#include "..\include\Exceptions.hpp"
#include "..\include\IFileReader.hpp"
#include "..\include\IniSymbols.hpp"
#include "..\include\SyntaxValidator.hpp"

std::string trimWhitespace(const std::string& str) {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

IniParser::IniParser(std::unique_ptr<IFileReader> reader)
    : m_reader(std::move(reader)), m_data(std::make_unique<IniData>()) {}

void IniParser::load(const std::string& filename) {
    m_data->clear();
    try {
        auto lines = m_reader->readLines(filename);
        std::string current_section;
        for (size_t line_num = 0; line_num < lines.size(); ++line_num) {
            const auto& raw_line = lines[line_num];
            const size_t global_line_num = line_num + 1;
            try {
                // пропуск пустых строк и комментариев
                if (SyntaxValidator::isCommentOrEmpty(raw_line)) continue;

                std::string line = raw_line;
                SyntaxValidator::trimLine(line);

                // обработка секций
                if (line[0] == SECTION_START) {
                    SyntaxValidator::validateSectionLine(line, global_line_num);
                    current_section = extractSectionName(line);
                    m_data->addSection(current_section);
                } else {
                    SyntaxValidator::validateKeyValueLine(line,
                                                          global_line_num);
                    auto [key, value] = parseKeyValue(line);
                    m_data->addValue(current_section, key, value);
                }
            } catch (const SyntaxError& ex) {
                throw_with_nested(IniException("Error in line " +
                                               std::to_string(global_line_num) +
                                               ": " + ex.what()));
            }
        }
    } catch (const FileError&) {
        throw;
    } catch (const std::exception& ex) {
        throw IniException("Failed to parse INI file: " +
                           std::string(ex.what()));
    }
}

std::string IniParser::extractSectionName(const std::string& line) {
    size_t end_pos = line.find(SECTION_END);
    std::string name = line.substr(1, end_pos - 1);
    SyntaxValidator::trimLine(name);
    return name;
}

std::pair<std::string, std::string> IniParser::parseKeyValue(
    const std::string& line) {
    size_t equal_pos = line.find(EQUAL);
    std::string key = line.substr(0, equal_pos);
    std::string value = line.substr(equal_pos + 1);

    SyntaxValidator::trimLine(key);
    SyntaxValidator::trimLine(value);

    return {key, value};
}