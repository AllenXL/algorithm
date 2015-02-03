/*一个整型数组，从数组中选取某些值
使得它们的和最大，要求选取的值两
两之间不相邻（如4,1,6,-8,10,3，选
的是4,6,10和为20最大），求最优的
时间复杂度*/

#include <iostream>
using namespace std;

int MaxSum(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return INT_MIN;

	int res = INT_MIN;
	int* dp = new int[len];
	dp[0] = arr[0];
	for (int i = 1; i < len; ++i)
	{
		int max = arr[i];
		for (int j = i - 2; j >= 0; --j)
		{
			if (dp[j] + arr[i] > max)
			{
				max = dp[j] + arr[i];
			}
		}
		dp[i] = max;
		if (res < dp[i])
		{
			res = dp[i];
		}
	}
	return res;
}

int main()
{
	int a[] = {4,1,6,-8,10,3};
	cout << MaxSum(a, sizeof(a) / sizeof(int)) << endl;

	int aa;
	cin >> aa;
}