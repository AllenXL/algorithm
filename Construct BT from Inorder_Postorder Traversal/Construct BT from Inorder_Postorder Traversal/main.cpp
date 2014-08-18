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


TreeNode* creatTree(vector<int>& inorder, int inBegin, int inEnd, 
					vector<int>& postorder, int posBegin, int posEnd)
{
	if (inBegin > inEnd)
		return NULL;

	int rootVal = postorder[posEnd];

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
	TreeNode* left = creatTree(inorder, inBegin, idx - 1, postorder, posBegin, posBegin + left_len - 1);
	TreeNode* right = creatTree(inorder, idx + 1, inEnd, postorder, posBegin + left_len, posEnd - 1);

	TreeNode* root = new TreeNode(rootVal);
	root -> left = left;
	root -> right = right;

	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	if (inorder.size() == 0)
		return NULL;
	return creatTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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

	vector<int> postorder;
	postorder.push_back(4);
	postorder.push_back(5);
	postorder.push_back(2);
	postorder.push_back(6);
	postorder.push_back(3);
	postorder.push_back(1);

	TreeNode* root = buildTree(inorder, postorder);
	dfs(root);
	int aa;
	cin >> aa;
}