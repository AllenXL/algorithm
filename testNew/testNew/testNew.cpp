// testNew.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <new>
using namespace std;

char buf[20];



// operator new �����أ��Լ�placement new��ʹ��
void* operator new(size_t size,int data);

class Base
{
public:
	Base(int x) : a(x) {}
	void* operator new(size_t size)
	{
		cout << "my new" << endl;
		return ::operator new(size); //����ȫ�ֵ�operator new
	}
	void f()
	{
		cout << "a = " << a << endl;
	}
public:
	int a;
};

int _tmain(int argc, _TCHAR* argv[])
{
	int* temp=new int(2);
	
	int* buft=new(buf+1) int(5);  //placement new
	cout<<*buft<<endl;
	cout<<*((int*)(buf + 1))<<endl;

	int* t=new(10) int(8);//operator new
	//*t=2;
	cout<<*t<<endl;
	cout << sizeof(int[3]) << endl;

	Base* b = new Base(100);
	b->f();

	return 0;
}

void* operator new(size_t size,int data)
{
	cout << "in" << endl;
	cout<<data<<endl;
	return operator new(sizeof(int));
}

