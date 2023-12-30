#ifndef HACK_CODE_STRATEGY
#define HACK_CODE_STRATEGY

#include <string>

namespace hack {

class Instruction;

class CodeStrategy {
    public:
        virtual std::string convert(const Instruction&) = 0;
};

}

#endif