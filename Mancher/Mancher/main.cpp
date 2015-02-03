#include <iostream>

using namespace std;


//用于求最长回文串的mancher算法，时间复杂度为O(n)
//通过记录已匹配的最右位置和对应的对称中心来跳过一些没用的比较

int Manacher(char* s)
{
	int len = strlen(s);
	if (s == NULL || len == 0 || len == 1)
		return 0;

	int* rad = new int[len * 2 + 2]; //以某字符为中心，向左右扩张，rad中保存对应半径(不包括自身), 刚好为实际回文长度
	char* str = new char[len * 2 + 3];
	str[0] = '$';
	str[1] = '#';

	int n = 2;
	for (int i = 0; i < len; ++i)
	{
		str[n++] = s[i];
		str[n++] = '#';
	}
	str[n++] = '\0';

	cout << str << endl;

	rad[0] = 0;
	int c = 0;
	int r = 0;

	len = len * 2 + 2;
	for (int i = 1; i < len; ++i)
	{
		if (r > i)
		{
			rad[i] = min(rad[2 * c - i], r - i);
		}
		else
		{
			rad[i] = 0;
		}

		while (str[i + rad[i] + 1] == str[i - rad[i] - 1]) rad[i]++;  //如果前面没有str[0] = '$', 执行这句话时很可能越界

		if (i + rad[i] > r)
		{
			r = i + rad[i];
			c = i;
		}
	}

	int res = 0;
	for (int i = 1; i < len; ++i)
	{
		res = max(res, rad[i]);
	}

	delete[] rad;
	delete[] str;
	return res;
}

int main()
{
	int n;
	cin >> n;
	char s[1000100] = {0};

	while (n--)
	{
		cin >> s;
		cout << Manacher(s) << endl;
	}

	return 0;
}