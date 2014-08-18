#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) 
{
	if (head == NULL)
		return NULL;

	ListNode* p = NULL;
	ListNode* q = head;

	int i = 0;
	while (i < m - 1)
	{
		p = q;
		q = q->next;
		i++;
	}

	ListNode* p1 = NULL;
	ListNode* p2 = q;
	while (m <= n)
	{
		ListNode* temp;
		temp = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = temp;
		m++;
	}
	q->next = p2;
	if (p)
	{
		p->next = p1;
	}
	else
	{
		head = p1;
	}
	return head;
}

void show(ListNode* head)
{
	ListNode* cur = head;
	while(cur)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
}

int main(void)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);

	show(head);

	head = reverseBetween(head, 2, 2);
	show(head);

	int aa;
	cin >> aa;
	return 0;
}