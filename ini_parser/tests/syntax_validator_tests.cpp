#include <gtest/gtest.h>

#include "..\include\SyntaxValidator.hpp"

TEST(SyntaxValidatorTest, ValidSection) {
    EXPECT_NO_THROW(SyntaxValidator::validateSectionLine("[Section1]", 1));
}

TEST(SyntaxValidatorTest, InvalidSection) {
    EXPECT_THROW(SyntaxValidator::validateSectionLine("[Section@1]", 1),
                 SyntaxError);
}

TEST(SyntaxValidatorTest, KeyValueParsing) {
    EXPECT_NO_THROW(SyntaxValidator::validateKeyValueLine("key = value", 1));
}

TEST(SyntaxValidateTest, EmptyLineDetection) {
    EXPECT_TRUE(SyntaxValidator::isCommentOrEmpty("   "));
    EXPECT_TRUE(SyntaxValidator::isCommentOrEmpty(";is comment"));
}