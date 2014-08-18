#include <iostream>
#include <vector>

using namespace std;

//可以参见：http://www.leetcode.com/2010/10/searching-2d-sorted-matrix.html
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	if (matrix.size() == 0)
		return false;

	int i = 0;
	int j = matrix[0].size() - 1;

	while (i < matrix.size() && j >= 0)
	{
		if (matrix[i][j] == target)
			return true;

		if (matrix[i][j] < target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return false;
}

int main(void)
{
	int aa;
	cin >> aa;
}