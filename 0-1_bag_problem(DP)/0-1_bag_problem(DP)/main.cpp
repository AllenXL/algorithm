#include <iostream>

using namespace std;

//0-1背包问题
//动态规划
//if w(i) > j,    f(i, j) = f(i - 1, j);
//else,           f(i, j) = max(f(i - 1, j), f(i - 1, j - w(i)) + v(i));

//从公式可看出，只要开辟一维矩阵即可

int GetMaxVal(int* w, int* v, int n, int maxVolume)
{
	if (w == NULL || v == NULL || n <= 0 || maxVolume <= 0)
	{
		return 0;
	}

	int* dp = new int[maxVolume + 1];
	memset(dp, 0, sizeof(int) * (maxVolume + 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = maxVolume; j >= w[i]; --j)
		{
			int tmp = dp[j - w[i]] + v[i];
			if (tmp > dp[j]) dp[j] = tmp;
		}
	}

	int res = dp[maxVolume];
	delete[] dp;
	return res;
}


int main()
{
	int N, M;
	cin >> N >> M;
	int* w = new int[N];
	int* v= new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> w[i];
		cin >> v[i];
	}

	cout << GetMaxVal(w, v, N, M) << endl;

	delete[] w;
	delete[] v;
	return 0;
}