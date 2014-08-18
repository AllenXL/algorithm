#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) 
{
	int len = numbers.size();
	map<int, int> num_idx;
	for (int i = 0; i < len; i++)
	{
		num_idx[numbers[i]] = i;
	}
	for (int i = 0; i < len; i++)
	{
		int tmp = target - numbers[i];
		if (num_idx.find(tmp) != num_idx.end() && num_idx[tmp] != i)
		{
			vector<int> res;
			res.push_back(i + 1);
			res.push_back(num_idx[tmp] + 1);
			return res;
		}
	}
}

void main()
{
	int a[] = {3, 2, 4};
	vector<int> src(a, a+3);
	
	vector<int>& res = twoSum(src, 6);

	cout << res[0] << res[1] << endl;

	int aa;
	cin >> aa;
}