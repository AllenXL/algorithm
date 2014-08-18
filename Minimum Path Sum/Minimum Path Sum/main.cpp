#include <iostream>
#include <vector>
using namespace std;

//dp
int minPathSum(vector<vector<int> > &grid)
{
	if (grid.size() == 0 || grid[0].size() == 0)
		return 0;

	int m = grid.size();
	int n = grid[0].size();

	vector<vector<int> > f(m, vector<int>(n));
	f[0][0] = grid[0][0];
	for (int j = 1; j < n; ++j)
	{
		f[0][j] = f[0][j - 1] + grid[0][j];
	}

	for (int i = 1; i < m; ++i)
	{
		f[i][0] = f[i - 1][0] + grid[i][0];
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			int a = f[i - 1][j] + grid[i][j];
			int b = f[i][j - 1] + grid[i][j];
			f[i][j] = a < b ? a : b;
		}
	}
	return f[m - 1][n - 1];
}


int main(void)
{
	int aa;
	cin >> aa;
}