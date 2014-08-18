#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = l + (r - l) / 2;

		if (A[m] == target)
			return m;
		else if (A[m] > target)
		{
			r = m -1;
		}
		else
		{
			l = m + 1;
		}
	}

	return l;
}

int main()
{
	int A[] = {1, 3, 5, 6};
	cout << searchInsert(A, 4, 7) << endl;
	int a;
	cin >> a;
}