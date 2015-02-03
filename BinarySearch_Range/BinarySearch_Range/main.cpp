#include <iostream>

using namespace std;


//确定一个数在一个排序数组中的区间，即介于哪两个数之间

void BS_FindRegion(int* arr, int len, int target)
{
	if (arr == NULL || len <= 0)
		return;

	int i = 0; 
	int j = len - 1;
	while (i <= j)
	{
		int m = i + (j - i) / 2;
		if (arr[m] == target)
		{
			cout << target << " is in array" << endl;
			return;
		}
		else if (arr[m] < target)
		{
			i = m + 1;
		}
		else
		{
			j = m - 1;
		}
	}
	cout << target << " is in range: " << j << " " << i << endl;
}

int main()
{
	int arr[] = {1, 5, 23};
	BS_FindRegion(arr, sizeof(arr) / sizeof(int), -1);
	int aa;
	cin >> aa;
}