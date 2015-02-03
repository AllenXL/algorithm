#include <iostream>

using namespace std;


//����������У��ڵ��������
//�Ѹ��Ӽ�����߿�����˫��ģ���ô�����������ڵ�ľ��붨��Ϊ���������ڵ��·���ĳ���
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
};

void MaxDistInTree(TreeNode* root, int& maxDist, int& depth) //ͬʱ���ظ������Ľڵ�������͸��������
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

	int rootDist = leftDepth + rightDepth + 2; //����root�ڵ�
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