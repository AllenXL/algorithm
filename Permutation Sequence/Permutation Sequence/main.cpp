#include <iostream>
#include <string>
#include <vector>

using namespace std;

//n������ȫ���У������򣩣�ȡ��k������ʵ���Ͽ���һλλ��ȷ������
string getPermutation(int n, int k)
{
	string res;
	if (n <= 0 || k <= 0)
		return res;

	vector<int> factories(n);
	factories[0] = 1;
	factories[1] = 1;
	for (int i = 2; i < n; ++i)
	{
		factories[i] = factories[i - 1] * i;
	}

	bool flag[10] = {false};  //����Ƿ񱻷��ʹ�
	for (int i = 1; i <= n; ++i)  //����ȷ����λ
	{
		int temp = k / factories[n - i]; //ȷ���ڼ�����
		k = k % factories[n - i];

		if (k == 0)  //�����Ͳ��������
		{
			k = factories[n - i];
		}
		else
			temp++;

		for (int j = 1; j <= n; ++j)
		{
			if (!flag[j]) temp--;
			if (temp == 0)
			{
				flag[j] = true;
				res += j + '0';
				break;
			}

		}
		
	}
	return res;
}

int main()
{
	cout << getPermutation(3, 2) << endl;
	int aa;
	cin >> aa;
	return 0;
}