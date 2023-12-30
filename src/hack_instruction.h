#ifndef HACK_INSTRUCTION
#define HACK_INSTRUCTION

#include <string>
#include <optional>
#include <hack_codestrategy.h>

// This module defines classes to represent Instruction
// Assumes instruction is wellformed and does not do any 
// kind of validation.
// Initializing the class with an invalid instuction format
// is UB

namespace hack {
    class Instruction
    {
        protected:
            std::string rawInstruction;
            CodeStrategy& codeStrategy;
        public:
            Instruction(std::string, CodeStrategy&);
            virtual std::string code() = 0;
    };

    class InstructionA: public Instruction {
        public:
            InstructionA(std::string, CodeStrategy&);
            int value() const;
            std::string code();
    };

    class InstructionC: public Instruction {
        public:
            InstructionC(std::string instruction, CodeStrategy&);
            std::string code();
            std::optional<std::string> destination() const;
            std::string computation() const;
            std::optional<std::string> jump() const;
    };
};

#endif