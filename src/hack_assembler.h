#include <string>

namespace hack {
class Assembler {
    public:
        Assembler(std::string asmFilePath);
    private:
        std::string asmFilePath;
};
}