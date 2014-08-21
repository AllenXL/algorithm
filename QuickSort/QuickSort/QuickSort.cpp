// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
using namespace std;

//����partition��ʽ
//��ʽһ������ʽ
int AdjustArray(int*a, int first, int last)
{
	int pivot=a[first];
	int i=first,j=last;

	while(i<j)
	{
		while(i<j&& pivot<a[j])
			j--;
		if(i<j)
		{
			a[i]=a[j];
			i++;
		}
		while(i<j&&pivot>a[i])
			i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
		}
	}

	a[i]=pivot;
	return i;
}



void swap(int* arr, int l, int r)
{
	int tmp = arr[l];
	arr[l] = arr[r];
	arr[r] = tmp;
	return;
}

//��ʽ��������ʽ
int partition(int* arr, int left, int right)
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
	int a[]={1, 10, 8, 5, 2, 20};
	int len = sizeof(a) / sizeof(int);
	QuickSort(a, 0, len - 1);
	for(int i=0; i < len; i++)
		cout<<a[i]<<endl;
	char * str="hello";
	cout<<sizeof(*str)<<endl;
	int i=65536;
	cout<<i<<endl;
	return 0;
}

