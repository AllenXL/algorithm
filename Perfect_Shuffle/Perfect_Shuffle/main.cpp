#include <iostream>

using namespace std;


//http://www.tuicool.com/articles/rUju2m
//a1, a2, b1, b2 ->  b1, a1, b2, a2

//实际数组长度为2*n
void perfect_shuffle(int* a, int n)
{
	if (a == NULL || n <= 0)
		return;

	if (n == 1)
	{
		int tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
		return;
	}

	if (n % 2 == 1)
	{
		int tmp = a[n - 1];
		for (int i = n; i < 2 * n; ++i)
		{
			a[i - 1] = a[i];
		}
		a[2 * n - 1] = tmp;
		n--;
	}

	for (int i = n / 2; i <= n - 1; ++i)
	{
		int tmp = a[i];
		a[i] = a[i + n / 2];
		a[i + n / 2] = tmp;
	}

	perfect_shuffle(a, n / 2);
	perfect_shuffle(a + n, n / 2);
}

void show(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	perfect_shuffle(a, sizeof(a) / sizeof(int) / 2);
	show(a, sizeof(a) / sizeof(int));
	int aa;
	cin >> aa;
}