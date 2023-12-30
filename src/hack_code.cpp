#include <hack_code.h>
#include <hack_specification.h>
#include <sstream>
#include <bitset>
#include <map>
#include <algorithm>

namespace hack {
namespace {

std::map<std::string, Specification::C_INSTRUCTION_DESTINATION>  CODE_DESTINATION = {
    { "M", Specification::C_INSTRUCTION_DESTINATION::D_M },
    { "D", Specification::C_INSTRUCTION_DESTINATION::D_D },
    { "DM", Specification::C_INSTRUCTION_DESTINATION::D_DM },
    { "A", Specification::C_INSTRUCTION_DESTINATION::D_A },
    { "AM", Specification::C_INSTRUCTION_DESTINATION::D_AM },
    { "AD", Specification::C_INSTRUCTION_DESTINATION::D_AD },
    { "ADM", Specification::C_INSTRUCTION_DESTINATION::D_ADM },
};

std::map<std::string, Specification::C_INSTRUCTION_JUMP>  CODE_JUMP = {
                { "JGT", Specification::C_INSTRUCTION_JUMP::J_JGT },
                { "JEQ", Specification::C_INSTRUCTION_JUMP::J_JEQ },
                { "JGE", Specification::C_INSTRUCTION_JUMP::J_JGE },
                { "JLT", Specification::C_INSTRUCTION_JUMP::J_JLT },
                { "JNE", Specification::C_INSTRUCTION_JUMP::J_JNE },
                { "JLE", Specification::C_INSTRUCTION_JUMP::J_JLE },
                { "JMP", Specification::C_INSTRUCTION_JUMP::J_JMP }
};

std::map<std::string, Specification::C_INSTRUCTION_COMPUTATION>  CODE_COMPUTATION = {
                { "0", Specification::C_INSTRUCTION_COMPUTATION::C_ZERO      },
                { "1", Specification::C_INSTRUCTION_COMPUTATION::C_ONE       },
                { "-1", Specification::C_INSTRUCTION_COMPUTATION::C_NEG_ONE   },
                { "D", Specification::C_INSTRUCTION_COMPUTATION::C_D         },
                { "X", Specification::C_INSTRUCTION_COMPUTATION::C_X         },
                { "!D", Specification::C_INSTRUCTION_COMPUTATION::C_NOT_D     },
                { "!X", Specification::C_INSTRUCTION_COMPUTATION::C_NOT_X     },
                { "-D", Specification::C_INSTRUCTION_COMPUTATION::C_NEG_D     },
                { "-X", Specification::C_INSTRUCTION_COMPUTATION::C_NEG_X     },
                { "D+1", Specification::C_INSTRUCTION_COMPUTATION::C_D_PLUS_1  },
                { "X+1", Specification::C_INSTRUCTION_COMPUTATION::C_X_PLUS_1  },
                { "D-1", Specification::C_INSTRUCTION_COMPUTATION::C_D_MINUS_1 },
                { "X-1", Specification::C_INSTRUCTION_COMPUTATION::C_X_MINUS_1 },
                { "D+X", Specification::C_INSTRUCTION_COMPUTATION::C_D_PLUS_X  },
                { "D-X", Specification::C_INSTRUCTION_COMPUTATION::C_D_MINUS_X },
                { "X-D", Specification::C_INSTRUCTION_COMPUTATION::C_X_MINUS_D },
                { "D&X", Specification::C_INSTRUCTION_COMPUTATION::C_D_AND_X   },
                { "D|X", Specification::C_INSTRUCTION_COMPUTATION::C_D_OR_X    }
};


}

std::string CodeInstructionA::convert(const Instruction& in)
{
    const InstructionA& instruction = dynamic_cast<const InstructionA&>(in);
    std::string result = std::bitset<16>(instruction.value()).to_string();
    result[0] = '0';
    return result;
}

std::string CodeInstructionC::convert(const Instruction& in)
{
    const InstructionC& instruction = dynamic_cast<const InstructionC&>(in);
    std::stringstream ss;
    ss << "111";
    // Computation
    std::string compution = instruction.computation();
    size_t hasM = compution.find("M");
    ss << ((hasM != std::string::npos) ? "1" : "0"); 
    std::replace(compution.begin(), compution.end(), 'A', 'X');
    std::replace(compution.begin(), compution.end(), 'M', 'X');
    ss << std::bitset<6>(CODE_COMPUTATION[compution]).to_string();

    // Destination
    if(!instruction.destination())
    {
        ss << std::bitset<3>(Specification::C_INSTRUCTION_DESTINATION::D_NULL).to_string();
    }
    else {
        std::string destination = instruction.destination().value();
        ss << std::bitset<3>(CODE_DESTINATION[destination]).to_string();
    }

    // Jump
    if(!instruction.jump())
    {
        ss << std::bitset<3>(Specification::C_INSTRUCTION_JUMP::J_NULL).to_string();
    }
    else {
        std::string jump = instruction.jump().value();
        ss << std::bitset<3>(CODE_JUMP[jump]).to_string();
    }
    return ss.str();
}

//std::string Code::code(std::unique_ptr<InstructionA> instruction)
//{
//    std::string result = std::bitset<16>(instruction.value()).to_string();
//    result[0] = '0';
//    return result;
//}

//std::string Code::code(std::unique_ptr<InstructionC> instruction)
//{
//    std::stringstream ss;
//    ss << "111";
//    // Computation
//    std::string compution = instruction.computation();
//    size_t hasM = compution.find("M");
//    ss << ((hasM != std::string::npos) ? "1" : "0"); 
//    std::replace(compution.begin(), compution.end(), 'A', 'X');
//    std::replace(compution.begin(), compution.end(), 'M', 'X');
//    ss << std::bitset<6>(CODE_COMPUTATION[compution]).to_string();
//
//    // Destination
//    if(!instruction.destination())
//    {
//        ss << std::bitset<3>(Specification::C_INSTRUCTION_DESTINATION::D_NULL).to_string();
//    }
//    else {
//        std::string destination = instruction.destination().value();
//        ss << std::bitset<3>(CODE_DESTINATION[destination]).to_string();
//    }
//
//    // Jump
//    if(!instruction.jump())
//    {
//        ss << std::bitset<3>(Specification::C_INSTRUCTION_JUMP::J_NULL).to_string();
//    }
//    else {
//        std::string jump = instruction.jump().value();
//        ss << std::bitset<3>(CODE_JUMP[jump]).to_string();
//    }
//    return ss.str();
//}

}