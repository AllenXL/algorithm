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

	for (int i = idx; i < num.size(); ++i)  //��ʵ����swap, ��һ������canUse��Ǹ������Ƿ����Ѿ�ʹ�ã�Ҳ�ǿ��Ե�
	{
		int j;
		for (j = idx; j < i; j++)
		{
			if (num[j] == num[i])  //ȥ��
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
	//sort(num.begin(), num.end()); ����������Ϊ����տ�ʼ�ź����ˣ�����swap�Ժ��ǻ���
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