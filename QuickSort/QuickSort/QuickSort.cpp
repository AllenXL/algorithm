// QuickSort.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
using namespace std;

//两种partition方式
//方式一、跳坑式
int partition(int*a, int first, int last)
{
	int pivot = a[first];
	int i = first, j = last;

	while(i < j)
	{
		while(i < j && pivot < a[j])
			j--;
		if(i < j)
		{
			a[i] = a[j];
			i++;
		}

		while(i < j && pivot >= a[i])
			i++;
		if(i < j)
		{
			a[j] = a[i];
			j--;
		}
	}

	a[i] = pivot;
	return i;
}



void swap(int* arr, int l, int r)
{
	int tmp = arr[l];
	arr[l] = arr[r];
	arr[r] = tmp;
	return;
}

//方式二、交换式
//以下代码有bug，当数组有重复数字的时候会死循环
//本质上是对等于pivot时的情况处理不当，建议还是用上面的算法
int partition2(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;
	int pivot = arr[mid];

	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;

		if (left < right)
		{
			swap(arr, left, right);
			//left++;
			//right--;
		}
	}
	return left;
}

void QuickSort(int* a,int first,int last)
{
	if(first<last)
	{
		//int i=AdjustArray(a,first,last);
		int i = partition(a, first, last);
		QuickSort(a,first,i-1);
		QuickSort(a,i+1,last);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={2, 1, 1, 1, 2};
	int len = sizeof(a) / sizeof(int);

	cout << partition(a, 0, len - 1) << endl;
	cout << endl;

	//QuickSort(a, 0, len - 1);

	for(int i=0; i < len; i++)
		cout << a[i] << " ";

	return 0;
}

