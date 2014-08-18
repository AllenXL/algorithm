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

TreeNode *s1, * s2, *pre;
void findNode(TreeNode* root)
{
	if (root == NULL)
		return;
	findNode(root->left);
	if (pre && (pre->val > root->val))
	{
		if (s1 == NULL)
		{
			s1 = pre;
			s2 = root;
		}
		else
			s2 = root;
	}
	pre = root;
	findNode(root->right);
}

void recoverTree(TreeNode *root) 
{
	if (root == NULL)
		return;
	s1 = NULL;
	s2 = NULL;
	pre = NULL;
	findNode(root);

	//swap
	int temp = s1->val;
	s1->val = s2->val;
	s2->val = temp;
	return;
}

void inorderTraversal(TreeNode * root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	cout << root->val << endl;
	inorderTraversal(root->right);
}


int main(void)
{
	TreeNode* root = new TreeNode(4);
	root -> left = new TreeNode(6);
	root -> right = new TreeNode(5);

	
	root -> left -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(3);
	root -> right -> right = new TreeNode(2);

	cout << "input: " << endl;
	inorderTraversal(root);
	recoverTree(root);

	cout << "output: " << endl;
	inorderTraversal(root);

	int aa;
	cin >> aa;
	return 0;
}