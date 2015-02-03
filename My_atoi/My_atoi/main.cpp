#include <iostream>

using namespace std;

int my_atoi(const char *s)
{
	if (s == NULL || strlen(s) == 0)
		return 0;

	int i = 0;
	long long res = 0;
	bool isPos = true;

	while (s[i] == ' ')
		++i;

	if (s[i] == '-')
	{
		isPos = false;
		++i;
	}
	else if (s[i] == '+')
		++i;

	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		if ((isPos && res > INT_MAX) || (!isPos && res - 1 > INT_MAX))
		{
			return 0;
		}
		++i;
	}

	if (!isPos)
	{
		res = -res;
	}

	return (int)res;

}



int main()
{
	char s[] = "-123abc";
	cout << my_atoi(s) << endl;

	int aa;
	cin >> aa;
	return 0;
}