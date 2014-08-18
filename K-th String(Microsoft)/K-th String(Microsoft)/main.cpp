/*2014微软暑期实习在线笔试
Time Limit: 10000ms
Case Time Limit: 1000ms
Memory Limit: 256MB

Description

Consider a string set that each of them consists of {0, 1} only. All strings in the set have the same number of 0s and 1s. Write a program to find and output the K-th string according to the dictionary order. 
If s​uch a string doesn’t exist, or the input is not valid, please output “Impossible”. For example, if we have two ‘0’s and two ‘1’s, we will have a set with 6 different strings, {0011, 0101, 0110, 1001, 1010, 1100}, 
and the 4th string is 1001.


Input

The first line of the input file contains a single integer t (1 ≤ t ≤ 10000), the number of test cases, followed by the input data for each test case.
Each test case is 3 integers separated by blank space: N, M(2 <= N + M <= 33 and N , M >= 0), K(1 <= K <= 1000000000). N stands for the number of ‘0’s, 
M stands for the number of ‘1’s, and K stands for the K-th of string in the set that needs to be printed as output.


Output

For each case, print exactly one line. If the string exists, please print it, otherwise print “Impossible”. 


Sample In

3
2 2 2
2 2 7
4 7 47

Sample Out

0101
Impossible
01010111011*/

#include <iostream>

using namespace std;

int GetTotal(int N, int M)
{
	if (N == 0 || M == 0)
		return 1;
	if (N == 1 || M == 1)
		return N + M;
	return GetTotal(N, M - 1) + GetTotal(N - 1, M);
}

void dfs(char* str, int idx, int N, int M, int& cnt, int K)
{
	if (N == 0 || M == 0)
	{
		cnt++;
		if (K == cnt)
		{
			if (N == 0)
			{
				while (M--)
				{
					str[idx++] = '1';
				}
				str[idx] = '\0';
			}
			else if (M == 0)
			{
				while (N--)
				{
					str[idx++] = '0';
				}
				str[idx] = '\0';
			}
			cout << str << endl;
		}
		return;
	}

	str[idx] = '0';
	dfs(str, idx + 1, N - 1, M, cnt, K);

	str[idx] = '1';
	dfs(str, idx + 1, N, M - 1, cnt, K);
}

int main()
{
	int case_num = 0;
	int N, M, K;
	cin >> case_num;

	for (int i = 0; i < case_num; ++i)
	{
		cin >> N >> M >> K;
		if (K > GetTotal(N, M))
		{
			cout << "Impossible" << endl;
			continue;
		}
		char str[50] = {'\0'};
		int cnt = 0;
		dfs(str, 0, N, M, cnt, K);
	}
	int aa;
	cin >> aa;
	return 0;
}