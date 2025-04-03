#pragma once

#include <map>
#include <string>
#include <vector>

#include "..\include\Exceptions.hpp"

class IniData {
   public:
    using Section = std::map<std::string, std::string>;
    void clear() noexcept;
    void addSection(const std::string& name);
    void addValue(const std::string& section, const std::string& key,
                  const std::string& value);
    const std::string& get(const std::string& section,
                           const std::string& key) const;
    std::vector<std::string> getKeys(const std::string& section) const;
    bool hasSection(const std::string& section) const noexcept;

   private:
    std::map<std::string, Section> m_sections;
};