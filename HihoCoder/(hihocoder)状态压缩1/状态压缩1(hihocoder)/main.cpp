#include <iostream>
#include <vector>

using namespace std;

/*
小Hi和小Ho所处的车厢可以被抽象成连成一列的N个位置，按顺序分别编号为1..N，每个位置上都有且仅有一名乘客在休息。
同时每个位置上都有一些垃圾需要被清理，其中第i个位置的垃圾数量为Wi。乘务员可以选择其中一些位置进行清理，
但是值得注意的是，一旦有编号连续的M个位置中有超过Q个的位置都在这一次清理中被选中的话（即这M个位置上的乘客有至少Q+1个被惊醒了），
就会发生令人不愉快的口角。
而小Hi和小Ho的任务是，计算选择哪些位置进行清理，在不发生口角的情况下，清扫尽可能多的垃圾。
*/

//动态规划 + 状态压缩
//假设前i个位置的选择方案已经确定，对于第i+1个位置来说，是否选择清理取决于i+1前面的M - 1个位置的选择情况；
//设选中为1，不选中为0，那么前M - 1个位置的选择状态实际上可以压缩成一个M - 1位的数字。
//因此只需两个状态即可，f(i, s)表示前i个位子，并且从i开始的M - 1位的选择状态为s，所对应的最大值


int countOnes(int s)
{
	int cnt = 0;
	while (s)
	{
		cnt++;
		s &= s - 1;
	}
	return cnt;
}

int GetMax(vector<int>& w, int N, int M, int Q)
{
	vector<vector<int> > dp(N + 1, vector<int>(1 << M - 1));
	for (int i = 1; i <= N; ++i)
	{
		for (int s = 0; s < (1 << M - 1); ++s)
		{
			int ones = countOnes(s);
			if (ones > Q)
			{
				dp[i][s] = 0;
				continue;
			}
			else if (ones == Q)
			{
				dp[i][s] = dp[i - 1][s >> 1];
			}
			else
			{
				dp[i][s] = max(dp[i - 1][s >> 1], dp[i - 1][(s >> 1) | (1 << M - 2)]);
			}

			if (s & (1 << M - 2))
			{
				dp[i][s] += w[i - 1];
			}
		}
	}

	int max = 0;
	for (int i = 0; i < (1 << M - 1); ++i)
	{
		max = max < dp[N][i] ? dp[N][i] : max;
	}
	return max;
}


int main()
{
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<int> w(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> w[i];
	}

	cout << GetMax(w, N, M, Q) << endl;

	int aa;
	cin >> aa;
}