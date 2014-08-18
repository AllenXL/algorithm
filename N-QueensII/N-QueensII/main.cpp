#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

/*
n皇后问题，题意就是求n×n矩阵中，每行放一个棋子，使得棋子所在的列和两条斜线上没有其他棋子，枚举所有可能。
dfs去遍历，考虑所有可能，row中记录每一行棋子的位置，col记录当前列是否有棋子，对角线的判断就是两点行差值和列差值是否相同。
 
当dfs深度达到n时，就表示存在满足条件的解，把当前状态图存到结果中。
 
temp（n, '.'）先把字符串全部赋值成 ‘ . ' ，在吧存在棋子的位置改成’Q‘
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