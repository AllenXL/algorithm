#include <iostream>

using namespace std;

//输入一个正数S,打印出所有和为S的所有连续正数序列(至少2个)
void FindContinuousSeq(int sum)
{
	int i = 1;
	int j = 2;
	int s = i + j;
	int m = (sum + 1) / 2;
	while (i < m)
	{
		if (s == sum)
		{
			cout << i << " " << j << endl;
			j++;
			s += j;
		}
		else if (s > sum)
		{
			s -= i;
			i++;
		}
		else
		{
			j++;
			s += j;
		}
	}
}


int main()
{
	FindContinuousSeq(15);
	int aa;
	cin >> aa;
}