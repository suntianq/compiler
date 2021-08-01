#include "symbol.h"
symbol_table::symbol_table(){
};

int symbol_table::findItem(string name,int floor){
    symbol_iter it;
    if(sym_table.size()==0)
        return 0;
    else{
        for(it=sym_table.begin();it<sym_table.end();it++){
            if(it->name==name&&it->symfloor==floor)
                return (int)(it - sym_table.begin());
        }
    }
    return 0;
}

int symbol_table::insert(string name,ValueType type,int floor){
    int offset = findItem(name,floor);
    if(offset==0){
        symbol_item new_item = symbol_item(name,type,floor);
        sym_table.push_back(new_item);
        return sym_table.size()-1;
    }
    return -1;
}
int symbol_table::insert(string name,int floor){
    int offset = findItem(name,floor);
    if(offset==0){
        symbol_item new_item;
        new_item.symfloor=floor;
        new_item.name = name;
        sym_table.push_back(new_item);
        return sym_table.size()-1;
    }
    return -1;
}

void symbol_table::setType(int pos,ValueType type){
    sym_table[pos].type=type;
}

symbol_table symtabl;