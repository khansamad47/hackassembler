#ifndef HACK_PARSER
#define HACK_PARSER

#include <string>
#include <hack_instruction.h>
#include <hack_code.h>
#include <memory>

// Parser
// Parser class is responsible to open and iterate the file

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
