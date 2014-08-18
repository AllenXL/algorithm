#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode dummy(-1);
	ListNode* end = &dummy;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			end->next = l1;
			l1 = l1->next;
		}
		else
		{
			end->next = l2;
			l2 = l2->next;
		}
		end = end->next;
	}

	if (l1)
	{
		end->next = l1;
	}
	if (l2)
	{
		end->next = l2;
	}
	return dummy.next;
}

ListNode* helper(vector<ListNode* >& lists, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		return merge(helper(lists, l, m), helper(lists, m + 1, r));
	}
	return lists[l];
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
	if (lists.size() == 0)
		return NULL;
	return helper(lists, 0, lists.size() - 1);
}

void show(ListNode* head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(3);
	head1->next->next = new ListNode(5);

	ListNode* head2 = new ListNode(2);
	head2->next = new ListNode(4);
	head2->next->next = new ListNode(6);

	show(head1);
	show(head2);
	show(merge(head1, head2));

	int aa;
	cin >> aa;
	return 0;
}