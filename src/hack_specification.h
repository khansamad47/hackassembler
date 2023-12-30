#ifndef HACK_SPECIFICATION
#define HACK_SPECIFICATION

namespace hack{
    class Specification {
        public:
            const size_t C_INSTRUCTION_DESTINATION_SIZE = 3;
            enum C_INSTRUCTION_DESTINATION {
                D_NULL = 0b000,
                D_M    = 0b001,
                D_D    = 0b010,
                D_DM   = 0b011,
                D_A    = 0b100,
                D_AM   = 0b101,
                D_AD   = 0b110,
                D_ADM  = 0b111
            };

            const size_t C_INSTRUCTION_JUMP_SIZE = 3;
            enum C_INSTRUCTION_JUMP {
                J_NULL = 0b000,
                J_JGT  = 0b001,
                J_JEQ  = 0b010,
                J_JGE  = 0b011,
                J_JLT  = 0b100,
                J_JNE  = 0b101,
                J_JLE  = 0b110,
                J_JMP  = 0b111
            };

            const size_t C_INSTRUCTION_COMPUTATION_SIZE = 6;
            enum C_INSTRUCTION_COMPUTATION {
                C_ZERO      = 0b101010,
                C_ONE       = 0b111111,
                C_NEG_ONE   = 0b111010,
                C_D         = 0b001100,
                C_X         = 0b110000,
                C_NOT_D     = 0b001101,
                C_NOT_X     = 0b110001,
                C_NEG_D     = 0b001111,
                C_NEG_X     = 0b110011,
                C_D_PLUS_1  = 0b011111,
                C_X_PLUS_1  = 0b110111,
                C_D_MINUS_1 = 0b001110,
                C_X_MINUS_1 = 0b110010,
                C_D_PLUS_X  = 0b000010,
                C_D_MINUS_X = 0b010011,
                C_X_MINUS_D = 0b000111,
                C_D_AND_X   = 0b000000,
                C_D_OR_X    = 0b010101
            };
    };
}

#endif