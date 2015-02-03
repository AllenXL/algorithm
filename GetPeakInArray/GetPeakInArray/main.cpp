#include <iostream>

using namespace std;


int getPeak(int* a, int n)
{
	if (a == NULL)
		return -1;
	if (n == 1)
		return 0;

	int peakIdx = 0;
	int peak = a[peakIdx];
	int max = peak;

	for (int i = 1; i < n; ++i)
	{
		if (a[i] < peak)
		{
			while (i < n && a[i] <= peak)
			{
				++i;
			}
			if (i < n)
			{
				peak = a[i];
				peakIdx = i;
				max = peak;
			}
			else
			{
				peakIdx = -1;
			}
		}
		else
		{
			max = a[i] > max ? a[i] : max;
		}
	}
	return peakIdx;
}


int main()
{
	int a[] = {7, 6, 5};
	cout << getPeak(a, 5) << endl;
	int aa;
	cin >> aa;
}