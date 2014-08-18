#include <iostream>
#include <string>
#include <vector>

using namespace std;

//n个数的全排列（已排序），取第k个数，实际上可以一位位的确定下来
string getPermutation(int n, int k)
{
	string res;
	if (n <= 0 || k <= 0)
		return res;

	vector<int> factories(n);
	factories[0] = 1;
	factories[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		factories[i] = factories[i - 1] * i;
	}

	bool flag[10] = {false};  //标记是否被访问过
	for (int i = 1; i <= n; ++i)  //依次确定各位
	{
		int temp = k / factories[n - i]; //确定第几个数
		k = k % factories[n - i];

		if (k == 0)  //整除和不整除情况
		{
			k = factories[n - i];
		}
		else
			temp++;

		for (int j = 1; j <= n; ++j)
		{
			if (!flag[j]) temp--;
			if (temp == 0)
			{
				flag[j] = true;
				res += j + '0';
				break;
			}

		}
		
	}
	return res;
}

int main()
{
	cout << getPermutation(3, 2) << endl;
	int aa;
	cin >> aa;
	return 0;
}