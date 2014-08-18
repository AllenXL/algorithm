#include <iostream>


using namespace std;

 struct TreeNode 
 {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 int g_max = 0;
 
 //方法一，超时
 /*int max_sum(TreeNode* head)
 {
	 if (head == NULL)
		 return 0;
	 
	 int l = max_sum(head->left);
	 int r = max_sum(head->right);

	 l += head->val;
	 r += head->val;

	 return l > r ? l : r;
 }

 int maxPathSum(TreeNode *root)
 {
	 if (root == NULL)
		 return 0;

	 int max_l = maxPathSum(root->left);
	 int max_r = maxPathSum(root->right);

	 if (max_l > g_max)
		 g_max = max_l;
	 if (max_r > g_max)
		 g_max = max_r;

	 int max_root_l = max_sum(root->left);
	 int max_root_r = max_sum(root->right);
	 int a = max_root_l + root->val;
	 int b = max_root_r + root->val;
	 int c = max_root_l + b;
	 
	 int max_root = a > b ? a : b;
	 max_root = c > max_root ? c : max_root;
	 
	 int res = g_max > max_root ? g_max : max_root;

	 return res;
 }*/

 //方法二， 一条路径，必定在一棵子树上，其中某个几点必定为该子树的根节点
 //本问题无法直接推导为递归问题，所以先弱化问题
int max_sum(TreeNode* head)  //返回该子树中，以head为起始节点的所有路径中的最大值，遍历过程中，顺便求出最大值保存到全局即可
{
	if (head == NULL)
		return 0;
	 
	int l = max_sum(head->left);
	int r = max_sum(head->right);
	
	l += head->val;
	r += head->val;

	int all = l;
	all = all > r ? all : r;
	all = all > head->val ? all : (head->val);

	g_max = g_max > all ? g_max : all;
	g_max = g_max > ( l + r - head->val) ? g_max : ( l + r - head->val);

	return all;
}

int maxPathSum(TreeNode *root)
{
	max_sum(root);
	return g_max;
}
 

void main()
{
	TreeNode root(10);
	root.left = new TreeNode(2);
	root.right = new TreeNode(-3);
	cout << maxPathSum(&root) << endl;
	int aa;
	cin >> aa;
}