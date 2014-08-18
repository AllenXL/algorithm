#include <iostream>
#include <string>

using namespace std;

string intToRoman(int num)
{
	string res;
	const int ints[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };  
    const char* romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int len = sizeof(ints) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		while (num >= ints[i])
		{
			num -= ints[i];
			res.append(romans[i]);
		}
	}

	return res;
}

int romanToInt(string s)
{
	int res = 0;

	const int ints[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };  
    const char* romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	int len = sizeof(ints) / sizeof(int);

	for (int i = 0; i < len; ++i)
	{
		string roman(romans[i]);
		int l = roman.size();

		while (s.substr(0, l) == roman)
		{
			s.erase(0, l);
			res += ints[i];
		}
	}

	return res;
}


int main(void)
{
	int num = 7;
	cout << intToRoman(num) << endl;

	cout << romanToInt("VII") << endl;
	int aa;
	cin >> aa;
	return 0;
}