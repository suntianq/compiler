%{
    #include "common.h"
    #define YYSTYPE Node *  
    extern tree parse_tree;
    symtable symtbl;
    extern int lineno;
    int yylex();
    int yyerror( char const * );
    int str_count=0;
    int chr_count=0;
%}
%token	INCLUDE	 INT BOOL TRUE FALSE CHAR FLOAT DOUBLE LONG SHORT VOID MAIN THIS DEFAULT USING
%token	IF ELSE	SWITCH CASE	FOR	WHILE BREAK CONTINUE DO GOTO RETURN
%token	CLASS STRUCT CONST STRING SCANF	PRINTF
%token	MOD	INC DEC ADD SUB MUL DIV OPAND OPOR POWER OPNOT SHIFTL SHIFTR 
%token	LPAREN	RPAREN	LBRACKET RBRACKET LBRACE RBRACE	
%token	GT LT EQ EQUAL NEQUAL GE LE	OR	AND	NOT BIT_AND BIT_OR AEQ SEQ
%token	SQUOTE DQUOTE	COLON SEMICOLON	COMMA
%token	CONSTCHAR CONSTSTRING	ID	INTNUMBER	

%right EQ AEQ SEQ
%left OR
%left AND
%left OPOR
%left POWER
%left OPAND
%left EQUAL NEQUAL
%left GT LT  GE LE	
%left SHIFTL SHIFTR

%left ADD SUB
%left MUL DIV MOD 

%right NOT
%right INC DEC
%right UMINUS




%%

program
:   INT MAIN LPAREN RPAREN compound_stmt
{
    $$=new Node;
    $$=$5;
    parse_tree.root=$$;
    $$->type_check();
}
|       VOID MAIN LPAREN RPAREN compound_stmt
{
    $$=new Node;
    $$=$5;
    parse_tree.root=$$;
    $$->type_check();
}
;


compound_stmt
:  LBRACE stmt_list RBRACE 
{   
    $$=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype,$2);
}
|   LBRACE stmt_list RETURN expression SEMICOLON RBRACE 
{
    $$=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype,$2);
}
|   LBRACE RBRACE 
{
    $$=parse_tree.NewRoot(STMT_NODE,COMP_STMT,NodeAttr(),Notype);
};


stmt_list
:  stmt_list stmt
{
    Node* s = $1;
    if(s!=NULL){
        while(s->sibling !=NULL)
            s=s->sibling;
        s->sibling = $2;
        $$=$1;
    }
    else 
        $$=$2;
}
|   stmt {$$=$1;};


stmt
:       expr_stmt       {$$=$1;}
|       declaration     {$$=$1;}
|	    if_stmt			{$$ = $1;}
|       while_stmt		{$$ = $1;}
|       for_stmt		{$$ = $1;}
|       printf_stmt		{$$ = $1;}
|       scanf_stmt		{$$ = $1;}
|       ret_stmt        {$$=$1;}
;

declaration
:       var_declaration		{$$=$1;}
|       const_declaration {$$=$1;}
;

var_declaration
:  type idlist SEMICOLON {
                    Node *p;
					$$=parse_tree.NewRoot(DECL_NODE,VAR_DECL,NodeAttr(),Notype,$1,$2);
				    for (p = $2;p;p=p->sibling){
					    p->type = $1->type;
			    }
};

const_declaration
:   CONST type idlist SEMICOLON	 {
        Node *p;
		$$=parse_tree.NewRoot(DECL_NODE,CONST_DECL,NodeAttr(),Notype,$2,$3);
		for (p = $3;p;p=p->sibling){
		    p->type = $2->type;
}					
};

type
:		    INT				    {$$=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Integer);}
|           CHAR				{$$=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Char);}
|           BOOL				{$$=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Boolean);}
|           FLOAT				{$$=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),Float);}
|           STRING				{$$=parse_tree.NewRoot(EXPR_NODE,TYPE_EXPR,NodeAttr(),String);}
;


idlist 
:   idlist 	COMMA id_or_assign
{
    Node* s =$1;
    if(s!=NULL){
        while (s->sibling!=NULL)
		    s=s->sibling;
		s->sibling = $3;
		$$ = $1;
    }
    else 
	    $$ = $3;
}
|   id_or_assign        {$$=$1;}
;

id_or_assign    
:   id {$$=$1;}
| assign_expr   {$$=$1;}
;

id
:   ID
{
    $$=parse_tree.NewRoot(EXPR_NODE,ID_EXPR,NodeAttr(),Notype);
    $$->attr.val.vals=$1->attr.val.vals;
    $$->name=$1->name;
}
;


expr_stmt
:	expression	SEMICOLON {$$=$1;}	
;

if_stmt
:	    IF 	LPAREN	expression	RPAREN	stmt 
		    {$$ = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, $3,$5);}
|       IF LPAREN expression RPAREN stmt ELSE stmt
            {$$ = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype,$3,$5,$7);}
|	    IF LPAREN expression RPAREN compound_stmt	
			{$$ = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, $3,$5);}
|	    IF LPAREN expression RPAREN compound_stmt ELSE compound_stmt
			{$$ = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, $3,$5,$7);}
|       IF LPAREN expression RPAREN compound_stmt ELSE if_stmt
            {$$ = parse_tree.NewRoot(STMT_NODE,IF_STMT,NodeAttr(),Notype, $3,$5,$7);}
;

while_stmt      
:       WHILE LPAREN expression RPAREN compound_stmt
            {  $$ = parse_tree.NewRoot(STMT_NODE,WHILE_STMT,NodeAttr(),Notype,$3,$5);}
;

for_stmt
:		FOR LPAREN expression SEMICOLON expression SEMICOLON  expression  RPAREN compound_stmt
            {  $$ = parse_tree.NewRoot(STMT_NODE,FOR_STMT,NodeAttr(),Notype,$3,$5,$7,$9);}
|       FOR LPAREN var_declaration expression SEMICOLON  expression  RPAREN compound_stmt
            {  $$ = parse_tree.NewRoot(STMT_NODE,FOR_STMT,NodeAttr(),Notype,$3,$4,$6,$8);}
;

scanf_stmt
:   SCANF LPAREN func_call_idlist RPAREN SEMICOLON  {
    $$ = parse_tree.NewRoot(STMT_NODE,SCANF_STMT,NodeAttr(),Notype,$3);
}
;

printf_stmt
:   PRINTF LPAREN func_call_idlist RPAREN SEMICOLON {
    $$ = parse_tree.NewRoot(STMT_NODE,PRINTF_STMT,NodeAttr(),Notype,$3);
}
;

ret_stmt
:   RETURN expression SEMICOLON {
    $$ = parse_tree.NewRoot(STMT_NODE,RET_STMT,NodeAttr(),Notype,$2);
}

func_call_idlist
:   func_call_id    {$$=$1;}
|   func_call_idlist COMMA func_call_id {
        Node* p=$1;
        if(p!=NULL){
            while(p->sibling!=NULL)
                p=p->sibling;
            p->sibling=$3;
            $$=$1;
        }
        else 
            $$=$3;
}
;

func_call_id
:   expression  {$$=$1;}
|   factor    {$$=$1;}
|   conststring {$$=$1;}
|   AND ID  {
    $$=parse_tree.NewRoot(STMT_NODE,ID_EXPR,NodeAttr(),Reference,$2);
}
;

conststring
:  CONSTSTRING  {
    $$ = parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),String);
	$$->attr.val.vals=$1->attr.val.vals;
    $$->str_seq=str_count++;
}



expression
:       assign_expr {$$=$1;}	
|       not_expression{$$=$1;}
;


assign_expr	:	id	EQ	expression
				{$$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_ASSIGN),Notype,$1,$3);}
|               id  AEQ expression
                {$$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_AEQ),Notype,$1,$3);}
|               id SEQ expression
                {$$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_SEQ),Notype,$1,$3);}
|               id EQ assign_expr
                {$$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_ASSIGN),Notype,$1,$3);}
;


not_expression
:	NOT or_expression
		{$$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_NOT),Notype,$2);}
|   or_expression {$$=$1;}  
;

or_expression   
:       or_expression OR and_expression
        {  $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_OR),Notype,$1,$3);}
|       and_expression { $$ = $1; }
;

and_expression  
:       and_expression AND relation_expr
        {  $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LOG_AND),Notype,$1,$3);}
|       relation_expr  { $$ = $1; }
;

relation_expr
:   relation_expr GT op_expr{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(GTR),Notype,$1,$3);} 
|   relation_expr LT op_expr	{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LSS),Notype,$1,$3);} 
|   relation_expr EQUAL op_expr{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(EQU),Notype,$1,$3);} 
|   relation_expr NEQUAL op_expr{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(NEQU),Notype,$1,$3);} 
|   relation_expr GE op_expr{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(GEQ),Notype,$1,$3);} 
|   relation_expr LE op_expr	{ $$ =parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(LEQ),Notype,$1,$3);} 
|   TRUE		{$$=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Boolean);$$->attr.val.valb=true;}
|   FALSE		{$$=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Boolean);$$->attr.val.valb=false;}
|   op_expr	    {$$=$1;}
;

op_expr
:	    id INC			    { $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_INC),Notype,$1);}  //++
|       id DEC				{ $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_DEC),Notype,$1);}  //--
|       op_expr ADD term    { $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_PLUS),Notype,$1,$3);}  //+
|       op_expr SUB term	{ $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MINUS),Notype,$1,$3);}  //-
|       term			    {$$=$1;}
;

			
term
:		term MUL factor { $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MUL),Notype,$1,$3);}  //*
|       term DIV factor { $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_DIV),Notype,$1,$3);}  ///
|       term MOD factor { $$ = parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_MOD),Notype,$1,$3);}  //%
|       factor			{$$=$1;}
;

factor
:   LPAREN expression RPAREN    {$$=$2;}
|   INTNUMBER   {$$=parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Integer);
                    $$->attr.val.vali=$1->attr.val.vali;}
|   id  {$$=$1;}
|   CONSTCHAR   {$$ = parse_tree.NewRoot(EXPR_NODE,CONST_EXPR,NodeAttr(),Char);
					$$->attr.val.valc=$1->attr.val.valc;
                    $$->chr_seq=chr_count++;
                    }
|   BIT_AND id{$$=$2;
                $$->type=Reference;
    }
|   SUB expression %prec UMINUS {   
    			$$=parse_tree.NewRoot(EXPR_NODE,OP_EXPR,NodeAttr(OP_UMINUS),Integer,$2);
                $$->attr.val.vali=-$2->attr.val.vali;
}
;


%%


int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
