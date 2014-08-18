// QuickSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

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

void QuickSort(int* a,int first,int last)
{
	if(first<last)
	{
		int i=AdjustArray(a,first,last);
		QuickSort(a,first,i-1);
		QuickSort(a,i+1,last);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[10]={1,3,5,7,9,2,4,6,8,10};
	QuickSort(a,0,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<<endl;
	char * str="hello";
	cout<<sizeof(*str)<<endl;
	int i=65536;
	cout<<i<<endl;
	return 0;
}

