#include <iostream>
#include <string>

using namespace std;

//在一个数中找最大递增子数
//如123423，输出1234

int main()
{
	string str;
	cin >> str;

	int len = str.size();
	int max = 0;
	int tmp_num = str[0] - '0';

	for (int i = 1; i < len; ++i)
	{
		if (str[i] > str[i - 1])
		{
			tmp_num = tmp_num * 10 + str[i] - '0';
		}
		else
		{
			max = max < tmp_num ? tmp_num : max;
			tmp_num = str[i] - '0';
		}
	}
	max = max < tmp_num ? tmp_num : max; 
	cout << max << endl;

	int aa;
	cin >> aa;
}