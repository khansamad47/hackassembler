#ifndef HACK_PARSER
#define HACK_PARSER

#include <string>
#include <hack_instruction.h>
#include <hack_code.h>
#include <memory>

namespace hack {

class Parser {
    private:
        CodeInstructionA codeInstructionA;
        CodeInstructionC codeInstructionC;
    public:
        std::string removeCommentsAndWhiteSpaces(std::string input);
        std::unique_ptr<Instruction> convert(std::string input);
};

}

#endif