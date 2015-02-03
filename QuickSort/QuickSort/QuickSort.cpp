// QuickSort.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
using namespace std;

//����partition��ʽ
//��ʽһ������ʽ
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

//��ʽ��������ʽ
//���´�����bug�����������ظ����ֵ�ʱ�����ѭ��
//�������ǶԵ���pivotʱ����������������黹����������㷨
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

