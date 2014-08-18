// findMostNumArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
using namespace std;
//size为数组A的大小
//返回数组中出现次数超过一半的数
int search(int *A,int size)
{
	int count=0;
	int current;
	for(int i=0;i<size;i++)
	{
		if(count==0)
		{
			current=A[i];
			count=1;

		}
		else
		{
			if(A[i]==current)
				count++;
			else
				count--;
		}


	}
	return current;
}
int main()
{
	int A[6]={1,2,2,1,1,1};
	int B[7]={1,0,1,0,0,1,1};
	int C[7]={3,4,6,3,3,3,7};
	cout<<search(A,6)<<" ";
	cout<<search(B,7)<<" ";
	cout<<search(C,7)<<" "<<endl;
	int i;
	cin>>i;
	return 0;
}

