#include <iostream>

using namespace std;

//题目要求几次跳跃之后，刚好能跳到最后一格
//递归，超时，存在很多重复计算
/*bool canJump1(int A[], int i, int end)
{
	if (i == end)
		return true;
	if (i > end)
		return false;
	if (A[i] == 0)
		return false;

	bool res = false;
	for (int j = 1; j <= A[i]; j++)
	{
		res = canJump1(A, i + j, end);
		if (res)
			break;
	}
	return res;
}

bool canJump(int A[], int n)
{
	return canJump1(A, 0, n - 1);
}*/


//用dp,   dp[i]表示从A[i]可以跳到A[n]，从n-1~1更新数组
//step从1~A[i]按step++的方式递增，但是这样在Large Judge时会TLE, 循环太耗时
/*bool canJump(int A[], int n)
{
	bool* flag = new bool[n];

	flag[n - 1] = true;
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 1; j <= A[i]; ++j)
		{
			if (i + j >= n - 1 || flag[i + j])  //这里其实逻辑有问题，是错误的，不符题意
			{
				flag[i] = true;
				break;
			}
		}
	}
	bool res = flag[0];
	delete flag;
	return res;
}*/

//AC
//其实没必要step++;
//如果dp[i+step]=false，即从i跳一个长度为step的一跳后，
//仍然无法从A[i+step]跳到A[n]，那么直接从A[i+step]能够到达最远的地方的后面一位开始跳，即step += A[i+step] + 1
/*bool canJump(int A[], int n)
{
	bool* flag = new bool[n];

	flag[n - 1] = true;
	for (int i = n - 2; i >= 0; --i)
	{
	    flag[i] = false;
		for (int j = 1; j <= A[i];)
		{
			if (i + j == n - 1)
			{
				flag[i] = true;
				break;
			}
			if (i + j > n - 1)
			    break;
			
			if (flag[i + j])
			{
			    flag[i] = true;
			    break;
			}
			j += A[i + j] + 1;
		}
	}
	bool res = flag[0];
	delete flag;
	return res;
}*/

//AC
//也可采用计算最远距离的方法，比较巧妙
bool canJump(int A[], int n)
{
	int max = 0;
	for (int i = 0; i < n - 1 && i <= max; ++i)
	{
		max = i + A[i] > max ? i + A[i] : max;	
	}
	return max >= n - 1;
}


//Jump Game II
//换一种dp定义，更容易求解, 用上述的dp定义也可以求解
//DP[i]代表到达i的最小跳数，显然DP是一个递增的数组。每次循环只需要尽量找到最小的DP[k]，使其满足k+A[k]>=n。
int jump(int A[], int n)
{
	int* dp = new int[n];

	dp[0] = 0;

	for (int i = 1; i < n; ++i)
	{
		dp[i] = 1000000;
		for (int j = 0; j < i; ++j)
		{
			if (j + A[j] >= i)
			{
				int tmp = dp[j] + 1;
				if (dp[i] > tmp)
				{
					dp[i] = tmp;
					break;   //直接break即可，因为dp[i]是递增的
				}
			}
		}
	}
	return dp[n - 1];
}


int main()
{
	int A[] = {2, 0};
	cout << canJump(A, 2) << endl;
	int aa;
	cin >> aa;
	return 0;
}