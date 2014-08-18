#include <iostream>

using namespace std;

//直接一个个加，超时
/*int dividePos(int dividend, int divisor)
{
	if (divisor > dividend)
		return 0;
	int res = 0;
	while (divisor <= dividend)
	{
		res++;
		divisor += divisor;
	}
	return res;
}

int divide(int dividend, int divisor)
{
	bool flag = true;
	if (dividend < 0)
	{
		flag = !flag;
		dividend = -dividend;
	}
	if (divisor < 0)
	{
		flag = !flag;
		divisor = -divisor;
	}

	int res = dividePos(dividend, divisor);
	if (!flag)
		return -res;
	else
		return res;
}*/

//类似二分法
//典型的二分法。以87除4举例， (4 * 2 = 8) => (8 * 2 = 16) => (16 * 2 = 32) => (32 * 2) => 64，因为64 * 2 = 128大于87，现在我们可以确定4 * 16 = 64小于87，
//那么再处理87 - 64 = 23，23除4的话用上面方法可以得到5，还余3，因为小于4，扔掉，所以最后结果是16 + 5 = 21。

//参见http://blog.csdn.net/pickless/article/details/9150617
//涉及到这种问题的优化，一般方法都是利用二分。
//假设：我们要求的解在[a, b]中。
//divisor * (a + b) / 2 > dividend => 解在[a, (a + b) / 2 - 1]中；
//divisor * (a + b) / 2 == dividend => 解为(a + b) / 2；
//divisor * (a + b) / 2 < dividend => 解在[(a + b) / 2 + 1, b]中或者解就是(a + b) / 2。 
long long dividePos(long long dividend, long long divisor)
{
	if (divisor > dividend)
		return 0;
	long long res = 1;
	long long tmp = divisor;
	long long left = dividend;

	while ( tmp <= dividend)
	{
		left = dividend - tmp;
		tmp <<= 1;
		if (tmp > dividend)
			break;
		else
			res <<= 1;
	}
	return res + dividePos(left, divisor);
}

int divide(int dividend, int divisor)
{
	bool flag = true;
	if (dividend < 0)
	{
		flag = !flag;
	}
	if (divisor < 0)
	{
		flag = !flag;
	}

	int res = dividePos(abs((long long)dividend), abs((long long)divisor));
	if (!flag)
		return -res;
	else
		return res;
}

//相同思路，不用*，实现乘法运算
int multiplyPos(int x, int y)
{
	if (x == 0)
		return 0;
	int tmp = 1;
	int res = y;
	int left = 0;

	while (tmp <= x)
	{
		left = x - tmp;
		tmp <<= 1;

		if (tmp > x)
			break;
		else
			res <<= 1;
	}

	return res += multiplyPos(left, y);
}

int main()
{
	cout << divide(-1010369383, -2147483648) << endl;
	cout << multiplyPos(4, 5) << endl;
	int aa;
	cin >> aa;
}