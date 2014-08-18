#include <iostream>

using namespace std;

//ֱ��һ�����ӣ���ʱ
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

//���ƶ��ַ�
//���͵Ķ��ַ�����87��4������ (4 * 2 = 8) => (8 * 2 = 16) => (16 * 2 = 32) => (32 * 2) => 64����Ϊ64 * 2 = 128����87���������ǿ���ȷ��4 * 16 = 64С��87��
//��ô�ٴ���87 - 64 = 23��23��4�Ļ������淽�����Եõ�5������3����ΪС��4���ӵ��������������16 + 5 = 21��

//�μ�http://blog.csdn.net/pickless/article/details/9150617
//�漰������������Ż���һ�㷽���������ö��֡�
//���裺����Ҫ��Ľ���[a, b]�С�
//divisor * (a + b) / 2 > dividend => ����[a, (a + b) / 2 - 1]�У�
//divisor * (a + b) / 2 == dividend => ��Ϊ(a + b) / 2��
//divisor * (a + b) / 2 < dividend => ����[(a + b) / 2 + 1, b]�л��߽����(a + b) / 2�� 
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

//��ͬ˼·������*��ʵ�ֳ˷�����
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