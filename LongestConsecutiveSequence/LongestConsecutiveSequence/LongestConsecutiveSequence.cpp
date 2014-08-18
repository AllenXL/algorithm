// LongestConsecutiveSequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//O(n)ʱ�������󳤶ȵ�ֵ�����Ӵ�----��̬�滮��

//C(i,j)������arr1�е�i������arr2�е�j������β��LCS����ô
//if arr1[i]==arr2[j],  C(i,j)=C(i-1,j-1)+1;
//else C(i,j)=0;
//���ȡ��max����
//�ݴ�����󣬵�Ȼ�ռ临�Ӷȿ����Ż���ֻ��һ����������

int longestConsecutive(vector<int> &num) 
{
	set<int> iset;
	int maxLen=0;
	int curLen=0;
	int curValue=0;
	for(vector<int>::iterator iter=num.begin();iter<num.end();iter++)
	{
		iset.insert(*iter);
	}
	
	for(vector<int>::iterator iter=num.begin();iter<num.end();iter++)
	{
		curValue=*iter;
		curLen=0;
		while(iset.find(curValue)!=iset.end())
		{
			iset.erase(curValue);
			curLen++;
			curValue++; //���ϲ�������ֵ�������Ƿ����
		}
		if(curLen!=0)
		{
			curValue=*iter-1;
			while(iset.find(curValue)!=iset.end())  //���²�������ֵ�������Ƿ����
			{
				iset.erase(curValue);
				curLen++;
				curValue--;
			}
		}

		if(curLen>maxLen)
			maxLen=curLen;
		
	}
	return maxLen;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[9]={1,3,4,6,4,2,8,5,5};
	vector<int> ivec;
	for(vector<int>::size_type i=0;i<9;i++)
	{
		ivec.push_back(a[i]);
	}
	cout<<longestConsecutive(ivec)<<endl;
	return 0;
}

