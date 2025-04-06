#include <gtest/gtest.h>

#include "..\include\IniData.hpp"
#include "..\include\IniParser.hpp"
#include "..\include\StdFileReader.hpp"

class ParserTest : public ::testing::Test {
   protected:
    void SetUp() override {
        parser = std::make_unique<IniParser>(std::make_unique<StdFileReader>());
    }

    std::unique_ptr<IniParser> parser;
}

TEST_F(ParserTest, BasicParsing) {
    parser->load("test_data/valid.ini");
    EXPECT_EQ(parser->get_value<int>("Section1.var1"), 5);
    EXPECT_EQ(parser->get_value<std::string>("Section2.var2"), "значение");
}

TEST_F(ParserTest, MissingKey) {
    parser->load("test_data/valid.ini");
    EXPECT_THROW(parser->get_value<int>("Section1.missing"), ValueNotFound);
}