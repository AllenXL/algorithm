// Expression2BT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//表达式转二叉树的源代码   
#include<iostream>   
#include<stack>   
#include<string>   
using namespace std;  
  
class Node  
{  
public:  
    char oper;//操作数或运算符   
    Node *left;//左子树   
    Node *right;//右子树   
    Node():left(NULL),right(NULL),oper(0){}  
    Node(char op):left(NULL),right(NULL),oper(op){}  
};  
  
//判断是否为运算符   
bool isOper(char op)  
{  
    char oper[]={'(',')','+','-','*','/'};  
    for(int i=0;i<strlen(oper);i++)  
    {  
        if(op==oper[i])  
            return true;  
    }  
    return false;  
}  
  
//求运算符的优先级   
int getOperPri(char op)  
{  
    switch(op)  
    {  
        case '(':  
        return 1; break;  
        case '+':  
        case '-':  
        return 2; break;  
        case '*':  
        case '/':  
        return 3; break;  
        default:  
        return 0;  
    }  
}  
  
//销毁二叉树   
void freeTree(Node*& p)  
{  
    if(p->left != NULL)  
        freeTree(p->left);  
    if(p->right != NULL)  
        freeTree(p->right);  
    delete(p);  
}  
  
//递归先序遍历   
void preOrderTraverse(Node *p)  
{  
   if(p!=NULL)  
   {  
       cout<<p->oper;  
       preOrderTraverse(p->left);  
       preOrderTraverse(p->right);  
   }  
}  
  
//中序遍历   
void inOrderTraverse(Node *p)  
{  
    if(p)  
    {  
        if(p->left)  
        {  
            if(isOper(p->left->oper)&&getOperPri(p->left->oper)<getOperPri(p->oper))  
            {  
                cout<<"(";  
                inOrderTraverse(p->left);  
                cout<<")";  
            }  
            else  
            inOrderTraverse(p->left);  
        }  
        cout<<p->oper;  
        if(p->right)  
        {  
            if(isOper(p->right->oper)&&getOperPri(p->right->oper)<=getOperPri(p->oper))  
            {  
                cout<<"(";  
                inOrderTraverse(p->right);  
                cout<<")";  
            }  
            else  
            inOrderTraverse(p->right);  
        }  
    }  
}  
 



//前缀表达式生成二叉树，递归
void pre2TreeExp(Node*& p, string expr, int *k)

{
	
	char oper = expr[(*k)++];

	p=new Node(oper);
	if(oper >= '0' && oper <='9')
	{
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		pre2TreeExp(p->left, expr, k);
		pre2TreeExp(p->right, expr, k);
	}

}

//中缀表达式生成二叉树，需要建立两个栈，运算符栈和二叉树节点栈  
void generateTree(Node*& p, string expr)  
{  
    stack <char> operStack;  
    stack <Node*> dataStack;  
    char tmpchr,c;  
    int idx=0;  
    tmpchr=expr[idx++];  
    while(operStack.size()!=0 || tmpchr!='\0')  
    {  
        if(tmpchr!='\0' && !isOper(tmpchr))//不是运算符，则进操作数的栈   
        {  
            p=new Node(tmpchr);  
            dataStack.push(p);  
            tmpchr=expr[idx++];  
        }  
        else  
        {  
            switch(tmpchr)  
            {  
            case '('://进栈   
                operStack.push('(');  
                tmpchr=expr[idx++];  
                break;  
            case ')'://脱括号   
                while(true)  
                {  
                    c=operStack.top();  
                    operStack.pop();  
                    if(c=='(')  
                    {  
                        break;  
                    }  
                    p=new Node(c);  
                    if(dataStack.size())  
                    {  
                        p->right=dataStack.top();  
                        dataStack.pop();  
                    }  
                    if(dataStack.size())  
                    {  
                        p->left=dataStack.top();  
                        dataStack.pop();  
                    }  
                    dataStack.push(p);  
                }  
                tmpchr=expr[idx++];  
                break;  
            default:  
                if(operStack.size()==0 || tmpchr!='\0' && getOperPri(operStack.top())< getOperPri(tmpchr))  
                {//进栈   
                    operStack.push(tmpchr);  
                    tmpchr=expr[idx++];  
                }  
                else  
                {//出栈   
                    p=new Node(operStack.top());  
                    p->oper=operStack.top();  
                    if(dataStack.size())  
                    {  
                        p->right=dataStack.top();  
                        dataStack.pop();  
                    }  
                    if(dataStack.size())  
                    {  
                        p->left=dataStack.top();  
                        dataStack.pop();  
                    }  
                    dataStack.push(p);  
                    operStack.pop();  
                }  
                break;  
            }  
        }  
    }  
    p=dataStack.top();  
    dataStack.pop();  
}  


//后缀表达式转成二叉树，很简单，一个二叉树节点栈就可实现，这里就不写了
  
int main()  
{  
   string expression;  
   Node* tree;  
  
   cout<<"请输入字符串表达式:";  
   cin>>expression;  
   //generateTree(tree,expression); 

   int k=0;
   pre2TreeExp(tree, expression, &k);
  
   cout<<"前缀表达式为:";  
   preOrderTraverse(tree);  
   cout<<endl;  
  
   cout<<"中缀表达式为:";  
   inOrderTraverse(tree);  
   cout<<endl;  
  
   freeTree(tree);  
   cout<<endl;  
  
   return 0;  
}

