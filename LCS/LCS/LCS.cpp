// LCS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include <iostream>
using namespace std;

//最长公共子串问题(LCS)，原理参见txt文档
char* findLCS(char* str1,char* str2)
{
	int n=strlen(str1);
	int m=strlen(str2);
	int* arrPrev=new int(m);
	int* arrCur=new int(m);

	int posJ=0;    //LCS的最后一个字符位置
	int maxLen=0; //LCS的长度

	memset(arrPrev,0,sizeof(*arrPrev)*m);

	for(int i=0;i<n;i++)
	{
		memset(arrCur,0,sizeof(*arrCur)*m);

		for(int j=0;j<m;j++)  
		{
			if(*(str1+i) == *(str2+j))
			{
				if(j==0)
					*arrCur=1;
				else
				{
					*(arrCur+j)=*(arrPrev+j-1)+1;
				}

				if(*(arrCur+j)>maxLen)
				{
					maxLen=*(arrCur+j);
					posJ=j;
					
				}
			}

		}
		
		int *temp=arrCur; //更新arrCur/arrPrev
		arrCur=arrPrev;
		arrPrev=temp;
	    
	}

    char* result=new char(maxLen+1);
	for(int i=0;i<maxLen;i++)
	{
		*(result+i)=*(str2+posJ-maxLen+1+i);

	}
	*(result+maxLen)='\0';

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
    char* str1="abdccab";
	char* str2="dcca";
	printf("%s",findLCS(str1,str2));

	return 0;
}

