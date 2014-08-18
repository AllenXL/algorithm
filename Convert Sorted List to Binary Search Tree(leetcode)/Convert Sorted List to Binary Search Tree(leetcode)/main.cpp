#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//ListNode to BST, 采用中递归
TreeNode* buildTree(ListNode*& node, int s, int e)
{
	if (s > e)
		return NULL;
	int mid = s + (e - s)/2;

	TreeNode* left = buildTree(node, s, mid - 1);
	TreeNode* root = new TreeNode(node -> val);
	root -> left = left;
	node = node -> next;
	root -> right = buildTree(node, mid + 1, e);

	return root;
}

TreeNode *sortedListToBST(ListNode *head) 
{
	if (head == NULL)
		return NULL;

	int len = 0;
	ListNode* cur = head;
	while (cur)
	{
		len++;
		cur = cur -> next;
	}

	return buildTree(head, 0, len - 1);
}


//问题II， vector to BST
TreeNode* buildTree2(vector<int>& num, int s, int e)
{
	if (s > e)
		return NULL;

	int mid = s + (e - s) / 2;
	TreeNode* left = buildTree2(num, s, mid - 1);
	TreeNode* root = new TreeNode(num[mid]);
	root -> left = left;
	root -> right = buildTree2(num, mid + 1, e);
	return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) 
{
	if (num.size() == 0)
		return NULL;
	return buildTree2(num, 0, num.size() - 1);
}


int main(void)
{
	int aa;
	cin >> aa;
}