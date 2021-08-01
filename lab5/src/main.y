%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern int symfloor;
    extern symbol_table symtabl;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL T_DOUBLE T_VOID
%token ASSIGN PLUS_ASSIGN MIN_ASSIGN TIM_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token SEMICOLON LB RB COMMA LP RP QMARK COLON 
%token IDENTIFIER INTEGER CHAR BOOL STRING NUMBER

%token PLUS MINUS TIMES DIVIDE MOD PLUS2 MINUS2 AND OR NOT EQ XOR

%token GT LT GE LE NE LOGICAL_AND LOGICAL_OR LOGICAL_NOT 

%token FOR DO MAIN IF ELSE WHILE RETURN CONTINUE BREAK
%token SCANF PRINTF
%token EOL

%left LOGICAL_OR
%left LOGICAL_AND
%left OR
%left XOR
%left AND
%left EQ NE
%left GT LT GE LE
%left SHIFT_LEFT SHIFT_RIGHT
%left PLUS MINUS
%left TIMES DIVIDE MOD
%right NOT LOGICAL_NOT
%left  PLUS2 MINUS2

%%

program
: statements {root = new TreeNode(0, NODE_PROG); root->addChild($1);};


T
: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_DOUBLE {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_DOUBLE;}
| T_VOID {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_VOID;}
| T_INT TIMES {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_POINT;}
| T_INT AND {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_CITE;}
| T_CHAR TIMES {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_POINT;}
| T_CHAR AND {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_CITE;}
| T_BOOL TIMES {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_POINT;}
| T_BOOL AND {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_CITE;}
| T_DOUBLE TIMES {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_POINT;}
| T_DOUBLE AND {$$ = new TreeNode(lineno,NODE_TYPE); $$->type = TYPE_CITE;}
;

constant
: INTEGER {$$=$1;}
| NUMBER {$$=$1;}
| CHAR {$$=$1;}
| STRING {$$=$1;}
| MINSINT {$$=$1;}
| MINSNUM {$$=$1;}
;

MINSINT
: MINUS INTEGER {
    TreeNode* node = new TreeNode($2->lineno,NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = $2->int_val;
    node->optype = OP_MINUS;
    $$=node;
}

MINSNUM
: MINUS NUMBER {
    TreeNode* node = new TreeNode($2->lineno,NODE_CONST);
    node->type = TYPE_DOUBLE;
    node->d_val = $2->d_val;
    node->optype = OP_MINUS;
    $$ = node;
}

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
| LB statements RB {$$=$2;}
;



statement
: declstmt{$$=$1;}
| selectstmt{$$=$1;}
| iterationstmt{$$=$1;}
| jumpstmt {$$=$1;}
| inputstmt{$$=$1;}
| printstmt{$$=$1;}
| exprstmt{$$=$1;}
| mainstmt{$$=$1;}
;

mainstmt
: T MAIN LP RP statements {
    $2->addChild($1);
    $2->addChild($5);
    $$=$2;
}
;

inputstmt
: SCANF LP func_call_idlist RP SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = INPUT_STMT;
    node->addChild($3);
    $$ = node;
}
;

printstmt
: PRINTF LP func_call_idlist RP SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = PRINT_STMT;
    node->addChild($3);
    $$ = node;
}
;

func_call_idlist 
: func_call_id {$$=$1;}
| func_call_id COMMA func_call_idlist {
    $1->addSibling($3);
    $$=$1;
}

func_call_id 
: expression {$$=$1;}
| constant {$$=$1;}
| AND IDENTIFIER {
    TreeNode* node = new TreeNode($2->lineno,NODE_CONST);
    node->type = TYPE_CITE;
    node->addChild($2);
    $$=node;
}
| TIMES IDENTIFIER {
    TreeNode* node = new TreeNode($2->lineno,NODE_VAR);
    node->type = TYPE_POINT;
    node->addChild($2);
    $$ = node;
}
;


declstmt
: var_declstmt{$$=$1;}
  /*fun_declstmt*/
;

var_declstmt
: T decl_list SEMICOLON
{
    TreeNode* node  = new TreeNode($2->lineno,NODE_STMT);
    node->stype = DECL_STMT;
    node->addChild($1);
    node->addChild($2);
    $$ = node;
}
;
decl_list
: decl{$$=$1;}
| decl_list COMMA decl
{
    $1->addSibling($3);
    $$=$1;
}
;

decl
: IDENTIFIER {$$ = $1;}
| IDENTIFIER ASSIGN assignment_expression{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype = OP_ASSIGN;
    node->etype = ASSIGN_EXPR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}


primary_expression
: IDENTIFIER{$$=$1;}
| LP expression RP {$$=$2;}
;

postfix_expression
: primary_expression {$$=$1;}
| postfix_expression PLUS2 {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = POSTFIX_EXPR;
    node->optype = OP_PLUS2;
    node->addChild($1);
    $$=node;
}
| postfix_expression MINUS2 {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = POSTFIX_EXPR;
    node->optype = OP_MINUS2;
    node->addChild($1);
    $$ = node;
}
;

unary_expression
: postfix_expression {$$=$1;}
| PLUS2 unary_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = UNARY_EXPR;
    node->optype = OP_PLUS2;
    node->addChild($2);
    $$ = node;
}
| MINUS2 unary_expression {
    TreeNode* node =new TreeNode($1->lineno,NODE_EXPR);
    node->optype = OP_MINUS2;
    node->etype = UNARY_EXPR;
    node->addChild($2);
    $$ = node ;
}
| MINUS unary_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = UNARY_EXPR;
    node->optype = OP_MINUS;
    node->addChild($2);
    $$ = node;
}
| NOT unary_expression {
    TreeNode* node =new TreeNode($1->lineno,NODE_EXPR);
    node->etype = UNARY_EXPR;
    node->optype = OP_NOT;
    node->addChild($2);
    $$ = node;
}
| LOGICAL_NOT unary_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = UNARY_EXPR;
    node->optype = OP_LOGICAL_NOT;
    node->addChild($2);
    $$ = node;
}
;

cast_expression 
: unary_expression {$$=$1;}
| constant {$$=$1;}
| LP T RP cast_expression {
    TreeNode* node = new TreeNode($2->lineno,NODE_EXPR);
    node->etype = CAST_EXPR;
    node->addChild($2);
    node->addChild($4);
    $$ = node;
}
;


multi_expression 
: cast_expression {$$=$1;}
| multi_expression TIMES cast_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = MULTI_EXPR;
    node->optype = OP_TIMES;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| multi_expression DIVIDE cast_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = MULTI_EXPR;
    node->optype = OP_DIVIDE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| multi_expression MOD cast_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = MULTI_EXPR;
    node->optype = OP_MOD;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

addi_expression
: multi_expression {$$ =$1;}
| addi_expression PLUS multi_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ADDI_EXPR;
    node->optype = OP_PLUS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| addi_expression MINUS multi_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ADDI_EXPR;
    node->optype = OP_MINUS;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

shift_expression 
: addi_expression {$$=$1;}
| shift_expression SHIFT_LEFT addi_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = SHIFT_EXPR;
    node->optype = OP_LSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| shift_expression SHIFT_RIGHT addi_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype =SHIFT_EXPR;
    node->optype = OP_RSHIFT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

relation_expression
: shift_expression{$$=$1;}
| relation_expression LT shift_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = RELATION_EXPR;
    node->optype = OP_LT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| relation_expression GT shift_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = RELATION_EXPR;
    node->optype = OP_GT;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| relation_expression LE shift_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = RELATION_EXPR;
    node->optype = OP_LE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| relation_expression GE shift_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = RELATION_EXPR;
    node->optype = OP_GE;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

equality_expression 
: relation_expression {$$=$1;}
| equality_expression EQ relation_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = EQUA_EXPR;
    node->optype = OP_EQ;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| equality_expression NE relation_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->optype = OP_NE;
    node->etype = EQUA_EXPR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

bit_and_expression 
: equality_expression {$$=$1;}
| bit_and_expression AND equality_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = AND_EXPR;
    node->optype = OP_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

bit_xor_expression
: bit_and_expression {$$=$1;}
| bit_xor_expression XOR bit_and_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = XOR_EXPR;
    node->optype = OP_XOR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;
 
bit_or_expression 
: bit_xor_expression {$$=$1;}
| bit_or_expression OR bit_xor_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = OR_EXPR;
    node->optype = OP_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

log_and_expression 
: bit_or_expression {$$=$1;}
| log_and_expression LOGICAL_AND bit_or_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = LOG_AND_EXPR;
    node->optype = OP_LOGICAL_AND;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

log_or_expression
: log_and_expression {$$=$1;}
| log_or_expression LOGICAL_OR log_and_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = LOG_OR_EXPR;
    node->optype = OP_LOGICAL_OR;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}

conditional_expression
: log_or_expression {$$=$1;}
| conditional_expression QMARK expression COLON conditional_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = CONDI_EXPR;
    node->addChild($1);
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
;

assignment_expression 
: conditional_expression{$$=$1;}
| unary_expression  ASSIGN assignment_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_ASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| unary_expression PLUS_ASSIGN assignment_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_PLUSASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| unary_expression MIN_ASSIGN assignment_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_MINUSASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| unary_expression DIV_ASSIGN assignment_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_DIVIDEASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| unary_expression TIM_ASSIGN assignment_expression {
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_TIMEASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| unary_expression MOD_ASSIGN assignment_expression{
    TreeNode* node = new TreeNode($1->lineno,NODE_EXPR);
    node->etype = ASSIGN_EXPR;
    node->optype = OP_MODASSIGN;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;
expression 
: assignment_expression {$$=$1;}
| expression COMMA assignment_expression {
    $1->addSibling($3);
    $$=$1;
}
;


exprstmt
: SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = EXPR_STMT;
    $$ = node;
}
| expression SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = EXPR_STMT;
    node->addChild($1);
    $$ = node;
}
;


selectstmt
: IF LP expression RP statements ELSE statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = SELECT_STMT;
    node->seltype = _IF_ELSE;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    $$ = node;
}
| IF LP expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = SELECT_STMT;
    node->seltype = _IF;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
;


iterationstmt
: WHILE LP expression RP statements {
    TreeNode* node = new TreeNode ($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _WHILE;
    node->addChild($3);
    node->addChild($5);
    $$ = node;
}
| DO statements WHILE LP expression RP SEMICOLON{
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _DO_WHILE;
    node->addChild($2);
    node->addChild($5);
    $$ = node;
}
| FOR LP expression SEMICOLON expression SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($7);
    node->addChild($9);
    $$ = node;
}
| FOR LP expression SEMICOLON expression SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($5);
    node->addChild($8);
    $$ = node;
}
| FOR LP expression SEMICOLON SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($6);
    node->addChild($8);
    $$ = node;
}
| FOR LP SEMICOLON expression SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($4);
    node->addChild($6);
    node->addChild($8);
    $$ = node;
}
| FOR LP expression SEMICOLON SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($7);
    $$ = node;
}
| FOR LP SEMICOLON expression SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($4);
    node->addChild($7);
    $$ = node; 
}
| FOR LP SEMICOLON SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($5);
    node->addChild($7);
    $$ = node;
}
| FOR LP SEMICOLON SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($6);
    $$ = node;
}
| FOR LP var_declstmt expression SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($6);
    node->addChild($8);
    $$ = node;
}
| FOR LP var_declstmt expression SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($4);
    node->addChild($7);
    $$ = node;
}
| FOR LP var_declstmt SEMICOLON expression RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
     node->addChild($3);
     node->addChild($5);
     node->addChild($7);
     $$ = node;
}
| FOR LP var_declstmt SEMICOLON RP statements {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = ITERATION_STMT;
    node->itype = _FOR;
    node->addChild($3);
    node->addChild($6);
    $$ = node;
}
;

jumpstmt 
: CONTINUE SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = JUMP_STMT;
    $$ = node;
}
| BREAK SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno,NODE_STMT);
    node->stype = JUMP_STMT;
    $$ = node;
}
;



%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}