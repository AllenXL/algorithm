// multiThread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "thread.h"

using namespace std;

void threadFun1()
{
	cout<<"Hello world from threadFun1"<<endl;
}

void threadFun2()
{
		cout<<"Hello world from threadFun2"<<endl;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	thread t1(threadFun1);
	thread t2(threadFun2);
	t1.join();
	t2.join();
	return 0;
}

