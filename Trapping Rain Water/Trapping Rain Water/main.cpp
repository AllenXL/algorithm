#include <iostream>
#include <vector>
using namespace std;

/*
对某个值A[i]来说，能trapped的最多的water取决于在i之前最高的值leftMostHeight[i]和在i右边的最高的值rightMostHeight[i]（均不包含自身）。
*/

int trap(int A[], int n) 
{
	vector<int> leftMax(n, 0);
	vector<int> rightMax(n, 0);

	int max = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (A[i] > max)
			max = A[i];
		leftMax[i + 1] = max;
	}

	max = 0;
	for (int i = n - 1; i > 0; --i)
	{
		if (A[i] > max)
			max = A[i];
		rightMax[i - 1] = max;
	}

	int res = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		if (leftMax[i] > A[i] && rightMax[i] > A[i])
		{
			int tmpMax = leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i];
			res += tmpMax - A[i];
		}
	}
	return res;
}


int main()
{
	int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trap(A, sizeof(A) / sizeof(int)) << endl;
	int aa;
	cin >> aa;
	return 0;
}