#include <iostream>
#include <string>

using namespace std;

//对于一个字符串，将其按n个字符阶段，最后不足的补零
/*int main()
{
	int m, n;
	cin >> m >> n;

	string str;
	string substr(n, '0');
	
	while (m--)
	{
		cin >> str;
		int cnt = str.size() / n;
		if (str.size() % n != 0)
			cnt++;

		for (int i = 0; i < cnt; ++i)
		{
			substr = string(n, '0');
			int k = 0;
			for (int j = i * n; j < str.size() && j < i * n + n; ++j)
			{
				substr[k++] = str[j];
			}
			cout << substr << endl;
		}

	}

	int aa;
	cin >> aa;
	return 0;
}
*/

//字符串去重，并按顺序输出
int main()
{
	string str;
	cin >> str;

	int c[26] = {0};

	for (int i = 0; i < str.size(); ++i)
	{
		if (c[str[i] - 'a'] == 0)
		{
			c[str[i] - 'a'] = 1;
		}
	}

	string res;
	for (int i = 0; i < 26; ++i)
	{
		if (c[i] != 0)
		{
			res.push_back(i + 'a');
		}
	}
	cout << res << endl;

	int aa;
	cin >> aa;
	return 0;
}