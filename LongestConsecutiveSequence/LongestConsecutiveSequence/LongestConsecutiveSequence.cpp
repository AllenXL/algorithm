// LongestConsecutiveSequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

//O(n)时间查找最大长度的值连续子串----动态规划解

//C(i,j)代表以arr1中第i个数、arr2中第j个数结尾的LCS，那么
//if arr1[i]==arr2[j],  C(i,j)=C(i-1,j-1)+1;
//else C(i,j)=0;
//结果取个max即可
//据此填矩阵，当然空间复杂度可以优化，只需一个向量即可

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
			curValue++; //往上查找连续值，看其是否存在
		}
		if(curLen!=0)
		{
			curValue=*iter-1;
			while(iset.find(curValue)!=iset.end())  //往下查找连续值，看其是否存在
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

