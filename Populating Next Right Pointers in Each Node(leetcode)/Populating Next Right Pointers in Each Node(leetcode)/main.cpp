#include <iostream>

using namespace std;

struct TreeLinkNode 
{
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


void connect(TreeLinkNode *root) 
{
	if (root == NULL)
		return;
        
	TreeLinkNode* cur_parent = root;
    TreeLinkNode* cur_child = NULL;
    TreeLinkNode* first_child = NULL;
        
    while (cur_parent)
    {
        if (cur_parent -> left)
		{
			if (cur_child)
			{
				cur_child -> next = cur_parent -> left;
				cur_child = cur_parent -> left;
			}
			else
			{
				cur_child = cur_parent -> left;
				first_child = cur_parent -> left;
			}
		}

		if (cur_parent -> right)
		{
			if (cur_child)
			{
				cur_child -> next = cur_parent -> right;
				cur_child = cur_parent -> right;
			}
			else
			{
				cur_child = cur_parent -> right;
				first_child = cur_parent -> right;
			}
		}

		cur_parent = cur_parent -> next;

    }

	connect(first_child);
        
    return;
}

int main(void)
{
}