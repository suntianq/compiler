#ifndef TREE_H
#define TREE_H

#include "pch.h"
#define MAX_ID 1024
#define VAR 0//变量的token
#define CVAR 1//常量的token
using namespace std;
enum Node_kind
{
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE
};

enum Stmt_kind
{
	WHILE_STMT = 0,
	PRINTF_STMT,
	SCANF_STMT,
	COMP_STMT,
	IF_STMT,
	FOR_STMT,
	START_STMT,
	RET_STMT,
};

enum Expr_kind
{
	TYPE_EXPR = 0, //单个类型
	OP_EXPR,
    CONST_EXPR,
	ID_EXPR,
};

enum Decl_kind
{
	VAR_DECL = 0,//变量声明
	CONST_DECL,//常量声明
	ARRAY_DECL,//数组
	FUNC_DECL,//函数
	POINT_DECL,//指针
};

enum Data_kind
{
	Notype = 0,
	Integer,
	Boolean,
	Char,
	Float,
	String,
	Reference,
};

enum OP_kind{
	OP_PLUS=1,
	OP_MINUS,
	OP_MUL,
	OP_DIV,
	OP_ASSIGN,OP_INC, OP_DEC, OP_MOD,//= ++ -- %
	OP_AEQ,OP_SEQ,	//+= -=
	OP_UMINUS,	//-
	GTR, GEQ, LSS, LEQ, EQU, NEQU,//比较运算符  ">",">=","<","<=","==","!="
	LOG_OR, LOG_AND, LOG_NOT //逻辑运算符  "||","&&","!"
};

#define MAX_CHILDREN 4

struct Value
{
	int vali;
	char valc;
	char valc1;
	bool valb;
	float valf;
	string vals;
	Value(int a){
		vali=a;
	}
	Value(char a){
		valc=a;
	}
	Value(bool a){
		valb=a;
	}
	Value(float a){
		valf=a;
	}
	Value(string a){
		vals=a;
	}
	Value(){}
};


//节点属性
class NodeAttr {
public:
	int op;
	Value val;
	int symtbl_seq;
	NodeAttr(void) { op = 0; }
	NodeAttr(int i)	{ op = i; }
};

class symbol{
public:
	string name;
	int token;
	int type;
	Value val;
};

struct symtable
{
	symbol table[MAX_ID];
	int size=0;
};

class chrtable{
public:
	string str[MAX_ID];
	char chr[MAX_ID];
	char chr1[MAX_ID];
	int seqchar=0;		//chr的个数
	int seqstr=0;		//str的个数
	int insert(char c);
	int insert(char c1,char c2);
	int insert(string s);
};


struct Label {
	string true_label;
	string false_label;
	string begin_label;
	string next_label;
};

class Node
{
public:
	struct Node *children[MAX_CHILDREN];
	struct Node *sibling;
	int lineno;
	int kind;	//节点类别（声明、表达式、语句）
	int kind_kind; //具体类型
	NodeAttr attr;	//节点属性
	int type; //数据类型
	int seq;
	int temp_var;	//临时变量编号
	int chr_seq=0;	//chr的标号
	int str_seq=0;	//str的标号
	Label label;
	string name;
public:
	Node(){};
	void node_print();
	void output();//打印整颗树
	void type_check();    //类型检查
	void Treetranslation();//语法树翻译
	void exprtrans();//表达式翻译
	void syminsert(Value val,int data_type);
	int symbol_lookup();
	bool search(string name);
	symbol symbol_select();//查找id
	
};

class tree
{
public:
	Node *root;
	int node_seq = 0;

	int temp_var_seq = 0;
	int label_seq = 0;

	void get_temp_var(Node *t);		//生成临时变量编号
	string new_label(void);			
	void recursive_get_label(Node *t);
	void stmt_get_label(Node *t);
	void expr_get_label(Node *t);
	void gen_decl();
	void gen_str();
	void recursive_gen_code(Node *t);		//递归产生代码
	void stmt_gen_code(Node *t);			//语句产生代码
	void expr_gen_code(Node *t);			//表达式产生代码


	Node *NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
		Node *child1 = NULL, Node *child2 = NULL, Node *child3 = NULL, Node *child4 = NULL);
	void get_label(void);	//设置节点的各种label
	void gen_code();
};

#endif