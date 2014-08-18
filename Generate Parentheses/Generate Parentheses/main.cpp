#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(int& l, int& r, int n, string& tmp, vector<string>& res)
{
	if (l == n && r == n)
	{
		res.push_back(tmp);
		return;
	}

	if (l < n)
	{
		tmp.push_back('(');
		l++;
		dfs(l, r, n, tmp, res);
		l--;
		tmp.pop_back();
	}

	if (r < n && l > r)
	{
		tmp.push_back(')');
		r++;
		dfs(l, r, n, tmp, res);
		r--;
		tmp.pop_back();
	}
	return;
}

vector<string> generateParenthesis(int n)
{
	vector<string> res;
	if (n <= 0)
		return res;
	string tmp;
	int l = 0;
	int r = 0;
	dfs(l, r, n, tmp, res);
	return res;
}

void show(vector<string>& res)
{
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
}

int main()
{
	show(generateParenthesis(3));
	int aa;
	cin >> aa;
	return 0;
}