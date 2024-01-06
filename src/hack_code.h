#ifndef HACK_CODE
#define HACK_CODE

#include <string>
#include <hack_instruction.h>
#include <memory>
#include <hack_codestrategy.h>

// Converts Instruction to machine code
// Assumes Insturction is well-formed and valid.
// Invalid instruction is UB

namespace hack {
    class CodeInstructionA: public CodeStrategy {
        public: 
            std::string convert(const Instruction& in);
    };

    class CodeInstructionC: public CodeStrategy {
        public: 
            std::string convert(const Instruction& in);
    };
}

#endif
