#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(string& digits, int& depth, string& path, vector<string>& res)
{
	const static string strT[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};

	if (depth == digits.size())
	{
		res.push_back(path);
		return;
	}

	for (int i = 0; i < strT[digits[depth] - '0'].size(); ++i)
	{
		path.push_back(strT[digits[depth] - '0'][i]);
		depth++;
		dfs(digits, depth, path, res);
		depth--;
		path.pop_back();
	}
}

vector<string> letterCombinations(string digits)
{
	int depth = 0;
	string path;
	vector<string> res;
	dfs(digits, depth, path, res);
	return res;
}

int main()
{
	vector<string> res = letterCombinations(string("23"));

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	int aa;
	cin >> aa;
}