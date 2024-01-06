#ifndef HACK_SYMBOLTABLE
#define HACK_SYMBOLTABLE

#include <string>
#include <map>

namespace hack {

class SymbolTable {
  public:
    typedef std::string Symbol;
    typedef int Address;
    SymbolTable();
    void insert(Symbol symbol, Address address);
    Address lookup(const Symbol& symbol);
    bool contains(Symbol symbol);
  private:
    std::map <Symbol,Address> table;
};

}

#endif
