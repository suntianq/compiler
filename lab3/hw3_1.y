%{
#include<stdio.h>
#include<stdlib.h>

#ifndef YYSTYPE
#define YYSTYPE double
#endif

int yylex();
extern int yyparse();
FILE* yyin;

void yyerror(const char *s);

%}

%token NUMBER
%token ADD MINU MUL DEV lbracket rbracket
%token UMINUS 
%token exit_sign equal
%left ADD MINU
%left MUL DEV
%right UMINUS

%start lines

%%

lines: lines expr equal   {printf("%f\n",$2);}
     | lines equal
     | lines exit_sign  {exit(0);}
     |
;

expr: NUMBER            {$$=$1;}
    | expr ADD expr     {$$=$1+$3;}
    | expr MINU expr    {$$=$1-$3;}
    | expr MUL expr     {$$=$1*$3;}
    | expr DEV expr     {$$=$1/$3;}
    | lbracket expr rbracket {$$=$2;}
    | MINU expr %prec UMINUS {$$=-$2;}
;

%%

int yylex(){
        int t;
        while(1){
            t=getchar();
            switch(t){
                case '\t': case ' ': case '\n':
                    break;
                case '+':
                    return ADD;
                case '-':
                    return MINU;
                case '*':
                    return MUL;
                case '/':
                    return DEV;
                case '(':
                    return lbracket;
                case ')':
                    return rbracket;
                case 'q':
                    return exit_sign;
                case '=':
                    return equal;
                case '0': case '1': case '2': case '3': case '4':case '5':case '6':case '7': case '8':case '9': 
                    yylval = 0;
                    while(t>='0'&&t<='9'){
                        yylval = yylval*10 +t-'0';
                        t=getchar();
                    }
                    ungetc(t,stdin);
                    return NUMBER;
                defalut:
                    return t;
            }
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