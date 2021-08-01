%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef YYSTYPE
#define YYSTYPE char*
#endif

char idStr[50];
char numStr[50];
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}

%token NUMBER ID 
%token ADD MINUS 
%token MUL DEV
%token lbracket rbracket
%token UMIN
%token end_sign
%left ADD MINUS
%left MUL DEV
%right UMIN

%start lines


%%

lines  :    lines expr '\n'  {printf("%s\n",$2);}
       |    lines end_sign  {exit(0);}
       |
;

expr   :    NUMBER  {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$," ");}
       |    ID      {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$," ");}
       |    expr ADD expr   {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$,$3);strcat($$,"+ ");}
       |    expr MINUS expr {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$,$3);strcat($$,"- ");}
       |    expr MUL expr   {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$,$3);strcat($$,"* ");}
       |    expr DEV expr   {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$1);strcat($$,$3);strcat($$,"/ ");}
       |    lbracket expr rbracket  {$$=(char *)malloc(50*sizeof(char)); strcpy($$,$2);}
       |    MINUS expr %prec UMIN   {$$=(char *)malloc(50*sizeof(char)); strcpy($$,"0");strcat($$,$2);strcat($$,"- ");}
;

%%

int yylex(){
    int t;
    while(1){
 
        t=getchar();   
        int ti=0;
        if(t==' '||t=='\t'){
        ;
        }
        else if(t>='0'&&t<='9'){
            while(t>='0'&&t<='9'){
                numStr[ti]=t;
                ti++;
                t=getchar();
            }
            numStr[ti]='\0';
            yylval=numStr;
            ungetc(t,stdin);
            return NUMBER;
        }
        else if((t>='a'&&t<='z')||(t>='A'&&t<='Z')||(t=='_')){

            while((t>='a'&&t<='z')||(t>='A'&&t<='Z')||(t=='_')||(t>='0'&&t<='9')){
                idStr[ti]=t;
                ti++;
                t=getchar();
            }
            idStr[ti]='\0';
            yylval=idStr;
            ungetc(t,stdin);
            return ID;
        }
        else if(t=='+')
            return ADD;
        else if(t=='-')
            return MINUS;
        else if(t=='*')
            return MUL;
        else if(t=='/')
            return DEV;
        else if(t=='(')
            return lbracket;
        else if(t==')')
            return rbracket;
        else if(t=='!')
            return end_sign;
        else    
            return t;
    }
}

int main()
{
    yyin = stdin;
    do
    {
        yyparse();
    }while(!feof(yyin));
    return 0;
}

void yyerror(const char* s)
{
    fprintf(stderr, "Parse error: %s\n", s);
    exit(1);
}
