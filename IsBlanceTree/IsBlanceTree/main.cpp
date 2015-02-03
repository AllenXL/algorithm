#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//method 1
bool IsBlanceTreeHelper(TreeNode* root, int& depth)
{
	if (root == NULL)
	{
		depth = 0;
		return true;
	}

	int left = 0;
	int right = 0;

	if (IsBlanceTreeHelper(root->left, left) && IsBlanceTreeHelper(root->right, right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			depth = left > right ? left + 1 : right + 1;
			return true;
		}
	}

	return false;
}

bool IsBlanceTree(TreeNode* root)
{
	int depth = 0;
	return IsBlanceTreeHelper(root, depth);
}

//method2: not efficiency
int TreeDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;

	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

bool IsBlanceTree2(TreeNode* root)
{
	if (root == NULL)
		return true;

	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	int diff = left - right;
	if (diff < -1 || diff > 1)
		return false;
	return IsBlanceTree2(root->left) && IsBlanceTree(root->right);
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(5);
	
	cout << IsBlanceTree2(root) << endl;
	int aa;
	cin >> aa;
}