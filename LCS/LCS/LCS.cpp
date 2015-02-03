#include "stdafx.h"
#include "string.h"
#include <iostream>
#include <vector>

using namespace std;

//LCS����ʵ���Ϸֳ������ͷ��������֣���������dp����������Ǵ���

//������Ӵ�����(LCS)��Ҫ������
char* findLCS(char* str1,char* str2)
{
	int n=strlen(str1);
	int m=strlen(str2);
	int* arrPrev=new int(m);
	int* arrCur=new int(m);

	int posJ=0;    //LCS�����һ���ַ�λ��
	int maxLen=0; //LCS�ĳ���

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
		
		int *temp=arrCur; //����arrCur/arrPrev
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

//LCS���Ӵ���������� 2014.08.29��������dpд
//f(i, j)��ʾs1ǰi���ַ���s2ǰj���ַ����γɵ�LCS�����Ҹ�LCS������s1[i - 1]��s2[j - 1]��β
//f(i, j) = f(i - 1, j - 1) + s1[i] == s2[j] ? 1 : 0;
char* findLCS2(char* str1,char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int idx1 = -1; //��¼����Ӵ������һ���ַ���str1�е�����
	int idx2 = -1;
	int maxLen = 0;

	int* dp = new int[len2];
	memset(dp, 0, sizeof(int) * len2);
	
	for (int i = 0; i < len1; ++i)
	{
		for (int j = len2 - 1; j >= 0; --j)
		{
			if (str1[i] != str2[j])
			{
				dp[j] = 0;
			}
			else
			{
				dp[j] = (j > 0 ? dp[j - 1] : 0) + 1;
			}
			if (maxLen < dp[j])
			{
				maxLen = dp[j];
				idx1 = i;
				idx2 = j;
			}
		}
	}

	char* res = new char[maxLen + 1];
	strncpy(res, str1 + idx1 - maxLen + 1, maxLen);
	res[maxLen] = '\0';
	
	delete[] dp;
    return res;
}

//LCS���Ӵ����������
//f(i, j)��ʾs1[0~i] �� s2[0~j]��LCS
//f(i, j) = f(i - 1, j - 1) + 1, if (str1[i] == str2[j]);
//f(i, j) = max(f(i, j - 1), f(i - 1, j));

//�������LCS����c[i,j] = c[i-1][j-1] + 1 ʱ����X[i] = Y[j] �� LCS��һ���ַ�
void GetLCSHelper(vector<vector<int> >& dp, int i, int j, char* str1, char* str2)
{
	if (i == 0)
	{
		if (dp[i][j] > 0)
		{
			cout << str1[i];
		}
		return;
	}
	else if (j == 0)
	{
		if (dp[i][j] > 0)
		{
			cout << str2[j];
		}
		return;
	}
	
	if (dp[i][j] == dp[i - 1][j])
	{
		GetLCSHelper(dp, i - 1, j, str1, str2);
	}
	else if (dp[i][j] == dp[i][j - 1])
	{
		GetLCSHelper(dp, i, j - 1, str1, str2);
	}
	else
	{
		cout << str1[i];
		GetLCSHelper(dp, i - 1, j - 1, str1, str2);
	}
}

int findLCS3(char* str1, char* str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	vector<vector<int> > dp(len1, vector<int>(len2, 0));
	
	int flag = 0;
	for (int i = 0; i < len2; ++i)
	{
		if (str1[0] == str2[i])
		{
			flag = 1;
		}
		dp[0][i] =  flag;
	}

	flag = 0;
	for (int i = 0; i < len1; ++i)
	{
		if (str1[i] == str2[0])
		{
			flag = 1;
		}
		dp[i][0] = flag;
	}

	for (int i = 1; i < len1; ++i)
	{
		for (int j = 1; j < len2; ++j)
		{
			if (str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len2; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	GetLCSHelper(dp, len1 - 1, len2 - 1, str1, str2);
	cout << endl;
	return dp[len1 - 1][len2 - 1];
}

int _tmain(int argc, _TCHAR* argv[])
{
    char* str1="badccab";
	char* str2="bdcca";

	printf("%s",findLCS(str1,str2));

	cout << endl;
	cout << "res of new algorithm: " << findLCS2(str1, str2) << endl;

	cout << "res of not continuos: " << findLCS3(str1, str2) << endl;
	return 0;
}

