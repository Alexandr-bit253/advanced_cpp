#pragma once
#include <memory>

#include "..\include\IFileReader.hpp"
#include "..\include\IniData.hpp"
#include "..\include\ValueConverter.hpp"

class IniParser {
   private:
    std::unique_ptr<IniData> m_data;
    std::unique_ptr<IFileReader> m_reader;

    std::string extractSectionName(const std::string& line);
    std::pair<std::string, std::string> parseKeyValue(const std::string& line);
    std::pair<std::string, std::string> parseSectionKey(
        const std::string& section_key) const;

   public:
    explicit IniParser(std::unique_ptr<IFileReader> reader);

    template <typename T>
    T get_value(const std::string& section_key) const {
        auto [section, key] = parseSectionKey(section_key);
        const auto& value = m_data->get(section, key);
        return ValueConverter<T>::convert(value);
    }

    void load(const std::string& filename);
};