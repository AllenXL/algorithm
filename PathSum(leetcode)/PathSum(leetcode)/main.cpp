// Flatten Binary Tree to Linked List (leetcode).cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void dfs(TreeNode* root, int cur_sum, int expect_sum, bool& flag)
{
	cur_sum += root -> val;
	if (root -> left == NULL && root -> right == NULL)
	{
		if (cur_sum == expect_sum)
		{
			flag = true;
		}
		cur_sum -= root -> val;
		return;
	}

    if (root -> left != NULL)
		dfs(root -> left, cur_sum, expect_sum, flag);
	if (root -> right != NULL)
		dfs(root -> right, cur_sum, expect_sum, flag);

	cur_sum -= root -> val;

}

bool hasPathSum(TreeNode *root, int sum)
{
	if (root == NULL)
		return false;
	bool flag = false;
	dfs(root, 0, sum, flag);
	return flag;
}



//Path Sum II
vector<vector<int> > res;
void findPath(TreeNode* root, int& cur_sum, int& expect_sum, vector<int>& cur_path)
{
	cur_sum += root -> val;
	cur_path.push_back(root -> val);
	if (root -> left == NULL && root -> right == NULL)
	{
		if (cur_sum == expect_sum)
		{
			res.push_back(cur_path);
			cur_sum -= root -> val;
			cur_path.pop_back();
			return;
		}
	}

	if (root -> left != NULL)
		findPath(root -> left, cur_sum, expect_sum, cur_path);
	if (root -> right != NULL)
		findPath(root -> right, cur_sum, expect_sum, cur_path);

	cur_sum -= root -> val;
	cur_path.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) 
{
	res.clear();
	if (root == NULL)
		return res;
	vector<int> cur;
	int cur_sum = 0;
	findPath(root, cur_sum, sum, cur);
	return res;
}

int main(void)
{
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(5);

	root -> left -> left = new TreeNode(3);
	root -> left -> right = new TreeNode(4);
	root -> right -> right = new TreeNode(6);

	cout << hasPathSum(root, 12) << endl;
	int aa;
	cin >> aa;

	return 0;
}

