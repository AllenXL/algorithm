#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//ตÝน้
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode* res;

	if (l1->val < l2->val)
	{
		res = l1;
		l1->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		res = l2;
		l2->next = mergeTwoLists(l2->next, l1);
	}
	return res;
}

void show(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


int main()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);

	ListNode* l2 = new ListNode(2);
	l2->next = new ListNode(4);
	l2->next->next = new ListNode(6);

	cout << "l1:" << endl;
	show(l1);
	cout << "l2:" << endl;
	show(l2);
	cout << "res:" << endl;
	show(mergeTwoLists(l1, l2));

	int aa;
	cin >> aa;
}