// FindMaxSumSequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

//����һ������A{a0,a1,a2...,an-1}����һ��A�����������У�ʹ��������----��̬�滮����
//f[i]��ʾ������ai��β�������е����ֵ����ô״̬ת�Ʒ�����f[i] = max{f[i-1]+a[i],a[i]}�������max{f[i]}����������Ҫ�õ��Ľ����������Ҫ�����

int findMaxSum(int* arr,int num)
{
	int sumTemp=arr[0];
	int maxSum=arr[0];

	for(int i=1;i<num;i++)
	{
		sumTemp=max(sumTemp+arr[i],arr[i]);
		if(sumTemp>maxSum)
			maxSum=sumTemp;
	}
	return maxSum;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arr[5]={1,2,-13,10,2};
	cout<<findMaxSum(arr,5)<<endl;
	return 0;
}

