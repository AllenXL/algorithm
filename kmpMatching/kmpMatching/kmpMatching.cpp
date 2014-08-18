// kmpMatching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);

	int i = 0;
	int j = 0;

	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == pLen)
		return i - j;
	else
		return -1;
}

void GetNext(char* p, int* next)
{
	int pLen = strlen(p);
	next[0] = -1;

	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		if (k == -1 || p[k] == p[j])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//改进next数组
void GetNext1(char* p, int* next)
{
	int pLen = strlen(p);
	next[0] = -1;

	int k = -1;
	int j = 0;

	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			k++;
			j++;
			
			if (p[j] != p[k])  //因为p[j]已经跟s[i]失配，然后你还用跟p[j]等同的值p[next[j]]去跟s[i]匹配，很显然，必然失配
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}
		}
	}
}

int KMPMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);

	if (s == 0 || p == 0)
		return -1;

	int* next = new int[pLen];
	GetNext1(p, next);

	int i = 0;
	int j = 0;

	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	delete next;
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
    char* s="ababaab";
	char* p="aab";


	int pos=KMPMatch(s,p);
	cout << "KMPMatch: " << pos << endl;

	int pos2 = ViolentMatch(s, p);
	cout << "ViolentMatch: " << pos2 << endl;


	return 0;
}

