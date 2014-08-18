#include <iostream>

using namespace std;

//��ĿҪ�󼸴���Ծ֮�󣬸պ����������һ��
//�ݹ飬��ʱ�����ںܶ��ظ�����
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


//��dp,   dp[i]��ʾ��A[i]��������A[n]����n-1~1��������
//step��1~A[i]��step++�ķ�ʽ����������������Large Judgeʱ��TLE, ѭ��̫��ʱ
/*bool canJump(int A[], int n)
{
	bool* flag = new bool[n];

	flag[n - 1] = true;
	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = 1; j <= A[i]; ++j)
		{
			if (i + j >= n - 1 || flag[i + j])  //������ʵ�߼������⣬�Ǵ���ģ���������
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
//��ʵû��Ҫstep++;
//���dp[i+step]=false������i��һ������Ϊstep��һ����
//��Ȼ�޷���A[i+step]����A[n]����ôֱ�Ӵ�A[i+step]�ܹ�������Զ�ĵط��ĺ���һλ��ʼ������step += A[i+step] + 1
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
//Ҳ�ɲ��ü�����Զ����ķ������Ƚ�����
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
//��һ��dp���壬���������, ��������dp����Ҳ�������
//DP[i]������i����С��������ȻDP��һ�����������顣ÿ��ѭ��ֻ��Ҫ�����ҵ���С��DP[k]��ʹ������k+A[k]>=n��
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
					break;   //ֱ��break���ɣ���Ϊdp[i]�ǵ�����
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