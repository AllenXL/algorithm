#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//method1 递归  超时
/*void dfs(vector<int>& num, int idx, int cur_sum, vector<int>& path, vector<vector<int> >& res)
{
	if (path.size() == 3 && cur_sum == 0)
	{
		res.push_back(path);
		return;
	}

	for (int i = idx; i < num.size(); ++i)
	{
		//if (i > idx && num[i] == num[i - 1])
		//	continue;
		cur_sum += num[i];
		path.push_back(num[i]);
		dfs(num, i + 1, cur_sum, path, res);
		path.pop_back();
		cur_sum -= num[i];

		while (i < num.size() - 1 && num[i] == num[i + 1]) i++;
	}
}

vector<vector<int> > threeSum(vector<int> &num)
{
	sort(num.begin(), num.end());
	vector<int> path;
	vector<vector<int> > res;
	dfs(num, 0, 0, path, res);
	return res;
}*/


//method2 转换为2sum问题
vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > res;
	if (num.size() < 3)
		return res;
	sort(num.begin(), num.end());
	vector<int> tmp;
	for (int i = 0; i < num.size(); ++i)
	{
		if (i > 0 && num[i] == num[i - 1])
			continue;
		//int target = -num[i];
		int begin = i + 1;
		int end = num.size() - 1;
		
		while (begin < end)
		{
			int sum = num[i] + num[begin] + num[end];
			if (sum == 0)
			{
				tmp.clear();
				tmp.push_back(num[i]);
				tmp.push_back(num[begin]);
				tmp.push_back(num[end]);
				res.push_back(tmp);
				//注意： 一定要跳过重复元素， 否则一直提示超时
                while(begin < end && num[begin] == num[begin + 1])
				{
					begin++;
                }
				while (end> begin && num[end] == num[end - 1])
				{
					end--;
				}
				begin++;
				end--;
			}
			else if (sum < 0)
			{
				while(begin < end && num[begin] == num[begin + 1])
				{
					begin++;
                }
				begin++;
			}
			else
			{
				while (end> begin && num[end] == num[end - 1])
				{
					end--;
				}
				end--;
			}
		}
	}
	return res;
}

//3sum closest方法同上
int threeSumClosest(vector<int> &num, int target)
{
	int res;
	bool flag = true;
	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); ++i)
	{
		if (i > 0 && num[i] == num[i - 1])
			continue;
		//int target = -num[i];
		int begin = i + 1;
		int end = num.size() - 1;
		
		while (begin < end)
		{
			int sum = num[i] + num[begin] + num[end];

			if (flag)
			{
				res = sum;
				flag = false;
			}
			else
			{
				if (abs(sum - target) < abs(res - target))
					res = sum;
			}

			if (sum == target)
			{
				return sum;
			}
			else if (sum < target)
			{
				while(begin < end && num[begin] == num[begin + 1])
				{
					begin++;
                }
				begin++;
			}
			else
			{
				while (end> begin && num[end] == num[end - 1])
				{
					end--;
				}
				end--;
			}
		}
	}
	return res;
}


//4sum
vector<vector<int> > fourSum(vector<int> &num, int target)
{
	vector<vector<int> > res;
	vector<int> tmp;
	if (num.size() < 4)
		return res;

	sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); ++i)
	{
		if (i != 0 && num[i] == num[i - 1])
			continue;
		for (int j = i + 1; j < num.size(); ++j)
		{
			if (j > i + 1 && num[j] == num[j - 1])
				continue;

			//2sum
			int begin = j + 1;
			int end = num.size() - 1;

			while (begin < end)
			{
				int sum = num[i] + num[j] + num[begin] + num[end];

				if (sum == target)
				{
					tmp.clear();
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[begin]);
					tmp.push_back(num[end]);
					res.push_back(tmp);

					//跳过重复点
					while (begin < end && num[begin] == num[begin + 1])
						begin++;
					while (end > begin && num[end] == num[end - 1])
						end--;
					begin++;
					end--;
				}
				else if (sum < target)
				{
					while (begin < end && num[begin] == num[begin + 1])
						begin++;
					begin++;
				}
				else if (sum > target)
				{
					while (end > begin && num[end] == num[end - 1])
						end--;
					end--;
				}
			}

		}
	}
	return res;
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(0);

	vector<vector<int> > res;
	res = fourSum(num, 3);

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	//cout << threeSumClosest(num, -100) << endl;

	int aa;
	cin >> aa;
}