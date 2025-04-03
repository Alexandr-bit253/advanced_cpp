#include "..\include\IniData.hpp"

void IniData::clear() noexcept { m_sections.clear(); }

void IniData::addSection(const std::string& name) {
    m_sections.try_emplace(name);
}

void IniData::addValue(const std::string& section, const std::string& key,
                       const std::string& value) {
    m_sections[section][key] = value;
}

const std::string& IniData::get(const std::string& section,
                                const std::string& key) const {
    auto sect_it = m_sections.find(section);
    if (sect_it == m_sections.end()) {
        throw ValueNotFound(section, key, {});
    }
    auto key_it = sect_it->second.find(key);
    if (key_it == sect_it->second.end()) {
        throw ValueNotFound(section, key, {});
    }

    return key_it->second;
}

std::vector<std::string> IniData::getKeys(const std::string& section) const {
    std::vector<std::string> keys;
    if (auto it = m_sections.find(section); it != m_sections.end()) {
        keys.reserve(it->second.size());
        for (const auto& [key, _] : it->second) {
            keys.push_back(key);
        }
    }
    return keys;
}

bool IniData::hasSection(const std::string& section) const noexcept {
    return m_sections.find(section) != m_sections.end();
}