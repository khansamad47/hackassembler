#include <string>
namespace hack {

class SymbolTable {
  public:
    SymbolTable();
    void add(std::string symbol, int value);
    int lookup(const std::string& symbol);
        // Returns 
};
}
