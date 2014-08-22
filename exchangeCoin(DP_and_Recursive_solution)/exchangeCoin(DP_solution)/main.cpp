#include <iostream>

using namespace std;

//��һ�100ԪǮ����1,2,5,10����Ǯ�����ܹ��ж��ٶһ�����
//������̨�����⣬��dp�ⷨ��������̨�׸��ӣ�Ҫ�����ظ����⣬��Ϊ��̨������˳��ģ����һ�ʵ��������˳���޹صġ�
//cracking code interview p. 337 �еݹ�ⷨ�ͽ���

//f(i) = û�е�n�ֱ�ֵ����Ļ���������ֻ��ǰn - 1�ֱ�ֵ�Ķһ��������� + ���ٰ�����n�ֱ�ֵ�Ļ���������f(i - n)��

//ʵ���ϣ�����f(i, j)Ϊ��ǰi�ֻ��Ҷһ�jԪ����Ӧ���ܶһ�������ô������ĵ��ƹ�ʽ��f(i, j) = f(i-1, j) + f(i, j-i)
//����˵������һ�������㲻�����ƹ�ʽ��ʱ�򣬲����ٸ�һ��������Ҳ������Ƴ���ʽ
//��Ȼ�����ڸù�ʽ�����ԣ�ֻ��һά����Ϳ��Լ�¼�м���

void GetExchangeDP(int total, int* dimes, int types)  //total Ϊ��Ǯ���� dimes�洢����, types������
{
	int* dp = new int[total + 1];
	memset(dp, 0, (total + 1) * sizeof(int));
	dp[0] = 1;

	for (int i = 0; i < types; ++i)
	{
		for (int j = dimes[i]; j <= total; ++j)
		{
			dp[j] += dp[j - dimes[i]];
		}
	}

	//print result
	for (int i = 1; i <= total; ++i)
	{
		cout << dp[i] << endl;
	}
	return;
}

//�ݹ�ʵ��
//f(i, j) = f(i-1, j) + f(i, j-i)
int GetExchangeHelper(int total, int* dimes, int len)
{
	if (total == 0)
		return 1;
	else if (total < 0)
		return 0;

	if (dimes == NULL || len <= 0)
		return 0;

	return GetExchangeHelper(total, dimes, len - 1) + GetExchangeHelper(total - dimes[len - 1], dimes, len);
}

void GetExchangeRecur(int total, int* dimes, int len)
{
	cout << GetExchangeHelper(total, dimes, len) << endl;
}

//����һ��������ֽⷽ��
//ǰ���Ƿֽ�ɣ��һ���û��10ԪǮ���Լ�������һ��10ԪǮ�������
//���ڷֽ�ɣ��һ���û��10ԪǮ����һ��10ԪǮ��...����10��10ԪǮ
//f(i, j) = f(i - 1, j) + f(i - 1, j - dimes[j]) + f(i - 1, j - dimes[j] * 2) + ...
//ͬ��������DP�͵ݹ�ʵ�֣������õݹ�
int GetExchangeHelper2(int total, int* dimes, int len)
{
	if (total == 0)
		return 1;
	else if (total < 0)
		return 0;

	if (dimes == NULL || len <= 0)
		return 0;

	int cur = dimes[len - 1];
	int ways = 0;
	for (int i = 0; i <= total; i += cur)
	{
		ways += GetExchangeHelper2(total - i, dimes, len - 1);
	}
	return ways;
}

void GetExchangeRecur2(int total, int* dimes, int len)
{
	cout << GetExchangeHelper2(total, dimes, len) << endl;
}


int main()
{
	int money = 100;
	int dimes[] = {1, 2, 5, 10};

	cout << "DP result:" << endl;
	GetExchangeDP(money, dimes, sizeof(dimes) / sizeof(int));

	cout << "Recursive Result1:" << endl;
	GetExchangeRecur(money, dimes, sizeof(dimes) / sizeof(int));

	cout << "Recursive Result2:" << endl;
	GetExchangeRecur2(money, dimes, sizeof(dimes) / sizeof(int));

	int aa;
	cin >> aa;
}