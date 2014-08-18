#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void inorderTraversal(TreeNode * root)
{
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	cout << root->val << endl;
	inorderTraversal(root->right);
}

//����ݹ�ֻ�������Ӻ��ӣ�ʵ����Ҫ�ұߵ������ӽڵ㶼���ڣ������Ǵ�����㷨
/*bool isValidBST(TreeNode *root)
{
	if (root == NULL)
		return true;

	if (root->left && root->left->val > root->val)
		return false;
	if (root->right && root->right->val < root->val)
		return false;

	if (isValidBST(root->left) && isValidBST(root->right))
		return true;
}*/

TreeNode* pre;
bool flag;
void inorderValid(TreeNode* root)
{
	if (root == NULL)
		return;
	inorderValid(root->left);
	if (pre && (pre->val >= root->val))
	{
		flag = false;
		return;
	}
	pre = root;
	inorderValid(root->right);
}

bool isValidBST(TreeNode *root)
{
	if (root == NULL)
		return true;

	pre = NULL;
	flag = true;

	inorderValid(root);
	return flag;
}

int main(void)
{
	TreeNode* root = new TreeNode(4);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(5);

	
	root -> left -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(3);
	root -> right -> right = new TreeNode(6);

	cout << "input: " << endl;
	inorderTraversal(root);
	cout << "isValid?" << endl;
	cout << isValidBST(root) << endl;

	int aa;
	cin >> aa;
	return 0;
}