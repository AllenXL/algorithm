#include <iostream>
#include <vector>
#include <string>

using namespace std;

//f(i,j) = min(f(i+1, j), f(i+1, j+1));
//递归，超时
/*int min_sum(vector<vector<int>>& nums, int i, int j)
{
	cout << i << " " << j << endl;
	if (i == nums.size() - 1)
		return nums[i][j];

	int l = nums[i][j] + min_sum(nums, i + 1, j);
	int r = nums[i][j] + min_sum(nums, i + 1, j + 1);

	return l > r ? r : l;
}

int minimumTotal(vector<vector<int> > &triangle) 
{
	return min_sum(triangle, 0, 0);
}*/


//dfs, memory limit exceed

/*void dfs(vector<vector<int>>& nums, int i, int j, int& sum, int& cur_min)
{
	if (i == nums.size() - 1)
	{
		if (sum < cur_min)
			cur_min = sum;
		return;
	}

	sum += nums[i][j];
	dfs(nums, i + 1, j, sum, cur_min);
	dfs(nums, i + 1, j + 1, sum, cur_min);
	sum -= nums[j][j];
}

int minimumTotal(vector<vector<int> > &triangle) 
{
	int sum = 0;
	int min = 9999999;
	dfs(triangle, 0, 0, sum, min);

	return min;
}*/

//dp, 还是用前面的公式f(i,j) = min(f(i+1, j), f(i+1, j+1));
int minimumTotal(vector<vector<int> > &triangle) 
{
	int rows = triangle.size();
	vector<int> sum_vec(triangle[rows-1]);

	for (int i = rows - 2; i >=0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			int l = triangle[i][j] + sum_vec[j];
			int r = triangle[i][j] + sum_vec[j + 1];
			sum_vec[j] = l < r ? l : r;
		}
	}
	return sum_vec[0];
}





int main()
{

	vector<vector<int> > tr(4);

	tr[0].push_back(2);

	tr[1].push_back(3);
	tr[1].push_back(4);

	tr[2].push_back(6);
	tr[2].push_back(5);
	tr[2].push_back(7);

	tr[3].push_back(4);
	tr[3].push_back(1);
	tr[3].push_back(8);
	tr[3].push_back(3);



	cout << minimumTotal(tr) << endl;

	int aa;
	cin >> aa;
}