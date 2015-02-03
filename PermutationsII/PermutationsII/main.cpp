#include <iostream>
#include <vector>
#include <algorithm>

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
		int j;
		for (j = idx; j < i; j++)
		{
			if (num[j] == num[i])  //swap以后其实已经乱序了，所以没必要sort，需要逐位比较。
				                   //如0, 1， 2， 2， 2， 5  -> 2， 1， 2， 0， 2， 5  中间连续的2在swap后已经断了
				break;
		}
		if (j == i)
		{
			swap(num[idx], num[i]);
			permute.push_back(num[idx]);
			dfs(num, idx + 1, permute, result);
			permute.pop_back();
			swap(num[idx], num[i]);
		}
	}
}

vector<vector<int> > permuteUnique(vector<int> &num)
{
	vector<vector<int> > result;
	vector<int> perm;
	//sort(num.begin(), num.end()); 不用排序，因为就算刚开始排好序了，后面swap以后还是会乱
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
	num.push_back(0);
	num.push_back(1);
	num.push_back(0);
	num.push_back(0);
	num.push_back(9);
	show(permuteUnique(num));

	int aa;
	cin >> aa;
	return 0;
}