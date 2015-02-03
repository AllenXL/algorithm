#include <iostream>

using namespace std;


//计算二叉树中，节点的最大距离
//把父子间的连线看成是双向的，那么二叉树中两节点的距离定义为：这两个节点的路径的长度
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
};

void MaxDistInTree(TreeNode* root, int& maxDist, int& depth) //同时返回该子树的节点最大距离和该树的深度
{
	if (root == NULL)
	{
		maxDist = 0;
		depth = -1;
		return;
	}

	int leftDist, leftDepth, rightDist, rightDepth;
	MaxDistInTree(root->left, leftDist, leftDepth);
	MaxDistInTree(root->right, rightDist, rightDepth);

	maxDist = leftDist > rightDist ? leftDist : rightDist;

	int rootDist = leftDepth + rightDepth + 2; //经过root节点
	maxDist = rootDist > maxDist ? rootDist : maxDist;
	
	depth = leftDepth > rightDepth ? leftDepth : rightDepth;
	depth += 1;
	return;
}

int main()
{
	TreeNode* root = new TreeNode();
	root->left = new TreeNode();
	root->right = new TreeNode();
	root->left->left = new TreeNode();
	root->right->left = new TreeNode();

	int maxDist, depth;
	MaxDistInTree(root, maxDist, depth);
	cout << maxDist << endl; 

	int aa;
	cin >> aa;
}