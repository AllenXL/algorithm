#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if (!head)
		return head;
	ListNode dummy(-1);
	dummy.next = head;
	
	ListNode* p1_prev = &dummy;
	ListNode* p1 = head;
	ListNode* p2 = head;

	while (n--)
	{
		
		p2 = p2->next;
	}

	while (p2)
	{
		p1_prev = p1;
		p1 = p1->next;
		p2 = p2->next;
	}

	p1_prev->next = p1->next;
	delete p1;
	return dummy.next;
}

void show(ListNode* head)
{
	ListNode* cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	return;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	show(head);
	show(removeNthFromEnd(head, 3));

	int aa;
	cin >> aa;
	return 0;
}