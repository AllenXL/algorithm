#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2)
{
	reverse(num1.begin(), num1.end()); //·½±ã¼ÆËã
	reverse(num2.begin(), num2.end());

	int n1 = num1.size();
	int n2 = num2.size();
	string res(n1 + n2, '0');

	int carry = 0;
	int tmp = 0;
	for (int i = 0; i < n2; ++i)
	{
		carry = 0;
		int v2 = num2[i] - '0';
		for (int j = 0; j < n1; ++j)
		{
			tmp = v2 * (num1[j] - '0') + (res[j + i] - '0') + carry;
			res[j + i] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		res[i + n1] = carry + '0';
	}

	int n = res.size() - 1;
	while (res[n] == '0' && n > 0)
		--n;
	res = res.substr(0, n + 1);
	reverse(res.begin(), res.end());
	return res;
}


int main()
{
	string str1("12");
	string str2("3");
	cout << multiply(str1, str2) << endl;
	int aa;
	cin >> aa;
	return 0;
}