#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void show(vector<vector<int> >& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[i].size(); ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


vector<vector<int> > res;

void dfs(vector<int>& S, int begin, vector<int>& cur)
{
	res.push_back(cur);

	for (int i = begin; i < S.size(); ++i)
	{
		cur.push_back(S[i]);
		dfs(S, i + 1, cur);
		cur.pop_back();
	}
}
vector<vector<int> > subsets(vector<int> &S)
{
	res.clear();
	sort(S.begin(), S.end());
	vector<int> cur;
	dfs(S, 0, cur);

	return res;
}



int main(void)
{
	int a[] = {1, 2, 3};
	vector<int> v(a, a + sizeof(a)/sizeof(int));
	vector<vector<int> > sub = subsets(v);
	show(sub);
	int aa;
	cin >> aa;
}