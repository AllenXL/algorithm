#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode * root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	cout << root->val << endl;
	inorderTraversal(root->right);
}

vector<TreeNode*> generate(int beg, int end)
{
	vector<TreeNode*> res;

	if (beg > end)
	{
		res.push_back(NULL);
		return res;
	}

	for (int i = beg; i <= end; i++)
	{
		vector<TreeNode*> left = generate(beg, i - 1);
		vector<TreeNode*> right = generate(i + 1, end);

		for (int j = 0; j < left.size(); j++)
			for (int k = 0; k < right.size(); k++)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left[j];
				root->right = right[k];
				res.push_back(root);
			}
	}

	return res;
}

vector<TreeNode *> generateTrees(int n) 
{
	return generate(1, n);
}

int main(void)
{
	vector<TreeNode*> res = generateTrees(3);
	cout << "total BST: " << res.size() << endl;

	for (int i = 0; i < res.size(); ++i)
	{
		cout << "index: " << i << endl;
		inorderTraversal(res[i]);
	}
	int aa;
	cin >> aa;
	return 0;
}