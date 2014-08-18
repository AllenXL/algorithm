#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void show_matrix(vector<vector<int> >& table)
{
	for (int i = 0; i < table.size(); ++i)
	{
		for (int j = 0; j < table[i].size(); j++)
			cout << table[i][j] << " ";
		cout << endl;
	}
	
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
{
	vector<vector<int> > res;
	if (root == NULL)
		return res;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	bool flag = true;
	vector<int> cur;
	while(!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		
		if (tmp != NULL)
		{
			if (flag)
			{
				cur.push_back(tmp->val);
			}
			else
			{
				cur.insert(cur.begin(), tmp->val);
			}
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		else
		{
			if (!cur.empty())
			{
				flag = !flag;
				res.push_back(cur);
				cur.clear();
				q.push(NULL);
			}
		}
	}

	return res;

}

int main(void)
{
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);

	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	root -> right -> right = new TreeNode(6);

	show_matrix(zigzagLevelOrder(root));

	int aa;
	cin >> aa;
}