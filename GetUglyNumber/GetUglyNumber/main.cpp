#include <iostream>

using namespace std;

//get idx-th ugly number
//an ugly number only contains factors of 2, 3, 5

int min(int a, int b, int c)
{
	int res = 0;
	res = a < b ? a : b;
	res = res < c ? res : c;
	return res;
}
int GetUglyNumber(int idx)
{
	int* arr = new int[idx];
	arr[0] = 1;
	
	int i = 1;
	int i2 = 0;
	int i3 = 0;
	int i5 = 0;

	while (i < idx)
	{
		arr[i] = min(arr[i2] * 2, arr[i3] * 3, arr[i5] * 5);

		while (arr[i2] * 2 <= arr[i])
			i2++;
		while (arr[i3] * 3 <= arr[i])
			i3++;
		while (arr[i5] * 5 <= arr[i])
			i5++;
		i++;
	}

	int res = arr[i - 1];
	delete[] arr;
	return res;
}

int main()
{
	cout << GetUglyNumber(7) << endl;
	int aa;
	cin >> aa;
}