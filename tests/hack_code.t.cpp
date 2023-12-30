#include <hack_instruction.h>
#include <hack_code.h>

#include <gtest/gtest.h>
#include <string>
#include <exception>

using namespace hack;

// Test 
TEST(CodeInstructionA, valid_0)
{
    auto result = InstructionA("@0");
    EXPECT_EQ(CodeInstructionA::convert(result), "0000000000000000");
}

TEST(InstructionA, valid_9999)
{
    auto result = InstructionA("@9999");
    EXPECT_EQ(CodeInstructionA::convert(result), "0010011100001111");
}

TEST(InstructionC, test1)
{
    auto result = InstructionC("M=D+M;JMP");
    EXPECT_EQ(CodeInstructionC::convert(result), "1111000010001111");
}
TEST(InstructionC, test2)
{
    auto result = InstructionC("D=D-M");
    EXPECT_EQ(CodeInstructionC::convert(result), "1111010011010000");
}

TEST(InstructionC, test3)
{
    auto result = InstructionC("D;JEQ");
    EXPECT_EQ(CodeInstructionC::convert(result),"1110001100000010");
}
TEST(InstructionC, test4)
{
    auto result = InstructionC("D=M");       
    EXPECT_EQ(CodeInstructionC::convert(result), "1111110000010000");
}
TEST(InstructionC, test5)
{
    auto result = InstructionC("M=D+M");     
    EXPECT_EQ(CodeInstructionC::convert(result), "1111000010001000");
}

TEST(InstructionC, test6)
{
    auto result = InstructionC("M=M+1");     
    EXPECT_EQ(CodeInstructionC::convert(result),"1111110111001000");
}

TEST(InstructionC, test7)
{
    auto result = InstructionC("0;JMP");
    EXPECT_EQ(CodeInstructionC::convert(result),"1110101010000111");
}