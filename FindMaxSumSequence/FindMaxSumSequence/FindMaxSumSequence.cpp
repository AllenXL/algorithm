// FindMaxSumSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

//给定一个数组A{a0,a1,a2...,an-1}，求一个A的连续子序列，使得其和最大。----动态规划方法
//f[i]表示所有以ai结尾的子序列的最大值。那么状态转移方程是f[i] = max{f[i-1]+a[i],a[i]}。最后求max{f[i]}就是我们所要得到的结果。（不需要填矩阵）

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

