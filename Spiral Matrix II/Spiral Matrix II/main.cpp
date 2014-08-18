#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void show(vector<vector<T> > &a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[0].size(); ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//思路和spiral matrix一样
vector<vector<int> > generateMatrix(int n)
{
	int num = 1;
	int x1 = 0;
	int y1 = 0;
	int x2 = n - 1;
	int y2 = n - 1;

	vector<vector<int> > res(n, vector<int>(n));
	if (n == 0)
		return res;

	while (x1 <= x2 && y1 <= y2)
	{
		//top
		for (int j = y1; j <= y2; ++j)
		{
			res[x1][j] = num;
			num++;
		}
		//right
		for (int i = x1 + 1; i <= x2; ++i)
		{
			res[i][y2] = num;
			num++;
		}
		
		//bottom
		if (x1 != x2)
		{
			for (int j = y2 - 1; j >= y1; --j)
			{
				res[x2][j] = num;
				num++;
			}
		}

		//left
		if (y1 != y2)
		{
			for (int i = x2 - 1; i >= x1 +1; --i)
			{
				res[i][y1] = num;
				num++;
			}
		}
		x1++;
		y1++;
		x2--;
		y2--;
	}

	return res;
}

int main(void)
{
	show(generateMatrix(3));

	int aa;
	cin >> aa;
	return 0;
}