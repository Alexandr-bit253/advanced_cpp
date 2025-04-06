#include <gtest/gtest.h>

#include "..\include\ValueConverter.hpp"

TEST(ValueConverterTest, IntConversion) {
    EXPECT_EQ(ValueConverter<int>::convert("123"), 123);
    EXPECT_THROW(ValueConverter<int>::convert("12.3"), ConversionError);
}

TEST(ValueConverterTest, BoolConversion) {
    EXPECT_TRUE(ValueConverter<bool>::convert("true"));
    EXPECT_FALSE(ValueConverter<bool>::convert("off"));
    EXPECT_THROW(ValueConverter<bool>::convert("yes"), ConversionError);
}

TEST(ValueConverterTest, StringConversion) {
    EXPECT_EQ(ValueConverter<std::string>::convert("Hello"), "Hello");
}