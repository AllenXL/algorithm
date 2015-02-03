#include <iostream>

using namespace std;

//������num�����ӣ��������γɵĸ���������

//����1��dfs�������е������������һ�飬�ȽϺ�ʱ
void GetProbabilities(int num, int idx, int& sum, int* probabilities)  //dfs
{
	if (idx == num)
	{
		probabilities[sum - num]++;
	}
	else
	{
		for (int i = 1; i <= 6; ++i)
		{
			sum += i;
			GetProbabilities(num, idx + 1, sum, probabilities);
			sum -= i;
		}
	}
}

void GetAllProbability(int num)
{
	int minSum = num;
	int maxSum = num * 6;

	int* probabilities = new int[maxSum - minSum + 1];
	for (int i = 0; i < maxSum - minSum + 1; ++i)
	{
		probabilities[i] = 0;
	}
	int sum = 0;
	GetProbabilities(num, 0, sum, probabilities); //����ÿ�ֵ����ͳ��ֵĴ���
	
	int total = pow(6.0, num);
	for (int i = 0; i < maxSum - minSum + 1; ++i)
	{
		double ratio = (probabilities[i] * 1.0 / total);
		cout << i + num << " : " << ratio << endl;
	}
	delete[] probabilities;
}

//����������̬�滮�����n-1�����ӵĵ��������֪����n�����ӵĵĵ�������Ϳ����Ƴ���
//���磬n-1������ʱ����Ϊ5���������3�Σ��Ƕ���n��������˵����3��Ӧ���ۼӵ���Ϊ6��7����������11�ĵ�����ȥ
//���߷�������Ҳ���ԣ�����n�����ӵ��������Ϊs�Ĵ���Ӧ����n-1��ɸ���У���Ϊs-1, s-2,...,s-6�ĵ��ӵĴ���֮��
//ʵ��ʱ�����Կ����������������㣬��ʵ����2�еĶ�ά����

void GetAllProbabilityDP(int num)
{
	if (num < 1)
		return;

	int* prob[2];
	int maxSum = 6 * num;
	prob[0] = new int[maxSum + 1]; //�������������Ӧ�Ĵ���
	prob[1] = new int[maxSum + 1];

	for (int i = 0; i < maxSum + 1; ++i)
	{
		prob[0][i] = 0;
		prob[1][i] = 0;
	}

	for (int i = 1; i <= 6; ++i) //1�����ӵ����
		prob[0][i] = 1;

	//��ʼdp����
	int flag = 1;
	for (int i = 2; i <= num; ++i)
	{
		for (int s = 0; s < i; ++s)
			prob[flag][s] = 0;
		for (int s = i; s <= 6 * i; ++s)
		{
			prob[flag][s] = 0;
			for (int k = 1; k < s && k <= 6; ++k)
			{
				prob[flag][s] += prob[1 - flag][s - k];
			}
		}
		flag = 1 - flag;
	}

	//������ʣ��������ܴ���
	int total = pow(6.0, num);
	for (int i = num; i < maxSum + 1; ++i)
	{
		double ratio = (prob[1 - flag][i] * 1.0 / total);
		cout << i << " : " << ratio << endl;
	}

}

int main()
{
	int num = 10;
	
	cout << "DP:" << endl;
	GetAllProbabilityDP(num);

	cout << "Recursive:" << endl;
	GetAllProbability(num);

	int aa;
	cin >> aa;
}