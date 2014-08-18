#include <iostream>

using namespace std;

//二分法的变形
int search(int A[], int n, int target) 
{
	if (A == NULL || n == 0)
		return -1;

	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == target)
			return m;
		else if (A[m] < target)
		{
			if (A[l] <= A[m])
			{
				l = m + 1;
			}
			else
			{
				if (A[r] >= target)
					l = m + 1;
				else
					r = m - 1;
			}
		}
		else
		{
			if (A[l] <= A[m])
			{
				if (A[l] <= target)
					r = m - 1;
				else
					l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}

	return -1;

}

//Search in Rotated Sorted Array II
bool search2(int A[], int n, int target)
{
	if (A == NULL || n == 0)
		return false;

	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == target)
			return true;
		else if (A[m] == A[l] && A[m] == A[r])
		{
			--r;
			++l;
		}
		else if (A[m] < target)
		{
			if (A[l] <= A[m])
			{
				l = m + 1;
			}
			else
			{
				if (A[r] >= target)
					l = m + 1;
				else
					r = m - 1;
			}
		}
		else
		{
			if (A[l] <= A[m])
			{
				if (A[l] <= target)
					r = m - 1;
				else
					l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}

	return false;
}

int main(void)
{
	int A[] = {1, 1, 3, 1};
	cout << search2(A, 4, 3) << endl;
	int aa;
	cin >> aa;
}