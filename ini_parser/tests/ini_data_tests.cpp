#include <gtest/gtest.h>

#include <memory>

#include "..\include\IniData.hpp"

TEST(IniDataTest, SectionOperation) {
    IniData data;
    data.addSection("Database");
    EXPECT_TRUE(data.hasSection("Database"));
    EXPECT_FALSE(data.hasSection("Network"));
}

TEST(IniDataTest, ValueStorage) {
    IniData data;
    data.addValue("Section", "key", "value");
    EXPECT_EQ(data.get("Section", "key"), "value");
}

TEST(IniDataTest, OverwriteValue) {
    IniData data;
    data.addValue("Section", "key", "old");
    data.addValue("Section", "key", "new");
    EXPECT_EQ(data.get("Section", "key"), "new");
}