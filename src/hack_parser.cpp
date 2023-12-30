#include <hack_parser.h>

#include <string>
#include <algorithm>
#include <memory>
#include <hack_code.h>

namespace hack {

std::string Parser::removeCommentsAndWhiteSpaces(std::string input)
{
       size_t pos = input.find("//");
       if (pos != std::string::npos)
       {
           input.erase(pos);
       }
       input.erase(std::remove_if(input.begin(), input.end(), [](unsigned char c){return std::isspace(c);}), input.end());
       return input;
}

std::unique_ptr<Instruction> Parser::convert(std::string input)
{
    if (input[0] == '@')
    {
        // This is an A-Instruction
        return std::make_unique<InstructionA>(input, codeInstructionA);
    }
    else {
        // This is a C-Instruction
        return std::make_unique<InstructionC>(input, codeInstructionC);
    }
}

}