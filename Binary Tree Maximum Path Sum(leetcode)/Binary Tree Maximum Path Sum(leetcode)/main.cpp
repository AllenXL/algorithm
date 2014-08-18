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
 
 //����һ����ʱ
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

 //�������� һ��·�����ض���һ�������ϣ�����ĳ������ض�Ϊ�������ĸ��ڵ�
 //�������޷�ֱ���Ƶ�Ϊ�ݹ����⣬��������������
int max_sum(TreeNode* head)  //���ظ������У���headΪ��ʼ�ڵ������·���е����ֵ�����������У�˳��������ֵ���浽ȫ�ּ���
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