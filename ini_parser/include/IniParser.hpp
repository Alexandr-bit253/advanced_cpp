#pragma once
#include <memory>

#include "..\include\IFileReader.hpp"
#include "..\include\IniData.hpp"

class IniData;

class IniParser {
   private:
    std::unique_ptr<IniData> m_data;
    std::unique_ptr<IFileReader> m_reader;

   public:
    explicit IniParser(std::unique_ptr<IFileReader> reader);

    // template <typename T>
    // T get_value(const std::string& section_key) const {
    //     auto [section, key] = parseSectionKey(section_key);
    //     const auto& value = m_data->get(section, key);
    // }

    void load(const std::string& filename);
};