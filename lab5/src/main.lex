%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
int symfloor = 0;
extern symbol_table symtabl;
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\n)
WHILTESPACE [[:blank:]]

INTEGER [0-9]+
NUMBER [0-9]+(\.[0-9]+)?
CHAR \'.?\'
STRING \".+\"
LB \{
RB \}
LP \(
RP \)
IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*
EQ ==
GT \>
LT \<
GE \>=
LE \<=
NE !=
LOGICAL_AND &&
LOGICAL_OR  \|\|
LOGICAL_NOT !
WHILE while

%%

{BLOCKCOMMENT}  /* */
{LINECOMMENT}  /* do nothing */

"if" return IF;
"else" return ELSE;
"for" return FOR;
"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"double" return T_DOUBLE;
"void"  return T_VOID;
"continue" return CONTINUE;
"break" return BREAK;
"," return COMMA;
";" return  SEMICOLON;
"?" return QMARK;
":" return COLON;
"main" {
    TreeNode* node = new TreeNode(lineno,NODE_MAIN);
    yylval = node;
    return MAIN;
}
"return" {
    TreeNode* node = new TreeNode(lineno,NODE_STMT);
    node->stype = JUMP_STMT;
    yylval = node;
    return RETURN;
}
"printf" {
    TreeNode* node = new TreeNode(lineno,NODE_STMT);
    node->stype = PRINT_STMT;
    yylval = node;
    return PRINTF;
}
"scanf" {
    TreeNode* node = new TreeNode(lineno,NODE_STMT);
    node->stype = INPUT_STMT;
    yylval = node;
    return SCANF;
}
"do" {return DO;}
{WHILE} {return WHILE;}
{EQ} {return EQ;}
{GT} {return GT;}
{LT} {return LT;}
{GE} {return GE;}
{LE} {return LE;}
{NE} {return NE;}
{LOGICAL_AND} { return LOGICAL_AND;}
{LOGICAL_OR} {return LOGICAL_OR;}
{LOGICAL_NOT} {return LOGICAL_NOT;}
"=" {return ASSIGN;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return TIMES;}
"/" {return DIVIDE;}
"%" {return MOD;}
"&" {return AND;}
"|" {return OR;}
"~" {return NOT;}
"++" {return PLUS2;}
"--" {return MINUS2;}
"+=" {return PLUS_ASSIGN;}
"-=" {return MIN_ASSIGN;}
"/=" {return DIV_ASSIGN;}
"%=" { return MOD_ASSIGN;}
"*=" {return TIM_ASSIGN;}
"<<" {return SHIFT_LEFT;}
">>" {return SHIFT_RIGHT;}



{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    yylval = node;
    return INTEGER;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_STRING;
    node->str_val = string(yytext);
    yylval = node;
    return STRING;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->int_val = yytext[1];
    yylval = node;
    return CHAR;
}

{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}
{NUMBER} {
    TreeNode* node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_DOUBLE;
    node->d_val = atof(yytext);
    yylval = node;
    return NUMBER;
}
{LB}    {return LB;}
{RB}    {return RB;}
{LP}    {return LP;}
{RP}    {return RP;}
{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%