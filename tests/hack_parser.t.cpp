#include <hack_parser.h>

#include <gtest/gtest.h>
#include <string>

using namespace hack;

TEST(Parser, cleanup_remove_comment)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces("// This is a comment");
    EXPECT_EQ(result,"");
}

TEST(Parser, cleanup_remove_emptyline)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces("    ");
    EXPECT_EQ(result,"");
}

TEST(Parser, cleanup_remove_whitespace)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces(" @command   ");
    EXPECT_EQ(result,"@command");
}

TEST(Parser, cleanup_remove_end_of_line_comment)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces(" @command // commeent // comment  ");
    EXPECT_EQ(result,"@command");
}

TEST(Parser, cleanup_remove_whitespace_in_between)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces("M=A + B; JMP ");
    EXPECT_EQ(result,"M=A+B;JMP");
}

TEST(Parser, cleanup_remove_whitespace_in_between_and_comment)
{
    std::string result = Parser::removeCommentsAndWhiteSpaces("M=A + B; JMP // this is a comment");
    EXPECT_EQ(result,"M=A+B;JMP");
}
