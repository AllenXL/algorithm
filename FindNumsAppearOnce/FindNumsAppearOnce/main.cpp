#include <iostream>

using namespace std;

int FindFistBit1(int num)
{
	int i = 1;
	int idx = 0;
	while (i)
	{
		if (num & i > 0)
		{
			return idx;
		}
		else
		{
			i << 1;
			idx++;
		}
	}
}

bool IsBit1(int num, int idx)
{
	int i = 1;
	i = i << idx;
	return num & i;
}

void FindNumsAppearOnce(int* data, int len, int* num1, int* num2)
{
	if (data == NULL || len < 2)
		return;

	int ORdata = 0;
	for (int i = 0; i < len; ++i)
		ORdata ^= data[i];

	int indexOf1 = FindFistBit1(ORdata);

	for (int i = 0; i < len; ++i)
	{
		if (IsBit1(data[i], indexOf1))
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

//除了2个数，其他数都出现两次
int main()
{
	int arr[] = {1, 3, 1, 4};
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(arr, sizeof(arr) / sizeof(int), &num1, &num2);
	cout << num1 << endl;
	cout << num2 << endl;
	int aa;
	cin >> aa;
}