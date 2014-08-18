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

void dfs(int r, int n, vector<int>& row, vector<int>& col, int& result)
{
	if (r == n)
	{
		result++;
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

int totalNQueens(int n) 
{
	int result = 0;
	vector<int> row(n, -1);
	vector<int> col(n, 0);
	dfs(0, n, row, col, result);
	return result;
}

int main()
{
	cout << totalNQueens(4) << endl;
	int aa;
	cin >> aa;
	return 0;
}