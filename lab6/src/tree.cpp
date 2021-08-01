#include "tree.h"

extern int lineno;
extern symtable symtbl;
extern chrtable ct;

tree parse_tree;

void Node::node_print(){
    cout.setf(ios_base::left);//左对齐
	cout.width(4);
	cout << seq << ":";//输出节点编号
    switch(kind){
        case STMT_NODE:{
            string name[] = {"while","printf","scanf","compound","if", "for"};//语句的类型
			cout.width(30);
			cout << name[kind_kind] + " statement";
			cout.width(15);
			cout << " ";
			break;
        }
        case EXPR_NODE:{
            string name[] = { "Type Specifier","Expr", "Const Declaration","ID Declaration"};//表达式的种类
			string t[] = { "notype","integer", "boolean","char", "float","string","reference" };//表达式的类型
			string opname[] = { " ", "+", "-", "*", "/", "=", "++", "--", "%", "&","|","~","^","<<",">>",">", ">=", "<", "<=", "==","!=", "||", "&&", "!" };//运算符的种类
			cout.width(30);
			cout << name[kind_kind];
            switch(kind_kind){
                case TYPE_EXPR: {
                    cout.width(15);
					cout << t[type];
					break; 
                }
                case OP_EXPR:{//运算符
					cout.width(15);
					cout << "op:" + opname[attr.op];
					break; 
				}
                case CONST_EXPR:{//常数表达式
					cout.width(10);
					cout << "value:";
					cout.width(5);
					switch (type)//常量的类型
					{
					case Integer:
						cout << attr.val.vali;
						break;
					case Char:
						cout << attr.val.valc;
						break;
					case Boolean:
						cout << attr.val.valb;
						break;
					case Notype:
						break;
					case Float:
						cout << attr.val.valf;
						break;
					case String:
						cout << attr.val.vals;
						break;
					default:
						break;
					}
				break;
                    }
                case ID_EXPR:   {//id表达式
				cout.width(10);
				cout << "symbol:";
				cout.width(5);
				cout << attr.val.vals;
				break; }

        }
        break;
        }
        case DECL_NODE: {
            cout.width(30);
			cout << "Var Declaration";
			cout.width(15);
			cout << "    ";
			break; 
        }
    }

    cout<<"Children: ";

    for (int i = 0; i < MAX_CHILDREN; i++)
	{
		if (children[i] == NULL)
		{
			if(i==0||i==1)
				cout<<"\t\t";
			if(i==2||i==3)
				cout<<"\t";			
			break;
		}	
		else
		{
			cout << children[i]->seq << " ";
			for (Node* sp = children[i]->sibling; sp; sp = sp->sibling)  //兄弟节点
				cout << sp->seq << " ";
		}
	}

    cout<<"\tLabel: ";
    if (label.true_label != "")
	{
		cout.width(15);
		cout<<"true_label:";
		cout.width(15);
		cout<<label.true_label;
	}
		
	if (label.false_label != "")
	{
		cout.width(15);
		cout<<"false_label:";
		cout.width(15);
		cout<<label.false_label;
	}
	
	if (label.begin_label != "")
	{
		cout.width(15);
		cout<<"begin_label:";
		cout.width(15);
		cout<<label.begin_label;
	}
	
	if (label.next_label != "")
	{
		cout.width(15);
		cout<<"next_label:";
		cout.width(15);
		cout<<label.next_label;
	}	

    cout<<endl;

}

void Node::output(){
    for (int i=0; i<MAX_CHILDREN; i++){
        if (children[i] == NULL)
			break;
        children[i]->output();
        for (Node* sp = children[i]->sibling; sp!=NULL; sp = sp->sibling)
		{
			sp->output();
		}
    }
    node_print();
}

void Node::type_check() {
    if(kind==STMT_NODE){
        if(kind_kind==IF_STMT){
           children[0]->type_check();
           children[1]->type_check();
        }
        else if(kind_kind==WHILE_STMT){
            children[0]->type_check();
            children[1]->type_check();
        }
        else if(kind_kind==FOR_STMT){
            children[0]->type_check();
            children[1]->type_check();
            children[3]->type_check();
            children[2]->type_check();
        }
        else if(kind_kind==COMP_STMT){
            for(int i=0;children[i]!=NULL&&i<MAX_CHILDREN;i++){
                children[i]->type_check();
                for(Node* s=children[i]->sibling;s;s=s->sibling)
                    s->type_check();
            }
            Treetranslation();
        }
    }
    else if(kind==DECL_NODE){
        int location;
        if(kind_kind==VAR_DECL){
            Node* n=children[1];
            if(search(n->attr.val.vals)){
                cout<<"在第"<<lineno<<"行重定义了变量"<<name<<endl;
            }
            while(n!=NULL){
                if(n->attr.op==OP_ASSIGN){
                    location=n->children[0]->symbol_lookup();
                    symtbl.table[location].type=n->type;
                    n->attr.symtbl_seq=location;
                    symtbl.table[location].token=VAR;
                    n->type_check();
                    n=n->sibling;
                    continue;
                }
                location=n->symbol_lookup();
                symtbl.table[location].type=n->type;
                n->attr.symtbl_seq=location;
                symtbl.table[location].token=VAR;
                n=n->sibling;
            

            }
        }
        else if(kind_kind==CONST_DECL){
            Node* n=children[1];
            while(n!=NULL){
                if(n->attr.op==OP_ASSIGN){
                    location=n->children[0]->symbol_lookup();
                    symtbl.table[location].type=n->type;
                    n->attr.symtbl_seq=location;
                    symtbl.table[location].token=CVAR;
                    n->type_check();
                    n=n->sibling;
                    continue;
                }
                    location=n->symbol_lookup();
                    symtbl.table[location].type=n->type;
                    n->attr.symtbl_seq=location;
                    symtbl.table[location].token=CVAR;
                    n=n->sibling;
            }
        }
    }

    else {
        for(int i=0;i<MAX_CHILDREN&&children[i]!=NULL;i++){
            children[i]->type_check();
            for(Node*s=children[i]->sibling;s;s=s->sibling)
                s->type_check();
        }
        Treetranslation();  //表达式的翻译检查
    }
}

void Node::Treetranslation(){
    if(kind==EXPR_NODE){
        if(kind_kind==OP_EXPR){
            //赋值
            if(attr.op==OP_ASSIGN){
                symbol s=children[0]->symbol_select();
                //a=1
                if(children[1]->kind_kind==CONST_EXPR){
                    if(s.type!=children[1]->type){
                        cout<<"第"<<lineno<<"行："<< s.name<<"与右值类型不符，无法赋值" << endl;
						  
                    }
                    children[0]->syminsert(children[1]->attr.val,children[1]->type);
                }
                //a=b
                else if(children[1]->kind_kind==ID_EXPR){
                    symbol ss=children[1]->symbol_select();
                    if(s.type!=ss.type){
                        cout <<"第"<<lineno<<"行：" <<"变量"<< s.name<<"与变量"<< ss.name<<"类型不符，无法赋值" << endl;
						  
                    }
                    children[0]->syminsert(children[1]->attr.val,children[1]->type);
                }
            }
            //加法运算
            else if(attr.op==OP_PLUS){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer){
                        cout<<"第"<<lineno<<"行："<<"+ 左运算数"<< l.name <<"变量类型错误"<<endl;
						  
                    }
                    temp1=l.val.vali;
                }

                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
						{
							cout<<"第"<<lineno<<"行："<<"+ 左运算数"<< "常量类型错误"<<endl;
							  
						}
						temp1 = children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
						{
							cout<<"第"<<lineno<<"行："<<"+ 右运算数"<< rr.name <<"变量类型错误"<<endl;
						}
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer){
                        cout<<"第"<<lineno<<"行："<<"+ 右运算数"<< "常量类型错误"<<endl;
						  
                    }
                    temp2 = children[1]->attr.val.vali;
                }
                type=Integer;
            }
            //减法
            else if(attr.op==OP_MINUS){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer){
                        cout<<"第"<<lineno<<"行："<<"- 左运算数"<< l.name <<"变量类型错误"<<endl;
						  
                    }
                    temp1=l.val.vali;
                }
                else if( children[0]->kind_kind == CONST_EXPR || children[0]->kind_kind==OP_EXPR ){
                    if (children[0]->type != Integer)
						{
							cout<<"第"<<lineno<<"行："<<"- 左运算数"<< "常量类型错误"<<endl;
							  
						}
						temp1 = children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
							cout<<"第"<<lineno<<"行："<<"- 右运算数"<< rr.name <<"变量类型错误"<<endl;
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"- 右运算数"<< "常量类型错误"<<endl;
                    temp2 = children[1]->attr.val.vali;
                }
                type=Integer;
            }
            //乘法运算
            else if(attr.op==OP_MUL){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"* 左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }

                else if( children[0]->kind_kind == CONST_EXPR || children[0]->kind_kind==OP_EXPR ){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"* 左运算数"<< "常量类型错误"<<endl;
						temp1 = children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
						cout<<"第"<<lineno<<"行："<<"* 右运算数"<< rr.name <<"变量类型错误"<<endl;
                    temp2 = rr.val.vali;
                }

                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"* 右运算数"<< "常量类型错误"<<endl;
                    temp2 = children[1]->attr.val.vali;
                }
                type=Integer;
            }

            //除法运算
            else if(attr.op==OP_DIV){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"/ 左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }

                else if( children[0]->kind_kind == CONST_EXPR || children[0]->kind_kind==OP_EXPR ){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"/ 左运算数"<< "常量类型错误"<<endl;
						temp1 = children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
							cout<<"第"<<lineno<<"行："<<"/ 右运算数"<< rr.name <<"变量类型错误"<<endl;
                    temp2 = rr.val.vali;
                }

                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"/ 右运算数"<< "常量类型错误"<<endl;
                    temp2 = children[1]->attr.val.vali;
                }
                type=Integer;
            }
            //取模运算
            else if(attr.op==OP_MOD){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"% 左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }

                else if( children[0]->kind_kind == CONST_EXPR || children[0]->kind_kind==OP_EXPR ){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"% 左运算数"<< "常量类型错误"<<endl;
						temp1 = children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
						cout<<"第"<<lineno<<"行："<<"% 右运算数"<< rr.name <<"变量类型错误"<<endl;
                    temp2 = rr.val.vali;
                }

                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"% 右运算数"<< "常量类型错误"<<endl;
						  
                    temp2 = children[1]->attr.val.vali;
                }
                type=Integer;
            }

            //++运算
            else if(attr.op==OP_INC){
                int temp1;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"++运算"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                    type=Integer;
                    attr.val.vali=temp1+1;
                    children[0]->syminsert(Value(temp1+1),Integer);
                }
                else {
                    cout<<"第"<<lineno<<"行："<<"++运算对象为常量，运算数类型错误"<<endl;
					  
                }
            }

            //--运算
            else if(attr.op==OP_DEC){
                int temp1;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"--运算"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                    type=Integer;
                    attr.val.vali=temp1-1;
                    children[0]->syminsert(Value(temp1-1),Integer);
                }
                else
                    cout<<"第"<<lineno<<"行："<<"--运算对象为常量，运算数类型错误"<<endl;
            }
     

            //>运算
            else if(attr.op==GTR){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<">左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                     if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<">左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    if (rr.type != Integer)
							cout<<"第"<<lineno<<"行："<<"> 右运算数"<< rr.name <<"变量类型错误"<<endl;
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"> 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1>temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //<运算
            else if(attr.op==LSS){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"<左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"<左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"< 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1<temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //>=运算
            else if(attr.op==GEQ){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<">=左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<">=左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<">= 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1>=temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //<=
            else if(attr.op==LEQ){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"<=左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"<=左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"<= 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1<=temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //==
            else if(attr.op==EQU){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"==左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
							cout<<"第"<<lineno<<"行："<<"==左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"== 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1==temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //!=
            else if(attr.op==NEQU){
                int temp1,temp2;
                if(children[0]->kind_kind==ID_EXPR){
                    symbol l=children[0]->symbol_select();
                    if(l.type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"!=左运算数"<< l.name <<"变量类型错误"<<endl;
                    temp1=l.val.vali;
                }
                else if(children[0]->kind_kind==CONST_EXPR||children[0]->kind_kind==OP_EXPR){
                    if (children[0]->type != Integer)
						cout<<"第"<<lineno<<"行："<<"!=左运算数"<< "常量类型错误"<<endl;
                    temp1=children[0]->attr.val.vali;
                }

                if(children[1]->kind_kind==ID_EXPR){
                    symbol rr=children[1]->symbol_select();
                    temp2 = rr.val.vali;
                }
                else if(children[1]->kind_kind==CONST_EXPR||children[1]->kind_kind==OP_EXPR){
                    if(children[1]->type!=Integer)
                        cout<<"第"<<lineno<<"行："<<"!= 右运算数"<< "常量类型错误"<<endl;
                    temp2=children[1]->attr.val.vali;
                }
                type=Boolean;
                if(temp1!=temp2)
                    attr.val.valb=true;
                else 
                    attr.val.valb=false;
            }

            //||
            else if(attr.op==LOG_OR){
                if(children[0]->type!=Boolean||children[1]->type!=Boolean)
                    cout<<"第"<<lineno<<"行 ||逻辑运算符类型错误"<<endl;
                type=Boolean;
                attr.val.valb=children[0]->attr.val.valb||children[1]->attr.val.valb;
                   
                }
            

            //&&
            else if(attr.op==LOG_AND){
                if(children[0]->type!=Boolean||children[1]->type!=Boolean)
                    cout<<"第"<<lineno<<"行 &&逻辑运算符类型错误"<<endl;
                
                type=Boolean;
                attr.val.valb=children[0]->attr.val.valb&&children[1]->attr.val.valb;
            }
            //!
            else if(attr.op==LOG_NOT){
                bool temp;
                if(children[0]->type!=Boolean)
                    cout<<"第"<<lineno<<"行 !逻辑运算符类型错误"<<endl;
                else {
                    temp=children[0]->attr.val.valb;
                    type=Boolean;
                    if(temp==true)
                        attr.val.valb=false;
                    else 
                        attr.val.valb=true;
                }
            }
        }
        else if(kind_kind==ID_EXPR){
            if(!search(name)){
                cout<<"Uninitialized variable at lineno: "<<lineno<<endl;
            }
        }
    
    }
}

bool Node::search(string id){

    for(int i=0;i<symtbl.size;i++){
        if(symtbl.table[i].name==id)
            return true;
    }
    return false;
}

void Node::syminsert(Value val,int type){
    int location=symbol_lookup();
    symtbl.table[location].val=val;
    symtbl.table[location].type=type;
}


symbol Node::symbol_select(){
    int location=symbol_lookup();
    symbol s=symtbl.table[location];
    return s;
}

int Node::symbol_lookup(){
    const char* s=attr.val.vals.c_str();
    for(int i=0;i<symtbl.size;i++){
        if(symtbl.table[i].name==s)
            return i;
    }
    symtbl.table[symtbl.size].name=s;
    symtbl.size++;
    return symtbl.size-1;
}


int chrtable::insert(char c){
    chr[seqchar]=c;
    seqchar++;
    return seqchar-1;
}
int chrtable::insert(string s){
    str[seqstr]=s;
    seqstr++;
    return seqstr-1;
}
int chrtable::insert(char c1,char c2){
    chr[seqchar]=c1;
    chr1[seqchar]=c2;
    seqchar++;
    return seqchar-1;
}

Node* tree::NewRoot(int kind, int kind_kind, NodeAttr attr, int type,
				   Node *child1, Node *child2, Node *child3, Node *child4)
{
	Node *t = new Node;
	
	if (NULL == t)
		cerr << "Out of memory at line %d\n" << lineno;
	else
	{
		t->kind = kind;
		t->kind_kind = kind_kind;
		t->attr = attr;
		t->type = type;
		t->children[0] = child1;
		t->children[1] = child2;
		t->children[2] = child3;
		t->children[3] = child4;
		t->lineno = lineno;
		t->seq = tree::node_seq++;
		t->sibling = NULL;
		t->label.begin_label = "";
		t->label.next_label = "";
		t->label.true_label = "";
		t->label.false_label = "";
		root = t;
		get_temp_var(t); // generate temp veriables
	}
	return t;
}


string tree::new_label(void)
{
	char tmp[20];

	sprintf(tmp, "label%d", tree::label_seq);
	tree::label_seq++;
	return tmp;
}


void tree::get_label(void)
{
	Node *p = root;

	p->label.begin_label = "_start";
	recursive_get_label(p);
}


void tree::recursive_get_label(Node *t)
{
	if (t->kind == STMT_NODE)
		stmt_get_label(t);
	else if (t->kind == EXPR_NODE)
		expr_get_label(t);
}



void tree::stmt_get_label(Node *t){
	switch (t->kind_kind)
	{
	case COMP_STMT:
		{
			Node *last;
			Node *p;
			for (p = t->children[0]; p->kind == DECL_NODE; p = p->sibling) ;

			p->label.begin_label = t->label.begin_label;
			for (; p; p = p->sibling)
			{
				last = p;
				recursive_get_label(p);
			}

			t->label.next_label = last->label.next_label;
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;
		}
		break;

	case WHILE_STMT:
		{
			Node *e = t->children[0];
			Node *s = t->children[1];

			if (t->label.begin_label == "")
				t->label.begin_label = new_label();
			s->label.next_label = t->label.begin_label;

			s->label.begin_label = e->label.true_label = new_label();

			if (t->label.next_label == "")
				t->label.next_label = new_label();
			e->label.false_label = t->label.next_label;
			if (t->sibling)
				t->sibling->label.begin_label = t->label.next_label;

			recursive_get_label(e);
			recursive_get_label(s);
		}
		break;
	case FOR_STMT:
		{
			Node*e1=t->children[0];
			Node*e2=t->children[1];
			Node*e3=t->children[2];
			Node*s=t->children[3];
			if(t->label.begin_label=="")
				t->label.begin_label=new_label();
			if(t->label.next_label=="")
				t->label.next_label=new_label();
			e2->label.true_label=s->label.next_label=new_label();
			e2->label.false_label=t->label.next_label;
			e3->label.begin_label=new_label();

			Node* w=t->children[3]->children[0];
			Node* last=new Node();
			while(w){
				last=w;
				w=w->sibling;
			}
			last->label.next_label=e3->label.begin_label;


			if(t->sibling)
				t->sibling->label.begin_label=t->label.next_label;
			s->label.next_label=e3->label.begin_label;

			recursive_get_label(e1);
			recursive_get_label(e2);
			recursive_get_label(e3);
			recursive_get_label(s);
		}
		break;
	case IF_STMT:
		{
			Node* e=t->children[0];
			Node* s1=t->children[1];  //if体
			Node* s2=t->children[2];  //else体
            if(e->label.true_label=="")
			    e->label.true_label=new_label();
			if(t->label.next_label=="")
				t->label.next_label=new_label();
			s1->label.next_label=t->label.next_label;
			if(t->sibling)
				t->sibling->label.begin_label=t->label.next_label;
			if(s2){
				e->label.false_label=new_label();
				s2->label.next_label=t->label.next_label;
			}
			else{
				e->label.false_label=t->label.next_label;
			}
			recursive_get_label(e);
			recursive_get_label(s1);
			if(s2)
				recursive_get_label(s2);
		}
		break;

	}

}

void tree::expr_get_label(Node* t){
	if(t->type!=Boolean)
		return;
	
	Node* e1=t->children[0];
	Node* e2=t->children[1];
	switch (t->attr.op)
	{
	case LOG_AND:
        {
		e1->label.true_label=new_label();
		e2->label.true_label=t->label.true_label;
		e1->label.false_label=e2->label.false_label=t->label.false_label;
		break;
        }
	case LOG_OR:
        {
		e1->label.false_label=new_label();
		e2->label.false_label=t->label.false_label;
		e1->label.true_label=e2->label.true_label=t->label.true_label;
		break;
        }
	case LOG_NOT:
        {	
		e1->label.true_label=t->label.false_label;
		e1->label.false_label=t->label.true_label;
		break;
        }
	}
	if(e1)
		recursive_get_label(e1);
	if(e2)
		recursive_get_label(e2);
}


//为表达式节点生成临时变量，每个表达式结点都是一个临时变量
void tree::get_temp_var(Node*t){
	if(t->kind!=EXPR_NODE)
		return;
	if(t->attr.op<OP_PLUS||t->attr.op>NEQU)
		return;
	Node* arg1=t->children[0];
	Node* arg2=t->children[1];
	if(arg1->kind_kind==OP_EXPR)
		tree::temp_var_seq--;
	if(arg2&&arg2->kind_kind==OP_EXPR)
		tree::temp_var_seq--;
	t->temp_var=tree::temp_var_seq;
	tree::temp_var_seq++;
}

void tree::gen_code()
{

    cout<<endl<<endl;
    gen_str();
    gen_decl();
	Node *p = root->children[0];
	cout << ".section .text" << endl;
    cout << "\t.globl main" << endl;
    cout<<"\t.type main, @function"<<endl;
    cout<<"main:"<<endl;
	for(;p;p=p->sibling)
        recursive_gen_code(p);

    cout<<endl<<"\tmovl $0, %eax"<<endl<<"\tret"<<endl;
}

void tree::gen_decl(){
    cout<<endl<<"# define variables and temp variables here"<<endl;
    cout << "\t.bss" << endl;
    cout<<"\t.align\t4"<<endl;
    for(int i=0;i<symtbl.size;i++){
        cout<<"_"<<symtbl.table[i].name<<":"<<endl;
        cout<<"\t.zero\t4"<<endl;
        cout<<"\t.align\t4"<<endl;
    }
    
    for(int i=0;i<=temp_var_seq;i++){
        if(i==temp_var_seq){
            cout << "t" <<  i << ":" << endl;
            cout << "\t.zero\t4" << endl;
        }
        else
        {
            cout << "t" <<  i << ":" << endl;
            cout << "\t.zero\t4" << endl;
            cout << "\t.align\t4" << endl;
        }
        
    }
}

void tree::gen_str(){
    cout<<endl<<"# define strings here" << endl;
    cout<<"\t.section   .rodata"<<endl;
    for(int i=0;i<ct.seqstr;i++){
        cout<<"_S"<<i<<":"<<endl;
        cout<<"\t.string "<<ct.str[i]<<endl;
    }
    for(int i=0;i<ct.seqchar;i++){
        cout<<"__"<<i<<":"<<endl;
        if(ct.chr1[i]){
            cout<<"\t.string \""<<ct.chr[i]<<ct.chr1[i]<<"\""<<endl;
        }
        else
            cout<<"\t.string \""<<ct.chr[i]<<"\""<<endl;
    }

}

void tree::recursive_gen_code(Node*t){
	if(t->kind==STMT_NODE)
		stmt_gen_code(t);
	else if(t->kind==EXPR_NODE&&t->kind_kind==OP_EXPR)
		expr_gen_code(t);
}


void tree::stmt_gen_code(Node*t){
	if(t->kind_kind==COMP_STMT){
		for(int i=0;i<4&&t->children[i];i++){
			recursive_gen_code(t->children[i]);
		for(Node* p=t->children[i]->sibling;p;p=p->sibling)
			recursive_gen_code(p);		
		}
	}
	else if(t->kind_kind==WHILE_STMT){
		if(t->label.begin_label!="")
			cout<<t->label.begin_label<<":"<<endl;
		recursive_gen_code(t->children[0]);
        if(t->children[0]->label.true_label!="")
            cout<<t->children[0]->label.true_label<<":"<<endl;
		recursive_gen_code(t->children[1]);
		cout<<"\tjmp "<<t->label.begin_label<<endl;
        if(t->label.next_label!="")
            cout<<t->label.next_label<<":"<<endl;
        return;
	}
	else if(t->kind_kind==IF_STMT){
        if(t->children[2]==NULL){//if语句
            recursive_gen_code(t->children[0]);
            cout<<t->children[0]->label.true_label<<":"<<endl;
            for(Node* s1=t->children[1];s1;s1=s1->sibling)
                recursive_gen_code(s1);
        }
        else {//if else
        Node* e=t->children[0];
        Node* s1=t->children[1];
        Node*s2=t->children[2];
        recursive_gen_code(e);
        cout<<e->label.true_label<<":"<<endl;
        for(;s1;s1=s1->sibling)
            recursive_gen_code(s1);
        cout<<"\tjmp "<<t->label.next_label<<endl;
        cout<<e->label.false_label<<":"<<endl;
        for(;s2;s2=s2->sibling)
            recursive_gen_code(s2);
        }
		if(t->label.next_label!="")
            cout<<t->label.next_label<<":"<<endl;
        return;
	}
	else if(t->kind_kind==FOR_STMT){
		recursive_gen_code(t->children[0]); //初始化，
		cout<<t->label.begin_label<<":"<<endl;
		recursive_gen_code(t->children[1]);
        cout<<t->children[1]->label.true_label<<":"<<endl;
		recursive_gen_code(t->children[3]);
		recursive_gen_code(t->children[2]);
		cout<<"\tjmp "<<t->label.begin_label<<endl;
        if(t->label.next_label!="")
            cout<<t->label.next_label<<":"<<endl;
        return;
	}
	else if(t->kind_kind==SCANF_STMT){
		Node* e=t->children[0];
        int i=1;
        Node* e1=e->sibling;
        
        if(e1!=NULL){//两个参数
            if(e1->kind==EXPR_NODE&&e1->kind_kind==OP_EXPR){
                expr_gen_code(e1);
                cout<<"\tpushl t"<<e1->temp_var<<endl;
       }
            if(e1->kind_kind==ID_EXPR&&e1->type==Reference)
                cout<<"\tpushl $_"<<e1->name<<endl;
            else
                cout<<"\tpushl _"<<e1->name<<endl;
                       
            if(e1->type==Integer)
                cout<<"\tpushl $"<<e1->attr.val.vali<<endl;
            if(e1->type==String)
                cout<<"\tpushl $_S"<<e1->str_seq<<endl;
            i=2;
        }
        cout<<"\tpushl $_S"<<e->str_seq<<endl;
        cout<<"\tcall scanf"<<endl;
        cout<<"\taddl $"<<i*4<<",%esp"<<endl;
        
	}
	else if(t->kind_kind==PRINTF_STMT){
        Node*e=t->children[0];
        int i=0;
        //共有多少个参数
        for(Node*m=e;m;m=m->sibling)
            i++;
        for(int j=i-1;j>=0;j--){   //从最后一个参数开始
            int tem=0;
            for(e=t->children[0];e;e=e->sibling){
                if(tem==j)  //找到了
                    break;
                else 
                    tem++;
            }   //e为当前要输出的参数
            if(e->kind==EXPR_NODE&&e->kind_kind==OP_EXPR){
                expr_gen_code(e);
                cout<<"\tpushl t"<<e->temp_var<<endl;
            }
            if(e->kind_kind==ID_EXPR&&e->type==Reference)
                cout<<"\tpushl $_"<<e->name<<endl;
            else if(e->kind_kind==ID_EXPR)
                cout<<"\tpushl _"<<e->name<<endl;

            if(e->type==Integer)
                cout<<"\tpushl $"<<e->attr.val.vali<<endl;
            if(e->type==String)
                cout<<"\tpushl $_S"<<e->str_seq<<endl; 
        }
        cout<<"\tcall printf"<<endl;
        cout<<"\taddl $"<<i*4<<",%esp"<<endl;
	}

}

void tree::expr_gen_code(Node* t){
	Node* e1=t->children[0];
	Node*e2=t->children[1];
	switch (t->attr.op)
	{
	case OP_ASSIGN:{
		if(e2->kind==EXPR_NODE&&e2->kind_kind==OP_EXPR)
            expr_gen_code(e2);
        if(e2->kind_kind==ID_EXPR)
            cout<<"\tmovl "<<"_"<<e2->name<<",%eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR){
            if(e2->type==Integer)
                cout<<"\tmovl "<<"$"<<e2->attr.val.vali<<",%eax"<<endl;
            if(e2->type==Char)
                cout<<"\tmovl "<<"__"<<e2->chr_seq<<",%eax"<<endl;
        }
        else if(e2->kind==EXPR_NODE&&e2->attr.op==OP_ASSIGN){
            
        }
        else 
            cout<<"\tmovl "<<"t"<<e2->temp_var<<",%eax"<<endl;

        cout<<"\tmovl %eax,_"<<e1->name<<endl;
		break;
    }
    case OP_AEQ:
    {
        if(e2->kind==EXPR_NODE&&e2->kind_kind==OP_EXPR)
            expr_gen_code(e2);
        cout << "\tmovl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<",%eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR){
            if(e2->type==Integer)
                cout<<"$"<<e2->attr.val.vali<<",%eax"<<endl;
            if(e2->type==Char)
                cout<<"__"<<e2->chr_seq<<",%eax"<<endl;
        }
        else cout<<"t"<< e2->temp_var<<", %eax"<<endl;
        cout<<"\taddl _"<<e1->name<<", %eax"<<endl;
		cout << "\tmovl %eax, _" << e1->name << endl;
        return;
    }
    case OP_SEQ:
    {
        if(e2->kind==EXPR_NODE&&e2->kind_kind==OP_EXPR)
            expr_gen_code(e2);
        cout << "\tmovl %eax, _" << e1->name << endl;
        cout<<"\tsubl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<",%eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR){
            if(e2->type==Integer)
                cout<<"$"<<e2->attr.val.vali<<",%eax"<<endl;
            if(e2->type==Char)
                cout<<"__"<<e2->chr_seq<<",%eax"<<endl;
        }
        else cout<<"t"<< e2->temp_var<<", %eax"<<endl;
        cout<<"\tmovl %eax,_"<<e1->name<<endl;
        return;
    }


    //+
	case OP_PLUS:
    {
		if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
		cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\taddl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        cout<<"\tmovl %eax, t"<<t->temp_var<<endl;
		break;
    }
    //-
	case OP_MINUS:
    {
		if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
		cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tsubl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        cout<<"\tmovl %eax, t"<<t->temp_var<<endl;
		break;
    }
	//*
    case OP_MUL:
    {
		if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
		cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\timull ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        cout<<"\tmovl %eax, t"<<t->temp_var<<endl;
        break;
    }
    // /
    case OP_DIV:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
		cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %edx"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %edx"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %edx"<<endl;
        cout<<"\tmovl %edx,%eax"<<endl;
        cout<<"\tsarl $31, %edx"<<endl;
        cout<<"\tmovl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %ebx"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %ebx"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %ebx"<<endl;
        cout<<"\tidivl %ebx"<<endl;
        cout<<"\tmovl %eax, t"<<t->temp_var<<endl;
        break;
    }
	//%
    case OP_MOD:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %edx"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %edx"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %edx"<<endl;
        cout<<"\tmovl %edx,%eax"<<endl;
        cout<<"\tsarl $31, %edx"<<endl;
        cout<<"\tmovl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %ebx"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %ebx"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %ebx"<<endl;
        cout<<"\tidivl %ebx"<<endl;
        cout<<"\tmovl %edx, t"<<t->temp_var<<endl;
        break;
    }
    case OP_INC:
    {
        cout<<"\tincl _"<<e1->name<<endl;
        break;
    }
    case OP_DEC:
    {
        cout<<"\tdecl _"<<e1->name<<endl;
        break;
    }

    case OP_UMINUS:
    {
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<",%eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<",%eax"<<endl;
        else cout<<"t"<<e1->temp_var<<",%eax"<<endl;
        cout<<"\tnegl %eax"<<endl;
        cout<<"\tmovl %eax, t"<<t->temp_var<<endl;
        break;
    }
    case LOG_OR:
    {
        recursive_gen_code(e1);
        if(e1->label.false_label!="")cout<<e1->label.false_label<<":"<<endl;
        recursive_gen_code(e2);
        break;
    }
    case LOG_NOT:
        recursive_gen_code(e1);
        break;
    case LOG_AND:
    {
        recursive_gen_code(e1);
        if(e1->label.true_label!="")cout<<e1->label.true_label<<":"<<endl;
        recursive_gen_code(e2);
        break;
    }    
    
    case LSS:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tcmpl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjl "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }    
    case LEQ:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tcmpl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjle "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }
    case GTR:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tcmpl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjg "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }
    
    case GEQ:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tcmpl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjge "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }
    case EQU:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tsubl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjz "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }
    case NEQU:
    {
        if(e1->kind_kind!=ID_EXPR&&e1->kind_kind!=CONST_EXPR)
			recursive_gen_code(e1);
		if(e2->kind_kind!=ID_EXPR&&e2->kind_kind!=CONST_EXPR)
			recursive_gen_code(e2);
        cout<<"\tmovl ";
        if(e1->kind_kind==ID_EXPR)
            cout<<"_"<<e1->name<<", %eax"<<endl;
        else if(e1->kind_kind==CONST_EXPR)
            cout<<"$"<<e1->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e1->temp_var<<", %eax"<<endl;
        cout<<"\tsubl ";
        if(e2->kind_kind==ID_EXPR)
            cout<<"_"<<e2->name<<", %eax"<<endl;
        else if(e2->kind_kind==CONST_EXPR)
            cout<<"$"<<e2->attr.val.vali<<", %eax"<<endl;
        else 
            cout<<"t"<<e2->temp_var<<", %eax"<<endl;
        if(t->label.true_label!="")
            cout<<"\tjnz "<<t->label.true_label<<endl;
        if(t->label.false_label!="")
            cout<<"\tjmp "<<t->label.false_label<<endl;
        break;
    }
	default:
		break;
	}
}
