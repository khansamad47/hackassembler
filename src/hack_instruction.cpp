#include <hack_instruction.h>
#include <string>
#include <optional>
#include <exception>
#include <sstream>
#include <regex>
#include <hack_codestrategy.h>

namespace hack {
Instruction::Instruction(std::string instuction, CodeStrategy& codeStrategy): rawInstruction(instuction), codeStrategy(codeStrategy)
{
}

InstructionA::InstructionA(std::string instruction, CodeStrategy& codeStrategy): Instruction(instruction, codeStrategy)
{
    // Validation logic for instruction A
    std::regex re("^@[0-9]+$");
    if (!std::regex_match(rawInstruction, re))
    {
        std::stringstream ss;
        ss << "Invalid A-Instruction: '" << rawInstruction << "'";
        throw std::runtime_error(ss.str());
    }
}

int InstructionA::value() const 
{
    return std::stoi(rawInstruction.substr(1));
}

InstructionC::InstructionC(std::string instruction, CodeStrategy& codeStrategy): Instruction(instruction, codeStrategy)
{
    // Validation logic for instruction C goes here
}

std::optional<std::string> InstructionC::destination() const
{
    size_t pos = rawInstruction.find("=");
    if (pos == std::string::npos) {
        return std::nullopt;
    }
    return std::make_optional<std::string> (rawInstruction.substr(0,pos));
}

std::string InstructionC::computation() const
{
    size_t start = rawInstruction.find("=");
    size_t end = rawInstruction.find(";");
    if (start == std::string::npos) {
        start = 0;
    }
    else {
        start++;
    }
    if (end == std::string::npos) {
        return rawInstruction.substr(start,end);
    }
    return rawInstruction.substr(start,end-start);
}

std::optional<std::string> InstructionC::jump() const
{
    size_t pos = rawInstruction.find(";");
    if (pos == std::string::npos) {
        return std::nullopt;
    }
    return std::make_optional<std::string> (rawInstruction.substr(pos+1));
}

std::string InstructionA::code()
{
    return codeStrategy.convert(*this);
}

std::string InstructionC::code()
{
    return codeStrategy.convert(*this);
}

}
