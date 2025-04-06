#include <gtest/gtest.h>

#include "..\include\IniParser.hpp"

TEST(ErrorHandlingTest, InvalidFile) {
    auto parser = IniParser(std::make_unique<StdFileReader>());
    EXPECT_THROW(parser.load("nonexistent.ini"), FileError);
}

TEST(ErrorHandlingTest, InvalidSyntax) {
    auto parser = IniParser(std::make_unique<StdFileReader>());
    EXPECT_THROW(parser.load("test_data/invalid.ini"), SyntaxError);
}