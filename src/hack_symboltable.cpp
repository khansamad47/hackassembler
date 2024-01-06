#include <hack_symboltable.h>

namespace hack {

SymbolTable::SymbolTable() {}

void SymbolTable::insert(Symbol symbol, Address address)
{
    table[symbol] = address;
}

SymbolTable::Address SymbolTable::lookup(const Symbol& symbol)
{
    return table.at(symbol);
}

bool SymbolTable::contains(Symbol symbol)
{
    return table.find(symbol) != table.end();
}

}
