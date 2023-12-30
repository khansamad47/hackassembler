#include <hack_instruction.h>

#include <gtest/gtest.h>
#include <string>
#include <exception>

using namespace hack;

// Test 
TEST(InstructionA, constructor_valid_1)
{
    EXPECT_NO_THROW({
        auto result = InstructionA("@0");
        EXPECT_EQ(result.value(), 0);
    });
}

TEST(InstructionA, constructor_valid_2)
{
    EXPECT_NO_THROW({
        auto result = InstructionA("@9999");
        EXPECT_EQ(result.value(), 9999);
    });
}

TEST(InstructionA, constructor_invalid)
{
    EXPECT_THROW(InstructionA("@"), std::runtime_error);
}

TEST(InstructionA, convert_invalid_2)
{
    EXPECT_THROW(InstructionA("123"), std::runtime_error);
}

TEST(InstructionC, testExtractFuncions1)
{
    auto result = InstructionC("M=D+M;JMP");
    EXPECT_EQ(result.computation(),"D+M");
    EXPECT_EQ(result.jump().value(),"JMP");
    EXPECT_EQ(result.destination().value(),"M");
}

TEST(InstructionC, testExtractFuncions2)
{
    auto result = InstructionC("0;JMP");
    EXPECT_EQ(result.computation(),"0");
    EXPECT_EQ(result.jump().value(),"JMP");
    EXPECT_FALSE(result.destination());
}
TEST(InstructionC, testExtractFuntions3)
{
    auto result = InstructionC("ADM=D+M;JEQ");
    EXPECT_EQ(result.computation(),"D+M");
    EXPECT_EQ(result.jump().value(),"JEQ");
    EXPECT_EQ(result.destination().value(),"ADM");
}
TEST(InstructionC, testExtractFuntions4)
{
    auto result = InstructionC("D+A");
    EXPECT_EQ(result.computation(),"D+A");
    EXPECT_FALSE(result.jump());
    EXPECT_FALSE(result.destination());
}
TEST(InstructionC, testExtractFunctions5)
{
    auto result = InstructionC("D=0");
    EXPECT_EQ(result.computation(),"0");
    EXPECT_FALSE(result.jump());
    EXPECT_EQ(result.destination().value(),"D");
}