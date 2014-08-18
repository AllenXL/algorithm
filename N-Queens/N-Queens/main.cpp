#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
n�ʺ����⣬���������n��n�����У�ÿ�з�һ�����ӣ�ʹ���������ڵ��к�����б����û���������ӣ�ö�����п��ܡ�
dfsȥ�������������п��ܣ�row�м�¼ÿһ�����ӵ�λ�ã�col��¼��ǰ���Ƿ������ӣ��Խ��ߵ��жϾ��������в�ֵ���в�ֵ�Ƿ���ͬ��
 
��dfs��ȴﵽnʱ���ͱ�ʾ�������������Ľ⣬�ѵ�ǰ״̬ͼ�浽����С�
 
temp��n, '.'���Ȱ��ַ���ȫ����ֵ�� �� . ' ���ڰɴ������ӵ�λ�øĳɡ�Q��
*/

void dfs(int r, int n, vector<int>& row, vector<int>& col, vector<vector<string> >& result)
{
	if (r == n)
	{
		vector<string> res;
		for (int i = 0; i < n; ++i)
		{
			string tmp(n, '.');
			tmp[row[i]] = 'Q';
			res.push_back(tmp);
		}
		result.push_back(res);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (col[i] == 0)
		{
			int j;
			for (j = 0; j < r; ++j)
			{
				if ((r - j) == abs(i - row[j]))
					break;
			}
			if (j == r)
			{
				col[i] = 1;
				row[r] = i;
				dfs(r + 1, n, row, col, result);
				col[i] = 0;
				row[r] = -1;
			}
		}
	}

}

vector<vector<string> > solveNQueens(int n)
{
	vector<vector<string> > result;
	vector<int> row(n, -1);
	vector<int> col(n, 0);
	dfs(0, n, row, col, result);
	return result;
}

void show(vector<vector<string> > & result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << endl;
		}
		cout << endl << endl;
	}
}

int main()
{
	show(solveNQueens(4));
	int aa;
	cin >> aa;
	return 0;
}