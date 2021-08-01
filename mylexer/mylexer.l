%option noyywrap
%{
#include <iomanip>
#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define maxTableNum 200

struct table{
    int index;
    char*  symname;
};

table hashTable[200];


char listtable[100][100];
int indentation=0;
int to_new=0;

void listtableinitial();
int inlisttable(char *text);
int addidlist(char* text) ;
int placeintolist(char*);
int hash_zyy(char *);

//初始化table函数：
void initTable(table * hashtab);


void printml(string token,string text);
void printid(string text);
void printnumber(string text);

//将保留字转换成大写输出
char *trans_to_capital(char* text,int length);

//获取标识符对应属性
int id_num(string text);

//获取常数的值
double num_value(string text);



%}

blank       [\t\n ]
digit       [0-9]
num         {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
id          [A-Za-z_][A-Za-z0-9_]*
siglincom    "//".*\n
commentbegin "/*"
commentelement .|\n
commentend   "*/"
%x COMMENT 

%%


{blank} {}


"bool" |  
"char" | 
"double" |
"float" |
"long" |
"int" |
"short" |
"void" |            {printml(trans_to_capital(yytext,yyleng),yytext);to_new=1;}


"break" | 
"case" |
"class" |
"const" |
"continue" | 
"default" |
"do" |
"false" |
"goto" |
"new" |
"return" |
"sizeof" |
"struct" |
"static" |
"switch" |
"this" |
"true" |
"using" |
"#include" |
"#define"               
"while" | 
"for" |
"if" |
"else" |                {printml(trans_to_capital(yytext,yyleng),yytext);}

{id}    {printid(yytext);}

{num}   {printnumber(yytext);}

"["     {printml("LBRACK",yytext);}
"]"     {printml("RBRACK",yytext);}
"{"     {printml("LBRACE",yytext);indentation++;to_new=0;}
"}"     {printml("RBRACE",yytext);}
"("     {printml("LKUOHAO",yytext);}
")"     {printml("YKUOHAO",yytext);}
"->"    {printml("STRUCTOP",yytext);}
"++"    {printml("SELF_PLUS",yytext);}
"--"    {printml("SELF_DEC",yytext);}
"~"     {printml("LOG_RE",yytext);}
"!"     {printml("LOG_NOT",yytext);}
"+"     {printml("PLUS",yytext);}
"-"     {printml("DEC",yytext);}
"&"     {printml("AND",yytext);}
"*"     {printml("MUL",yytext);}
"/"     {printml("DIV",yytext);}
"%"     {printml("PERA",yytext);}
"<<"    {printml("LEFTMOV",yytext);}
">>"    {printml("RIGHTMOV",yytext);}
"<"     {printml("LESS",yytext);}
">"     {printml("BIGGER",yytext);}
"<="    {printml("LESS_EQ",yytext);}
">="    {printml("BIG_EQ",yytext);}
"^"     {printml("XOR",yytext);}
"|"     {printml("BIT_OR",yytext);}
"&&"    {printml("LOG_AND",yytext);}
"||"    {printml("LOG_OR",yytext);}
"="     {printml("ASSIGN",yytext);}
"=="    {printml("EQ",yytext);}
"!="    {printml("NOT_EQ",yytext);}
"+="    {printml("PLUS_EQ",yytext);}
"-="    {printml("DEC_EQ",yytext);}
"*="    {printml("MUL_EQ",yytext);}
"/="    {printml("DIV_EQ",yytext);}
"%="    {printml("PERA_EQ",yytext);}
"<<="   {printml("LEFTMOV_EQ",yytext);}
">>="   {printml("RIGHTMOV_EQ",yytext);}
"&="    {printml("AND_EQ",yytext);}
"|="    {printml("OR_EQ",yytext);}
"^="    {printml("XOR_EQ",yytext);}
","     {printml("COMMA",yytext);}
";"     {printml("SEMI",yytext);to_new=0;}
":"     {printml("COLON",yytext);}
"."     {printml("DOT",yytext);}

{siglincom}         {}
{commentbegin}      {BEGIN COMMENT;}
<COMMENT>{commentelement}    {}
<COMMENT>{commentend}        {BEGIN INITIAL;}

%%
void initTable(table* hashtab){
    for(int i=0;i<maxTableNum;i++){
        hashtab[i].symname=new char[15];
        hashtab[i].symname[0]='0';
        hashtab[i].symname[1]='\0';
    }
}


void listtableinitial(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            listtable[i][j]=0;
        }
    }
}

int inlisttable(char *text){
    for(int i=0;i<100 && listtable[i][0]!=0;i++){
        if(!strcmp(text,listtable[i]))
        return i;
    }
    return 0;
}

/*int addidlist(char *text){
    int i;
    for(i=0;i<100 && listtable[i][0]!=0;i++)
    ;
    strcat(text,"_");
    strcat(text,(char*)(indentation+'0'));
    strcpy(listtable[i],text);
}*/



void printml(string  token,string text){
    cout<<left<< setw(20)<<token.c_str()<<left<< setw(20)<<text.c_str()<<endl;
}
void printid(string text){
    cout<<left<< setw(20)<<"ID"<<left<< setw(20)<<text.c_str()<<left<< setw(20)<<id_num(text)<<endl;
}
void printnumber(string text){
    cout<<left<< setw(20)<<"NUMBER"<<left<< setw(20)<<text.c_str()<<left<< setw(20)<<num_value(text)<<endl;
}

char*  trans_to_capital(char* text,int length){
    char*  temp=new char[length];
    int i=0;
    while(text[i]!='\0'){
        temp[i]=text[i]-32;
        i++;
    }
    return temp;
}

double num_value(string text){
    double ans;
    ans=atof(text.c_str());
    return ans;
}

int id_num(string text){
    int length=text.length();
    char temp[length];
    for(int i=0;i<length;i++)
        temp[i]='0';
    strcpy(temp,text.c_str());
    int hash=0;
    for(int i=0;i<length;i++){
        hash+=(temp[i]-'A'+1)*(i+1);
    }
    hash=hash%200;
    while(true){
        if(strcmp(hashTable[hash].symname,"0")==0){
            strcpy(hashTable[hash].symname,temp);
            return hash;
        }
        else{
    if(strcmp(hashTable[hash].symname,temp)==0)
       {
            return hash;
       }
        else
            hash=(hash+1)%200;
        } 
    }
}


int main(){
    cout<<left<< setw(20)<<"单词"<<left<< setw(20)<<"词素"<<left<< setw(20)<<"属性"<<endl;

    yyFlexLexer lexer;
    initTable(hashTable);
    freopen("./testin.txt","r",stdin);
    lexer.yylex();
    return 0;
}
