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
        SyntaxValidator validator;
        std::string current_section;
        for (size_t line_num = 0; line_num < lines.size(); ++line_num) {
            const auto& line = lines[line_num];
            try {
                // пропуск пустых строк и комментариев
                if (line.empty() || line[0] == COMMENT) continue;
                // обработка секций
                if (line[0] == SECTION_START) {
                    size_t end_pos = line.find(SECTION_END);
                    if (end_pos == std::string::npos) {
                        throw SyntaxError(line_num + 1,
                                          "Unclosed section header");
                    }
                    current_section =
                        trimWhitespace(line.substr(1, end_pos - 1));
                    if (current_section.empty()) {
                        throw SyntaxError(line_num + 1, "Empty section name");
                    }
                    m_data->addSection(current_section);//<------------------------
                }
            } catch (const SyntaxError&) {
                throw;
            } catch (const std::exception& ex) {
                throw SyntaxError(line_num + 1, ex.what());
            }
        }
    } catch (const std::ios_base::failure&) {
        throw FileError(filename, "Failed to open or read file");
    }
}