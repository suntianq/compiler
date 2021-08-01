#ifndef SYMBOL_H
#define SYMBOL_H

#include "./pch.h"
#include "type.h"

struct symbol_item
{
    string name;    //标识符名字
    ValueType type; //类型
    int symfloor;      //位于哪一层
    symbol_item(){
        symfloor=0;
    }
    symbol_item(string n,ValueType t,int f){
        this->name = n;
        this->type = t;
        this->symfloor= f;
    }
};
typedef vector<symbol_item>::iterator symbol_iter;
class symbol_table {
public:
    vector<symbol_item> sym_table;
public: 
    symbol_table();
    int findItem(string,int);
    int insert(string,ValueType,int);
    int insert(string,int);
    void setType(int,ValueType);
};



#endif