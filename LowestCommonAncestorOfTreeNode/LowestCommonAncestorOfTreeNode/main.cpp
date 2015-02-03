#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool IsInTree(TreeNode* root, TreeNode* target)
{
	if (root == NULL || target == NULL)
		return false;

	if (root == target)
		return true;
	return IsInTree(root->left, target) || IsInTree(root->right, target);
}

TreeNode* FindCommAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL || p == NULL || q == NULL)
		return NULL;

	if (root == p || root == q)
		return root;

	bool isInLeft_p = IsInTree(root->left, p);
	bool isInLeft_q = IsInTree(root->left, q);

	if (isInLeft_p != isInLeft_q)
		return root;

	TreeNode* childSide = isInLeft_p ? root->left : root->right;
	return FindCommAncestor(childSide, p, q);
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	TreeNode* res = FindCommAncestor(root, root->left->left, root->left->right);
	cout << res->val << endl;
	int aa;
	cin >> aa;
}