#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//�ж϶�����p2 �ǲ��Ƕ�����p1������
//˼·����p1���ҵ���p2���ڵ�ƥ��Ľڵ㣬���ж��Ƿ�ƥ��
bool isMatch(TreeNode* root1, TreeNode* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;

	if (root1->val != root2->val)
		return false;

	return isMatch(root1->left, root2->left) && isMatch(root1->right, root2->right);
}

bool HasSubTree(TreeNode* root1, TreeNode* root2)
{
	if (root2 == NULL)
	{
		return true;
	}

	if (root1 == NULL)
	{
		return false;
	}

	bool r = false;
	if (root1->val == root2->val)
	{
		r = isMatch(root1, root2);
	}
	
	if (!r)
	{
		r = HasSubTree(root1->left, root2);
	}

	if (!r)
	{
		r = HasSubTree(root1->right, root2);
	}
	return r;
}

int main()
{
	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(1);
	root1->right = new TreeNode(3);
	root1->left->left = new TreeNode(1);
	root1->left->right = new TreeNode(2);

	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(3);

	cout << HasSubTree(root1, root2);

	int aa;
	cin >> aa;
}