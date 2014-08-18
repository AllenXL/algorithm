// MergeSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void MergeArray(int* a,int first,int mid,int last,int *temp)
{
	int i=first,j=mid+1;
	int k=0;
	while(i<mid+1 && j<last+1)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<mid+1)
		temp[k++]=a[i++];
	while(j<last+1)
		temp[k++]=a[j++];

	for(i=0;i<k;i++)
		a[first+i]=temp[i];

}

void MergeSort1(int* a,int first,int last,int* temp)
{
	if(first<last)
	{
		int mid=(first+last)/2;
		MergeSort1(a,first,mid,temp);
		MergeSort1(a,mid+1,last,temp);
		MergeArray(a,first,mid,last,temp);
	}

}

bool MergeSort(int* a,int n)
{
	int *temp=new int[n];
	if(temp==NULL)
		return false;
	MergeSort1(a,0,n-1,temp);
	delete temp;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10]={1,3,5,7,9,2,4,6,8,10};
	//MergeArray(a,0,4,9,c);
	MergeSort(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<endl;
	return 0;
}

