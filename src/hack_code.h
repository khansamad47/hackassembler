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
    //class Code {
    //    public:
    //    static std::string code(std::unique_ptr<InstructionA> in);
    //    static std::string code(std::unique_ptr<InstructionC> in);
    //};

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
