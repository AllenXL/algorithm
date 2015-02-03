/*һ���������飬��������ѡȡĳЩֵ
ʹ�����ǵĺ����Ҫ��ѡȡ��ֵ��
��֮�䲻���ڣ���4,1,6,-8,10,3��ѡ
����4,6,10��Ϊ20��󣩣������ŵ�
ʱ�临�Ӷ�*/

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