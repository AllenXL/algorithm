#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ÇóÊ÷µÄ¾µÏñ
void MirrorTree(TreeNode* root)
{
	if (root == NULL)
		return;

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	MirrorTree(root->left);
	MirrorTree(root->right);
}

void preOrderTraversal(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root->val << endl;
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

int main()
{
	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);
	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(5);

	cout << "original tree:" << endl;
	preOrderTraversal(root1);

	MirrorTree(root1);
	cout << "Mirror tree:" << endl;
	preOrderTraversal(root1);

	int aa;
	cin >> aa;
}