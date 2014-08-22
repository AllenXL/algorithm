#include <iostream>

using namespace std;

//想兑换100元钱，有1,2,5,10四种钱，问总共有多少兑换方法
//类似跳台阶问题，有dp解法，但比跳台阶复杂，要考虑重复问题，因为跳台阶是有顺序的，而兑换实际上是与顺序无关的。
//cracking code interview p. 337 有递归解法和解释

//f(i) = 没有第n种币值参与的换法总数（只用前n - 1种币值的兑换方法数） + 至少包含第n种币值的换法总数（f(i - n)）

//实际上，若令f(i, j)为用前i种货币兑换j元所对应的总兑换数，那么，这里的递推公式是f(i, j) = f(i-1, j) + f(i, j-i)
//所以说，当用一个变量搞不出递推公式的时候，不妨再搞一个变量，也许就能推出公式
//当然，由于该公式的特性，只用一维数组就可以记录中间结果

void GetExchangeDP(int total, int* dimes, int types)  //total 为总钱数， dimes存储币种, types币种数
{
	int* dp = new int[total + 1];
	memset(dp, 0, (total + 1) * sizeof(int));
	dp[0] = 1;

	for (int i = 0; i < types; ++i)
	{
		for (int j = dimes[i]; j <= total; ++j)
		{
			dp[j] += dp[j - dimes[i]];
		}
	}

	//print result
	for (int i = 1; i <= total; ++i)
	{
		cout << dp[i] << endl;
	}
	return;
}

//递归实现
//f(i, j) = f(i-1, j) + f(i, j-i)
int GetExchangeHelper(int total, int* dimes, int len)
{
	if (total == 0)
		return 1;
	else if (total < 0)
		return 0;

	if (dimes == NULL || len <= 0)
		return 0;

	return GetExchangeHelper(total, dimes, len - 1) + GetExchangeHelper(total - dimes[len - 1], dimes, len);
}

void GetExchangeRecur(int total, int* dimes, int len)
{
	cout << GetExchangeHelper(total, dimes, len) << endl;
}

//另外一种子问题分解方法
//前面是分解成：兑换后没有10元钱，以及至少有一张10元钱两种情况
//现在分解成：兑换后：没有10元钱，有一张10元钱，...，有10张10元钱
//f(i, j) = f(i - 1, j) + f(i - 1, j - dimes[j]) + f(i - 1, j - dimes[j] * 2) + ...
//同样可以用DP和递归实现，下面用递归
int GetExchangeHelper2(int total, int* dimes, int len)
{
	if (total == 0)
		return 1;
	else if (total < 0)
		return 0;

	if (dimes == NULL || len <= 0)
		return 0;

	int cur = dimes[len - 1];
	int ways = 0;
	for (int i = 0; i <= total; i += cur)
	{
		ways += GetExchangeHelper2(total - i, dimes, len - 1);
	}
	return ways;
}

void GetExchangeRecur2(int total, int* dimes, int len)
{
	cout << GetExchangeHelper2(total, dimes, len) << endl;
}


int main()
{
	int money = 100;
	int dimes[] = {1, 2, 5, 10};

	cout << "DP result:" << endl;
	GetExchangeDP(money, dimes, sizeof(dimes) / sizeof(int));

	cout << "Recursive Result1:" << endl;
	GetExchangeRecur(money, dimes, sizeof(dimes) / sizeof(int));

	cout << "Recursive Result2:" << endl;
	GetExchangeRecur2(money, dimes, sizeof(dimes) / sizeof(int));

	int aa;
	cin >> aa;
}