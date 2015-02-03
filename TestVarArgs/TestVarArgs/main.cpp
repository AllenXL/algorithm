#include <iostream>
#include <stdarg.h>

using namespace std;

int average(int first, ...)
{
	int cnt = 0;
	int sum = 0;

	int i = first;
	va_list nums;
	va_start(nums, first);
	while (i != -1)
	{
		sum += i;
		cnt++;
		i = va_arg(nums, int);
	}
	va_end(nums);
	return cnt == 0 ? 0 : sum / cnt;
}

int main()
{
	cout << average(0, 0, -1) << endl;
	int aa;
	cin >> aa;
}