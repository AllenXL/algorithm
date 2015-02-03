#include <iostream>

using namespace std;

//计算数字在排序数组中出现的次数
//用二分法分别得到该数字的左右边界
int GetFirstK(int* data, int len, int target)
{
	if (data == NULL || len == 0)
		return -1;

	int i = 0;
	int j = len - 1;

	while (i <= j)
	{
		int m = i + (j - i) / 2;

		if (data[m] == target)
		{
			if ((m > 0 && data[m - 1] != target) || m == 0)
			{
				return m;
			}
			else
			{
				j = m - 1;
			}
		}
		else if (data[m] > target)
		{
			j = m - 1;
		}
		else
		{
			i = m + 1;
		}
	}
	return -1;
}

int GetLastK(int* data, int len, int target)
{
	if (data == NULL || len == 0)
		return -1;

	int i = 0;
	int j = len - 1;

	while (i <= j)
	{
		int m = i + (j - i) / 2;

		if (data[m] == target)
		{
			if (m ==  len - 1 || (m < len - 1 && data[m + 1] != target))
			{
				return m;
			}
			else
			{
				i = m + 1;
			}
		}
		else if (data[m] > target)
		{
			j = m - 1;
		}
		else
		{
			i = m + 1;
		}
	}
	return -1;
}

int GetNumberOfK(int* data, int len, int k)
{
	int left = GetFirstK(data, len, k);
	int right = GetLastK(data, len, k);

	if (left > -1 && right > -1)
		return right - left + 1;
	else
		return 0;
}

int main()
{
	int arr[] = {1, 2, 3, 3, 3}; //排序数组
	cout << GetNumberOfK(arr, sizeof(arr) / sizeof(int), 3) << endl;
	int aa;
	cin >> aa;
}