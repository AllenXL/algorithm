#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void show(vector<vector<T> >& matrix)
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

/*
基本思路是把图片分为行数/2层，然后一层层进行旋转，每一层有上下左右四个列，然后目标就是把上列放到右列，右列放到下列，下列放到左列，左列放回上列，
中间保存一个临时变量即可。因为每个元素搬运的次数不会超过一次，时间复杂度是O(矩阵的大小)，空间复杂度是O(1)。
*/

void rotate(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	int layerNum = n / 2;

	for (int i = 0; i < layerNum; ++i)
	{
		for (int j = i; j < n - 1 - i; ++j)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 -j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

int main()
{

	int aa;
	cin >> aa;
	return 0;
}
