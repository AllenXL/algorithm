#include <iostream>

using namespace std;

//����һ������S,��ӡ�����к�ΪS������������������(����2��)
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