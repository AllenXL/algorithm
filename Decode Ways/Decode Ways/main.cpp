#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//dfs超时，因为存在重复子问题
/*int cnt = 0;
void dfs(string& s, int begin, map<string, char>& m)
{
	if (begin >= s.size())
		cnt++;

	for (int i = begin; i < s.size() && i < begin + 2; i++)
	{
		string temp = s.substr(begin, i - begin + 1);
		if (m.find(temp) != m.end())
		{
			dfs(s, i + 1, m);
		}
	}
}

int numDecodings(string s)
{
	map<string, char> m;
	for (int i = 1; i <= 26; i++)
	{
		char temp[5];
		sprintf(temp, "%d", i);
		string s(temp);
		m[s] = 'A' + i - 1;
	}
	dfs(s, 0, m);
	return cnt;
}*/

//改用DP, if a[i] is valid, f(i) += f(i-1); if a[i-1 ~ i] is valid, f(i) += f(i-2);

int numDecodings(string s)
{
	if (s.size() == 0)
		return 0;
	vector<int> num(s.size(), 0);
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
		{
			if (s[i] >= '1' && s[i] <='9')
				num[i] = 1;
		}
		else if (i == 1)
		{
			if (s[i] >= '1' && s[i] <='9')
				num[i] += num[i - 1];
			string a(s, i - 1, 2);
			if (a >= "10" && a <= "26")
				num[i] += 1;
		}
		else
		{
			if (s[i] >= '1' && s[i] <='9')
				num[i] += num[i - 1];
			string a(s, i - 1, 2);
			if (a >= "10" && a <= "26")
				num[i] += num[i - 2];
		}
	}
	return num.back();
}


int main(void)
{
	string s("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"
);
	cout << numDecodings(s) << endl;

	int aa;
	cin >> aa;
	return 0;
}