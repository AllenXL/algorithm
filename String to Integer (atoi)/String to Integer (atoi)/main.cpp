#include <iostream>
#include <string>

using namespace std;

int atoi(const char *str)
{
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '\0')
		return 0;

	bool isPos = true;
	if (*str == '+')
	{
		isPos = true;
		str++;
	}
	else if (*str == '-')
	{
		isPos = false;
		str++;
	}
	else
		isPos = true;

	long long num = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num = num * 10 + *str - '0';
			if (num > INT_MAX)
				return isPos ? INT_MAX : INT_MIN;
		}
		else
			break;
		str++;
	}

	if (!isPos)
	{
		num = -num;
	}
	return (int)num;
}

int main()
{
	cout << atoi("2147483648") << endl;
	cout << "finish" << endl;
	int aa;
	cin >> aa;
}