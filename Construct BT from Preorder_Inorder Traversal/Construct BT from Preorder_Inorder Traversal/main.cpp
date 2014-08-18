#include <vector>
#include <iostream>

using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* creatTree(vector<int>& preorder, int preBegin, int preEnd, 
					vector<int>& inorder, int inBegin, int inEnd)
{
	if (inBegin > inEnd)
		return NULL;

	int rootVal = preorder[preBegin];

	int idx = -1;
	for (int i = inBegin; i <= inEnd; i++)
	{
		if (inorder[i] == rootVal)
		{
			idx = i;
			break;
		}
	}

	int left_len = idx - inBegin;
	TreeNode* left = creatTree(preorder, preBegin + 1, preBegin + left_len, inorder,inBegin, idx - 1 );
	TreeNode* right = creatTree(preorder, preBegin + left_len + 1, preEnd, inorder, idx + 1, inEnd);
	
	TreeNode* root = new TreeNode(rootVal);
	root -> left = left;
	root -> right = right;

	return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)  
{
	if (inorder.size() == 0)
		return NULL;
	return creatTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

void dfs(TreeNode* root)
{
	if (root == NULL)
		return;
	cout << root -> val << endl;
	dfs(root -> left);
	dfs(root -> right);
}

int main(void)
{
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(5);
	inorder.push_back(1);
	inorder.push_back(6);
	inorder.push_back(3);

	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(5);
	preorder.push_back(3);
	preorder.push_back(6);

	TreeNode* root = buildTree(preorder, inorder);
	dfs(root);
	int aa;
	cin >> aa;
}