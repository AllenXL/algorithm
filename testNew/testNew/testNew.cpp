// testNew.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <new>
using namespace std;

char buf[20];



// operator new 的重载，以及placement new的使用
void* operator new(size_t size,int data);

class Base
{
public:
	Base(int x) : a(x) {}
	void* operator new(size_t size)
	{
		cout << "my new" << endl;
		return ::operator new(size); //调用全局的operator new
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

