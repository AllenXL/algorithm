#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int>& candidate, int idx, int& cur_sum, int& target, vector<int>& cur_vec, vector<vector<int> >& res)
{
	if (cur_sum == target)
	{
		res.push_back(cur_vec);
		return;
	}
	if (idx == candidate.size() || cur_sum > target)
		return;
	
	for (int i = idx; i < candidate.size() && (cur_sum + candidate[i]) <= target; ++i)
	{
		cur_sum += candidate[i];
		cur_vec.push_back(candidate[i]);
		dfs(candidate, i, cur_sum, target, cur_vec, res);
		cur_sum -= candidate[i];
		cur_vec.pop_back();
	}
}


vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
	vector<vector<int> > res;
	if (candidates.size() == 0)
		return res;

	sort(candidates.begin(), candidates.end());

	vector<int> cur_vec;
	int cur_sum = 0;
	dfs(candidates, 0, cur_sum, target, cur_vec, res);
	return res;
}

void show(vector<vector<int> >& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector<int> in;
	in.push_back(2);
	in.push_back(3);
	in.push_back(6);
	in.push_back(7);
	vector<vector<int> > out;
	out = combinationSum(in, 7);
	show(out);
	int aa;
	cin >> aa;
	return 0;
}