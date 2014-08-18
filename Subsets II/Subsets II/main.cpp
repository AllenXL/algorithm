#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(vector<int>& a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

void show2(vector<vector<int> >& a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int> > res;
void dfs(vector<int>& s, int begin, vector<int> cur)
{
	res.push_back(cur);

	for (int i = begin; i < s.size(); ++i)
	{
		if (i != begin && s[i] == s[i - 1]) 
			continue;
		cur.push_back(s[i]);
		dfs(s, i + 1, cur);
		cur.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S) 
{
	res.clear();
	if (S.size() == 0)
		return res;
	sort(S.begin(), S.end());
	vector<int> cur;
	dfs(S, 0, cur);
	return res;
}

int main(void)
{
	int a[5] = {1, 2, 2};
	vector<int> seq(a, a + 3);
	
	subsetsWithDup(seq);
	show2(res);
	int aa;
	cin >> aa;
	return 0;
}