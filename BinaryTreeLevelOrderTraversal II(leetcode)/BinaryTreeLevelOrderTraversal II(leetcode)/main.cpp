// Flatten Binary Tree to Linked List (leetcode).cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

//如果是每层的也要逆序的话，就把 left 和right  入队或入栈的顺序调换一下就行了
vector<vector<int> > levelOrderBottom(TreeNode *root) 
{
	vector<vector<int> > res;
	if (root == NULL)
		return res;

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	vector<int> tmp;
	while (!q.empty())
	{
		TreeNode* cur = q.front();
		q.pop();

		if (cur)
		{
			tmp.push_back(cur -> val);
			if (cur -> left)
				q.push(cur -> left);
			if (cur -> right)
				q.push(cur -> right);
		}
		else
		{
			if (!tmp.empty())
			{
				res.insert(res.begin(), tmp);
				tmp.clear();
				q.push(NULL);
			}
		}
	}

	return res;
}

template <typename T>
void show(vector<vector<T> > data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data[i].size(); ++j)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);

	root -> left -> left = new TreeNode(3);
	root -> left -> right = new TreeNode(4);
	root -> right -> right = new TreeNode(6);

	vector<vector<int> >& res = levelOrderBottom(root);
	show(res);
	
	int aa;
	cin >> aa;
	return 0;
}

