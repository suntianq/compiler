%option noyywrap
%{
#include "common.h"
#include "main.tab.h" 
int lineno=1;
extern symtable symtbl;
chrtable ct;
%}



BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL (\n)
WHILTESPACE [[:blank:]]

digit [0-9] 
letter [A-Za-z]
id ({letter}|[_])({letter}|{digit}|[_])* 
intnum	{digit}+
conststring		\".*\"
constchar	\'.+\'

%%


{WHILTESPACE} {}
{EOL} {lineno++;}
{BLOCKCOMMENT} {}
{LINECOMMENT} {}
"bool" {return BOOL;}
"break" {return BREAK;}
"case" {return CASE;} 
"char" {return CHAR;}
"class" {return CLASS;}
"const" {return CONST;}
"continue" {return CONTINUE;} 
"default" {return DEFAULT;}
"do" {return DO;} 
"double"        {return DOUBLE;} 
"else"			{return ELSE;}
"false"			{return FALSE;}
"float"			{return FLOAT;}
"for"			{return FOR;}
"goto"          {return GOTO;} 
"if"			{return IF;}
"include"	    {return INCLUDE;}
"int"			{return INT;}
"long"          {return LONG;} 
"main"		    {return MAIN;}
"return"		{return RETURN;}
"short"         {return SHORT;} 
"string"		{return STRING;}
"struct"		{return STRUCT;}
"switch"		{return SWITCH;}
"this"          {return THIS;} 
"true"			{return TRUE;}
"using"         {return USING;} 
"void"          {return VOID;} 
"while"			{return WHILE;}
"printf"         {return PRINTF;}
"scanf"         {return SCANF;}


"%"			{return MOD;}
"++"		{return INC;}
"--"		{return DEC;}
"+"			{return ADD;}
"-"			{return SUB;}
"*"			{return MUL;}
"/"			{return DIV;}
"&"			{return BIT_AND;}
"|"			{return BIT_OR;}
"^"			{return POWER;}
"~"			{return OPNOT;}
"<<"		{return SHIFTL;}
">>"		{return SHIFTR;}
"("			{return LPAREN;}
")"			{return RPAREN;}
"["			{return LBRACKET;}
"]"			{return RBRACKET;}
"{"			{return LBRACE;}
"}"			{return RBRACE;}
">"			{return GT;}
"<"			{return LT;}
"="			{return EQ;}
"+="		{return AEQ;}
"-="		{return SEQ;}
"=="		{return EQUAL;}
"!="		{return NEQUAL;}
">="		{return GE;}
"<="		{return LE;}
"||"		{return OR;}
"&&"	    {return AND;}
"!"			{return NOT;}
"'"			{return SQUOTE;}
"\""		{return DQUOTE;}
":"			{return COLON;}
";"			{return SEMICOLON;}
","			{return COMMA;}


{intnum}    {
	Node* n=new Node();
    n->attr.val.vali=atoi(yytext);
	n->type=Integer;
	yylval=n;
    return INTNUMBER;
}
{constchar}		{
				Node* n=new Node();
				string temp=string(yytext);
				n->attr.val.valc=temp.at(1);
				if(n->attr.val.valc=='\\'){
					n->attr.val.valc1=temp.at(2);
					ct.insert(n->attr.val.valc,n->attr.val.valc1);
				}
				else
					ct.insert(n->attr.val.valc);
				yylval=n;
				return CONSTCHAR;
}
				
{conststring}	{
                Node* n=new Node();
				n->attr.val.vals=yytext;
				ct.insert(n->attr.val.vals);
				yylval=n;
				return CONSTSTRING;
}

{id}        {
                Node* n=new Node();
				n->attr.val.vals=yytext;
				n->name=yytext;
				yylval=n;
				return ID;
}

    

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%