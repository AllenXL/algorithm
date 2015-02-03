#include <iostream>

using namespace std;


//����������Ĵ���mancher�㷨��ʱ�临�Ӷ�ΪO(n)
//ͨ����¼��ƥ�������λ�úͶ�Ӧ�ĶԳ�����������һЩû�õıȽ�

int Manacher(char* s)
{
	int len = strlen(s);
	if (s == NULL || len == 0 || len == 1)
		return 0;

	int* rad = new int[len * 2 + 2]; //��ĳ�ַ�Ϊ���ģ����������ţ�rad�б����Ӧ�뾶(����������), �պ�Ϊʵ�ʻ��ĳ���
	char* str = new char[len * 2 + 3];
	str[0] = '$';
	str[1] = '#';

	int n = 2;
	for (int i = 0; i < len; ++i)
	{
		str[n++] = s[i];
		str[n++] = '#';
	}
	str[n++] = '\0';

	cout << str << endl;

	rad[0] = 0;
	int c = 0;
	int r = 0;

	len = len * 2 + 2;
	for (int i = 1; i < len; ++i)
	{
		if (r > i)
		{
			rad[i] = min(rad[2 * c - i], r - i);
		}
		else
		{
			rad[i] = 0;
		}

		while (str[i + rad[i] + 1] == str[i - rad[i] - 1]) rad[i]++;  //���ǰ��û��str[0] = '$', ִ����仰ʱ�ܿ���Խ��

		if (i + rad[i] > r)
		{
			r = i + rad[i];
			c = i;
		}
	}

	int res = 0;
	for (int i = 1; i < len; ++i)
	{
		res = max(res, rad[i]);
	}

	delete[] rad;
	delete[] str;
	return res;
}

int main()
{
	int n;
	cin >> n;
	char s[1000100] = {0};

	while (n--)
	{
		cin >> s;
		cout << Manacher(s) << endl;
	}

	return 0;
}