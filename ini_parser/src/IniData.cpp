#include "..\include\IniData.hpp"

void IniData::clear() noexcept { m_sections.clear(); }

void IniData::addSection(const std::string& name) {
    m_sections.try_emplace(name);
}