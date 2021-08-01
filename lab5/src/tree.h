#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "symbol.h"

enum NodeType
{
    NODE_CONST,   //常量
    NODE_VAR,    //变量
    NODE_EXPR,   //表达式
    NODE_TYPE,   //类型
    NODE_STMT,   //语句
    NODE_MAIN,
    NODE_PROG,   //root结点 程序开始
};
enum OperatorType
{
    OP_EQ,  // ==
    OP_GT,  //>
    OP_LT,  //<
    OP_GE,  //>=
    OP_LE,  //<=
    OP_NE,  //!=
    OP_LOGICAL_AND,  //&&
    OP_LOGICAL_OR,  //||
    OP_LOGICAL_NOT, //!
    OP_PLUS,        //+
    OP_MINUS,       //- 
    OP_TIMES,       //*
    OP_DIVIDE,      // /
    OP_MOD,         //%
    OP_AND,         //&
    OP_OR,          //|
    OP_NOT,         //~
    OP_PLUS2,       //++
    OP_MINUS2,      //--
    OP_LSHIFT,      // <<
    OP_RSHIFT,      // >>
    OP_XOR,        // ^
    OP_QMARK,        //?
    OP_COLON,       //:
    OP_ASSIGN,      //=
    OP_PLUSASSIGN,   //+=
    OP_MINUSASSIGN,  //-=
    OP_TIMEASSIGN,   //*=
    OP_DIVIDEASSIGN, //  /=
    OP_MODASSIGN,    // %=
    OP_LPAREN,      //(
    OP_RPAREN,      //)
    OP_COMMA,       //,
    OP_EXCLA,       //!
};
enum StmtType {
    COMP_STMT,      //复合语句
    EXPR_STMT,      //表达式语句
    SELECT_STMT,    //选择语句  
    ITERATION_STMT, //循环语句
    JUMP_STMT,      //跳转语句
    INPUT_STMT,     //输入
    PRINT_STMT,     //输出
    DECL_STMT,      //声明语句
};
enum ExprType{
    POSTFIX_EXPR,   //后缀表达式
    UNARY_EXPR,     //前缀表达式
    CAST_EXPR,      //强制类型转换
    MULTI_EXPR,     //乘除表达式
    ADDI_EXPR,      //加减表达式
    SHIFT_EXPR,     //移位表达式
    RELATION_EXPR,  //关系运算表达式
    EQUA_EXPR,      //相等运算
    AND_EXPR,       //按位与
    XOR_EXPR,       //按位异或
    OR_EXPR,        //按位或
    LOG_AND_EXPR,   //逻辑与表达式
    LOG_OR_EXPR,    //逻辑或表达式
    CONDI_EXPR,     //三目运算表达式 x==y?2:3
    ASSIGN_EXPR,    //赋值运算表达式
    BLANK_EXPR,     // ; 
};
enum IterationType{
    _WHILE,
    _DO_WHILE,
    _FOR,
};
enum SelectType{
    _IF_ELSE,
    _IF,
};

struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;    //行数
    NodeType nodeType; //节点类型

    TreeNode* child = nullptr;  //孩子结点
    TreeNode* sibling = nullptr; //兄弟结点

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo(TreeNode*);
    void printChildrenId(TreeNode*);

    void printAST(TreeNode*); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo(TreeNode*);

    void genNodeId(TreeNode*);   //获取节点编号，并将其加一

public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    ExprType etype;
    IterationType itype;
    SelectType seltype;
    int int_val;
    char ch_val;
    bool b_val;
    double d_val;
    string str_val;
    string var_name;
public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);
    static string eType2String (ExprType type);

public:
    TreeNode(int lineno, NodeType type);
};



#endif