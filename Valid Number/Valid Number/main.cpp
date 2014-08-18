#include <iostream>

using namespace std;

bool is_digit(const char& c)
{
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
bool isNumber(const char *s) 
{
	if (s == NULL)
		return false;

	while (*s == ' ')
	{
		s++;
	}

	if (*s == '+' || *s == '-')
		s++;

	bool hasDot = false;
	bool hasE = false;
	bool firstPart = false;
	bool secondPart = false;
	bool hasSpace = false;

	//前后允许有空格，点之前不允许有e，e之前可以有点
	while (*s != '\0')
	{
		if (*s == '+' || *s == '-')
		{
			if (hasSpace)
				return false;
			if (!hasE || !(*(s - 1) == 'e' || *(s - 1) == 'E'))
				return false;
		}

		else if (*s == '.')
		{
			if (hasDot || hasE || hasSpace)
				return false;
			else
			{
				hasDot = true;
			}
		}

		else if (*s == 'e' || *s == 'E')
		{
			if (hasE || !firstPart || hasSpace)
				return false;
			else
				hasE = true;
		}

		else if (is_digit(*s))
		{
			if (hasSpace)
				return false;
			if (!hasE)
			{
				firstPart = true;
			}
			else
				secondPart = true;
		}

		else if (*s == ' ')
		{
			hasSpace = true;
		}

		else
			return false;
		s++;
	}

	if (!firstPart)
		return false;
	else if (hasE && !secondPart)
		return false;
	else
		return true;
}

int main(void)
{
	char * str = "  +46.e-3  ";

	cout << isNumber(str) << endl;

	int aa;
	cin >> aa;
}