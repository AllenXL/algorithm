#include <iostream>

using namespace std;

//想兑换100元钱，有1,2,5,10四种钱，问总共有多少兑换方法
//类似跳台阶问题，有dp解法，但比跳台阶复杂，要考虑重复问题，因为跳台阶是有顺序的，而兑换实际上是与顺序无关的。
//cracking code interview p. 337 有递归解法和解释

//f(i) = 没有第n种币值参与的换法总数（只用前n - 1种币值的兑换方法数） + 至少包含第n种币值的换法总数（f(i - n)）

//实际上，若令f(i, j)为用前i种货币兑换j元所对应的总兑换数，那么，这里的递推公式是f(i, j) = f(i-1, j) + f(i, j-i)
//所以说，当用一个变量搞不出递推公式的时候，不妨再搞一个变量，也许就能推出公式
//当然，由于该公式的特性，只用一维数组就可以记录中间结果
int main()
{
	const int N = 100;
	int dimes[] = {1, 2, 5, 10};
	int arr[N+1] = {1};

	for (int i = 0; i < sizeof(dimes)/sizeof(int); ++i)
	{
		for(int j = dimes[i]; j <= N; ++j) 
		{
            arr[j] += arr[j - dimes[i]];
		}
	}
	
	for (int i = 1; i <= N; ++i)
	{
		cout << arr[i] << endl;
	}

	int aa;
	cin >> aa;
}