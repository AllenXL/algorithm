// Expression2BT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//���ʽת��������Դ����   
#include<iostream>   
#include<stack>   
#include<string>   
using namespace std;  
  
class Node  
{  
public:  
    char oper;//�������������   
    Node *left;//������   
    Node *right;//������   
    Node():left(NULL),right(NULL),oper(0){}  
    Node(char op):left(NULL),right(NULL),oper(op){}  
};  
  
//�ж��Ƿ�Ϊ�����   
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
  
//������������ȼ�   
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
  
//���ٶ�����   
void freeTree(Node*& p)  
{  
    if(p->left != NULL)  
        freeTree(p->left);  
    if(p->right != NULL)  
        freeTree(p->right);  
    delete(p);  
}  
  
//�ݹ��������   
void preOrderTraverse(Node *p)  
{  
   if(p!=NULL)  
   {  
       cout<<p->oper;  
       preOrderTraverse(p->left);  
       preOrderTraverse(p->right);  
   }  
}  
  
//�������   
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
 



//ǰ׺���ʽ���ɶ��������ݹ�
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

//��׺���ʽ���ɶ���������Ҫ��������ջ�������ջ�Ͷ������ڵ�ջ  
void generateTree(Node*& p, string expr)  
{  
    stack <char> operStack;  
    stack <Node*> dataStack;  
    char tmpchr,c;  
    int idx=0;  
    tmpchr=expr[idx++];  
    while(operStack.size()!=0 || tmpchr!='\0')  
    {  
        if(tmpchr!='\0' && !isOper(tmpchr))//����������������������ջ   
        {  
            p=new Node(tmpchr);  
            dataStack.push(p);  
            tmpchr=expr[idx++];  
        }  
        else  
        {  
            switch(tmpchr)  
            {  
            case '('://��ջ   
                operStack.push('(');  
                tmpchr=expr[idx++];  
                break;  
            case ')'://������   
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
                {//��ջ   
                    operStack.push(tmpchr);  
                    tmpchr=expr[idx++];  
                }  
                else  
                {//��ջ   
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


//��׺���ʽת�ɶ��������ܼ򵥣�һ���������ڵ�ջ�Ϳ�ʵ�֣�����Ͳ�д��
  
int main()  
{  
   string expression;  
   Node* tree;  
  
   cout<<"�������ַ������ʽ:";  
   cin>>expression;  
   //generateTree(tree,expression); 

   int k=0;
   pre2TreeExp(tree, expression, &k);
  
   cout<<"ǰ׺���ʽΪ:";  
   preOrderTraverse(tree);  
   cout<<endl;  
  
   cout<<"��׺���ʽΪ:";  
   inOrderTraverse(tree);  
   cout<<endl;  
  
   freeTree(tree);  
   cout<<endl;  
  
   return 0;  
}

