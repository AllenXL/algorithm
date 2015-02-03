#include <iostream>

using namespace std;

//假设有num个骰子，将其能形成的各个点数和

//方法1：dfs，把所有点数情况都搜索一遍，比较耗时
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
	GetProbabilities(num, 0, sum, probabilities); //计算每种点数和出现的次数
	
	int total = pow(6.0, num);
	for (int i = 0; i < maxSum - minSum + 1; ++i)
	{
		double ratio = (probabilities[i] * 1.0 / total);
		cout << i + num << " : " << ratio << endl;
	}
	delete[] probabilities;
}

//方法二：动态规划，如果n-1个骰子的点数情况已知，求n个骰子的的点数情况就可以推出来
//比如，n-1个骰子时，和为5的情况共有3次，那对于n个骰子来说，这3次应该累加到和为6、7、。。。、11的点数上去
//或者反过来推也可以，对于n个骰子的情况，和为s的次数应该是n-1个筛子中，和为s-1, s-2,...,s-6的点子的次数之和
//实现时，可以开辟两个数组来计算，其实就是2行的二维数组

void GetAllProbabilityDP(int num)
{
	if (num < 1)
		return;

	int* prob[2];
	int maxSum = 6 * num;
	prob[0] = new int[maxSum + 1]; //保存点数和所对应的次数
	prob[1] = new int[maxSum + 1];

	for (int i = 0; i < maxSum + 1; ++i)
	{
		prob[0][i] = 0;
		prob[1][i] = 0;
	}

	for (int i = 1; i <= 6; ++i) //1个骰子的情况
		prob[0][i] = 1;

	//开始dp计算
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

	//计算概率，即除以总次数
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