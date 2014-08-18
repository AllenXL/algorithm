#include <iostream>
#include <vector>

using namespace std;

//直接用公式算，涉及到阶乘，数据过大，故用dp
int uniquePaths(int m, int n)
{
	vector<vector<int> > f(m, vector<int>(n));

	for (int i = 0; i < m; ++i)
	{
		f[i][0] = 1;
	}

	for (int j = 0; j < n; ++j)
	{
		f[0][j] = 1;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	return f[m - 1][n - 1];
}


int main()
{
	cout << uniquePaths(19, 13);
	int aa;
	cin >> aa;
}