// Flatten Binary Tree to Linked List (leetcode).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void dfs_tree(TreeNode* root)
{
	if (root == NULL)
		return;

	cout << root -> val << endl;

	dfs_tree(root -> left);
	dfs_tree(root -> right);
	return;
}

void flatten(TreeNode *root)
{
	if (root == NULL)
		return;
	flatten(root -> left);
	flatten(root -> right);

	if (root -> left == NULL)
		return;

	TreeNode* cur = root -> left;
	TreeNode* prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur -> right;
	}
	
	TreeNode* right = root -> right;
	root -> right = root -> left;
	root -> left = NULL;
	prev -> right = right;
}

int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);

	//root -> left -> left = new TreeNode(3);
	//root -> left -> right = new TreeNode(4);
	//root -> right -> right = new TreeNode(6);


	flatten(root);

	dfs_tree(root);



	return 0;
}

