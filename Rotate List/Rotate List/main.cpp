#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
	if (head == NULL || head->next == NULL || k == 0)
		return head;

	int len = 0;
	ListNode* p = head;
	ListNode* tail = NULL;
	while (p)
	{
		len++;
		tail = p;
		p = p->next;
	}

	k %= len;

	p = head;
	for (int i = 0; i < (len - k - 1); ++i)
	{
		p = p->next;
	}
	tail->next = head;
	head = p->next;
	p->next = NULL;
	return head;
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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	show(head);
	show(rotateRight(head, 5));
	int aa;
	cin >> aa;
	return aa;
}