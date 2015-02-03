#include <iostream>

using namespace std;

//判断大小端系统，若为小端，该函数返回1

bool is_little_edian()
{
	union t
	{
		int a;
		char b;
	};
	t x;
	x.a = 1;
	return x.b == 1;
}

int main()
{
	int x = 1;
	char* c = (char*)&x;
	cout << (int)*c << endl;
	cout << is_little_edian() << endl;

	size_t y = 1;
	cout << sizeof(y) << endl;

	int aa;
	cin >> aa;
}