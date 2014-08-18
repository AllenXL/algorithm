#include <iostream>
#include <vector>
#include <map>

using namespace std;

//����I
int maxProfit1(vector<int> &prices) 
{
	int len = prices.size();

	if (len == 0)
		return 0;

	map<int, int> max_map;
	int max = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (prices[i] > max)
			max = prices[i];
		max_map[i] = max;
	}

	int res = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int tmp;
		tmp = max_map[i + 1] - prices[i];

		if (tmp > res)
			res = tmp;
	}
	return res;
}

//����II
//���������ߵ����������εĳ��Ⱥ�
int maxProfit2(vector<int> &prices) 
{
	int len = prices.size();
	int res = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if (prices[i] < prices[i + 1])
			res += prices[i + 1] - prices[i];
	}
	return res;
}

//����III, �����Σ��ֱ������ֵ����ʱ
int maxProfit3(vector<int> &prices)
{
	int res = 0;
	int tmp_res = 0;
	int len = prices.size();

	for (int i = 2; i <= len; ++i)
	{
		vector<int> a(prices.begin(), prices.begin() + i);
		vector<int> b(prices.begin() + i - 1, prices.end());
		tmp_res = maxProfit1(a) + maxProfit1(b);
		if (tmp_res > res)
			res = tmp_res;
	}
	return res;
}

//����III�� �ܿ��ظ�����
int maxProfit4(vector<int> &prices)
{
	int res = 0;
	int len = prices.size();

	if (len == 0)
		return res;

	vector<int> l(len, 0);//l[i] Ϊ��0~i����һ�ν��׵��������
	vector<int> r(len, 0); //r[i] Ϊ��i~(len - 1)����һ�ν��׵��������

	int min = prices[0]; 
	for (int i = 1; i < len; i++)
	{
		l[i] = (prices[i] - min) > l[i - 1] ? (prices[i] - min) : l[i - 1];
		min = min < prices[i] ? min : prices[i];
	}

	int max = prices[len - 1];
	for (int i = len - 2; i >= 0; i--)
	{
		r[i] = (max - prices[i]) > r[i + 1] ? (max - prices[i]) : r[i + 1];
		max = max > prices[i] ? max : prices[i]; 
	}

	for (int i = 0; i < len; i++)
	{
		int tmp = l[i] + r[i];
		if (tmp > res)
			res = tmp;
	}
	return res;

}

void main()
{

	vector<int> vec;
	int a[5] = {1, 2, 1, 10, 3};
	vec.assign(a, a+5);

	cout << maxProfit4(vec) << endl;
	
	int aa;
	cin >> aa;
}