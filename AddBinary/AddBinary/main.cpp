#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
	string res;
	
	int a_idx = a.size() - 1;
	int b_idx = b.size() - 1;

	int flag = 0;

	while (a_idx >= 0 && b_idx >= 0)
	{
		int total = flag + (a[a_idx] - '0') + (b[b_idx] - '0');
		int cur = total % 2;
		flag = total / 2;
		res = char(cur + '0') + res;
		
		a_idx--;
		b_idx--;
	}

	while (a_idx >= 0)
	{
		int total = a[a_idx] - '0' + flag;
		int cur = total % 2;
		flag = total / 2;
		res = char(cur + '0') + res;

		a_idx--;
	}

	while (b_idx >= 0)
	{
		int total = b[b_idx] - '0' + flag;
		int cur = total % 2;
		flag = total / 2;
		res = char(cur + '0') + res;

		b_idx--;
	}

	if (flag > 0)
		res = char(flag + '0') + res;

	return res;
}

int main(void)
{
	string a("1");
	string b("111");
	cout << addBinary(a, b) << endl;
	int aa;
	cin >> a;
	return 0;
}