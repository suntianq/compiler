#include "common.h"
#include <fstream>

extern FILE *yyin;
extern symtable symtbl;
extern chrtable ct;
extern tree parse_tree;
extern int yyparse();

using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    yyparse();
    if(parse_tree.root != NULL) {
        //parse_tree.root->genNodeId(root);
        //parse_tree.root->printAST(root);
        parse_tree.get_label();
        parse_tree.gen_code();
    }
    return 0;
}