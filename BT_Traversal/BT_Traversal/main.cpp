#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ǰ�����-�ݹ�
void PreOrderTraversal_Recursive(TreeNode* root)
{
	if (root == NULL)
		return;

	cout << root->val << endl;
	PreOrderTraversal_Recursive(root->left);
	PreOrderTraversal_Recursive(root->right);
}

//ǰ�����-�ǵݹ�
void PreOrderTraversal(TreeNode* root)
{
	if (root == NULL)
		return;

	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* cur = s.top();
		cout << cur->val << endl;
		s.pop();
		if (cur->right)
			s.push(cur->right);
		if (cur->left)
			s.push(cur->left);
	}
}


//�������-�ݹ�
void InOrderTraversal_Recursive(TreeNode* root)
{
	if (root == NULL)
		return;

	InOrderTraversal_Recursive(root->left);
	cout << root->val << endl;
	InOrderTraversal_Recursive(root->right);
}

//�������-�ǵݹ�
void InOrderTraversal(TreeNode* root)
{
	stack<TreeNode*> s;
    TreeNode *p=root;
    while (p != NULL || !s.empty())  //�д����������p��ջ���д�����������ͽ���ѭ������
    {
        while(p != NULL)  //����д����������p����ջ������ɰ�������ȼ���ջ
        {
            s.push(p);
            p = p->left;
        }
        if(!s.empty())  //ջ����Ԫ��������ȼ���ߣ��������
        {
            p = s.top();
            cout << p->val << " ";
            s.pop();
            p = p->right;
        }
    } 
}

//�������-�ݹ�
void PostOrderTraversal_Recursive(TreeNode* root)
{
	if (root == NULL)
		return;

	PostOrderTraversal_Recursive(root->left);
	PostOrderTraversal_Recursive(root->right);
	cout << root->val << endl;
}

//�������-�ǵݹ�
void PostOrderTraversal(TreeNode* root)
{
	if (root == NULL)
		return;

	stack<TreeNode*> s;
	TreeNode* used = root;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* cur = s.top();
		
		if (used == cur->left || used == cur->right || (cur->left == NULL && cur->right == NULL))
		{
			cout << cur->val << endl;
			s.pop();
			used = cur;
		}
		else
		{
			if (cur->right)
				s.push(cur->right);
			if (cur->left)
				s.push(cur->left);
		}
	}
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	//root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	cout << "recursive:" << endl;
	InOrderTraversal_Recursive(root);
	cout << "use stack:" << endl;
	InOrderTraversal(root);
	int aa;
	cin >> aa;
}


