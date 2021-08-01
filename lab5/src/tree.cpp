#include "tree.h"
static int globalNodeId = 0;

void TreeNode::addChild(TreeNode* child) {
    if(this->child == nullptr)
        this->child = child;
    else{
        this->child->addSibling(child);
    }
}

void TreeNode::addSibling(TreeNode* sibling){
    if(this->sibling == nullptr)
        this->sibling = sibling;
    else{
        TreeNode* tmp = this->sibling;
        while(tmp->sibling!=nullptr)
            tmp = tmp->sibling;
        tmp->sibling = sibling;
    }
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno = lineno;
    this->nodeType = type;
}

void TreeNode::genNodeId(TreeNode* root) {
    root->nodeID = globalNodeId;
    globalNodeId += 1;
    for(TreeNode* t=root->child;t;t=t->sibling)
        genNodeId(t);
}

void TreeNode::printNodeInfo(TreeNode* t) {
    string print_type = "";
    string detail = "";
    string childNodeID = "Children: ";
    if(t->nodeType == NODE_STMT){
        detail = sType2String(t->stype);
    }
    else if(t->nodeType == NODE_EXPR){
        detail = "OP: "+ opType2String(t->optype);
    }
    else if(t->nodeType == NODE_VAR){
        detail = "var name: "+ t->var_name;
    }
    else if(t->nodeType == NODE_TYPE){
        detail = t->type->getTypeInfo();
    }
    else if(t->nodeType == NODE_CONST){
        string t_type_str = t->type->getTypeInfo();
        string t_type_sym = opType2String(t->optype);
        if(t_type_str=="int"){
            if(t_type_sym=="-")
            detail = t_type_sym + to_string(t->int_val);
            else 
            detail = to_string(t->int_val);
        }
        else if(t_type_str=="string"){
            detail=t->str_val;
        }
        else if(t_type_str=="bool"){
            detail=to_string(t->b_val);
        }
        else if(t_type_str=="double"){
             if(t_type_sym=="-")
            detail = t_type_sym + to_string(t->d_val);
            else 
            detail = to_string(t->d_val);
        }
        else if(t_type_str=="char"){
            detail=to_string(t->ch_val);
        }
        else if(t_type_str=="getsite"){
            detail="&";
        }
        else if(t_type_str=="pointer"){
            detail="pointer";
        }
        detail=t_type_str+": "+detail;
    }
    print_type = nodeType2String(t->nodeType);
    cout<<"line"<<setw(3)<<t->lineno<<"   ";
    cout<<"@"<<setw(4)<<setiosflags(ios::left)<<t->nodeID;
    cout<<setw(15)<<setiosflags(ios::left)<<print_type;
    cout<<setw(25)<<setiosflags(ios::left)<<detail;
    printSpecialInfo(t);
    printChildrenId(t);
}

void TreeNode::printChildrenId(TreeNode *t) {
    cout<<" children:[";
    if(t->child!=nullptr){
        cout<<"@"<<t->child->nodeID<<" ";
        TreeNode*tmp = t->child->sibling;
        while(tmp!=nullptr){
            cout<<"@"<<tmp->nodeID<<" ";
            tmp=tmp->sibling;
        }
    }
    cout<<"]"<<endl;
}

void TreeNode::printAST(TreeNode* root) {
    if(!root)
        return;
    printNodeInfo(root);
    for(TreeNode* t=root->child;t;t=t->sibling)
        printAST(t);
}


// You can output more info...
void TreeNode::printSpecialInfo(TreeNode*t) {
    switch (t->stype)
    {
    case ITERATION_STMT:{
        if(t->itype==_FOR)
            cout<<setw(10)<<"for";
        else if(t->itype==_DO_WHILE)
            cout<<setw(10)<<"do_while";
        else if(t->itype==_WHILE)
            cout<<setw(10)<<"while";
        break;
    }
    case SELECT_STMT:{
        if(t->seltype==_IF)
            cout<<setw(10)<<"if";
        else if(t->seltype==_IF_ELSE)
            cout<<setw(10)<<"ifelse";
        break;
    }
    default:
        cout<<setw(10)<<" ";
        break;
    }
}

string TreeNode::sType2String(StmtType type) {
    switch (type)
    {
    case COMP_STMT:
        return "compand_stmt";
    case EXPR_STMT:
        return "expression_stmt";
    case SELECT_STMT:
        return "select_stmt";
    case ITERATION_STMT:
        return "iteration_stmt";
    case JUMP_STMT:
        return "jump_stmt";
    case INPUT_STMT:
        return "input_stmt";
    case PRINT_STMT:
        return "print_stmt";
    case DECL_STMT:
        return "declare_stmt";
    default:
        return "unknown statment type";
        break;
    }
}


string TreeNode::nodeType2String (NodeType type){
    switch (type)
    {
    case NODE_STMT:
        return "statement";
     case NODE_EXPR:
        return "expression";
    case NODE_PROG:
        return "program";
    case NODE_TYPE:
        return "type";
    case NODE_VAR:
        return "value";
    case NODE_CONST:
        return "const";
    case NODE_MAIN:
        return "main";
    default:
        return "unknown node type";
        break;
    }
}
string TreeNode::eType2String(ExprType type){
    switch (type){
        case POSTFIX_EXPR:
            return "postfix_expr";
        case UNARY_EXPR:
            return "unary_expr";
        case CAST_EXPR:
            return "cast_expr";
        case MULTI_EXPR:
            return "multi_expr";
        case ADDI_EXPR:
            return "addi_expr";
        case SHIFT_EXPR:
            return "shift_expr";
        case RELATION_EXPR:
            return "relation_expr";
        case EQUA_EXPR:
            return "equation_expr";
        case AND_EXPR:
            return "and_expr";
        case XOR_EXPR:
            return "xor_expr";
        case OR_EXPR:
            return "or_expr";
        case LOG_AND_EXPR:
            return "log_and_expr";
        case LOG_OR_EXPR:
            return "log_or_expr";
        case CONDI_EXPR:
            return "condition_expr";
        case ASSIGN_EXPR:
            return "assign_expr";
        case BLANK_EXPR:
            return "blank_expr";
        default:
            return "unknown Expression type";
        break;
    }
   
}

string TreeNode::opType2String(OperatorType type){
    switch (type)
    {
    case OP_EQ:
        return "==";
    case OP_PLUS:
        return "+";
      case OP_MINUS:
        return "-";
    case OP_TIMES:
        return "*";
    case OP_DIVIDE:
        return "/";
    case OP_MOD:
        return "%";
    case OP_AND:
        return "&";
    case OP_OR:
        return "|";
    case OP_NOT:
        return "~";
    case OP_PLUS2:
        return "++";
    case OP_MINUS2:
        return "--";
    case OP_NE: 
        return "!=";
    case OP_GT:
        return ">";
    case OP_LT:
        return "<";
    case OP_GE:
        return ">=";
    case OP_LE:
        return "<=";
    case OP_LOGICAL_NOT:
        return "!";
    case OP_LOGICAL_AND:
        return "&&";
    case OP_LOGICAL_OR:
        return "||";
    case OP_LSHIFT:
        return "<<";
    case OP_RSHIFT:
        return ">>";
    case OP_XOR:
        return "^";
    case OP_QMARK:
        return "?";
    case OP_COLON:
        return ":";
    case OP_ASSIGN:
        return "=";
    case OP_PLUSASSIGN:
        return "+=";
    case OP_MINUSASSIGN:
        return "-=";
    case OP_TIMEASSIGN:
        return "*=";
    case OP_DIVIDEASSIGN:
        return "/=";
    case OP_MODASSIGN:
        return "%=";
    case OP_LPAREN:
        return "(";
    case OP_RPAREN:
        return ")";
    case OP_COMMA:
        return ",";
    case OP_EXCLA:
        return "!";
    default:
        return "unknown op type";
        break;
    }
}


