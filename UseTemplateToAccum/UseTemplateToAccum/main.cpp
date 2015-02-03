#include <iostream>

using namespace std;

enum ERR_CODE
{
	EC_ERROR = 100,
	EC_BODY = 2
};

/*º∆À„1+2+...+N
template <unsigned int N>
class sum
{
public:
	enum {n = sum<N - 1>::n + N};
};


template <>
class sum<1>
{
public:
	enum {n = 1};
};*/

template <int N>
class sum
{
public:
	static int get_sum()
	{
		return N + sum<N - 1>::get_sum();
	}
};

template <>
class sum<1>
{
public:
	static int get_sum()
	{
		return 1;
	}
};

int main()
{
	ERR_CODE a;
	a = EC_BODY;
	cout << a << endl;

	cout << sum<5>::get_sum() << endl;

	int aa;
	cin >> aa;
}