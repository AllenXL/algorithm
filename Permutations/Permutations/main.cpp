#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& num, int idx, vector<int>& permute, vector<vector<int> >& result)
{
	if (idx == num.size())
	{
		result.push_back(permute);
		return;
	}

	for (int i = idx; i < num.size(); ++i)  //其实不用swap, 用一个数组canUse标记各个数是否已已经使用，也是可以的
	{
		swap(num[idx], num[i]);
		permute.push_back(num[idx]);
		dfs(num, idx + 1, permute, result);
		permute.pop_back();
		swap(num[idx], num[i]);
	}
}


vector<vector<int> > permute(vector<int> &num)
{
	vector<vector<int> > result;
	vector<int> perm;
	dfs(num, 0, perm, result);
	return result;
}

void show(vector<vector<int> >& result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	show(permute(num));

	int aa;
	cin >> aa;
	return 0;
}