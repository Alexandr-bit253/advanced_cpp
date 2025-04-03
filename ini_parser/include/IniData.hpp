#pragma once

#include <map>
#include <string>
#include <vector>

#include "..\include\Exceptions.hpp"

class IniData {
   public:
    using Section = std::map<std::string, std::string>;
    void clear() noexcept {};
    void addSection(const std::string& name);

   private:
    std::map<std::string, Section> m_sections;
};