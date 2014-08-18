#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode dummy(-1);
	dummy.next = head;

	ListNode* end = &dummy;
	ListNode* p1 = head;
	
	while (p1 && p1->next)
	{
		//cout << p1->val;
		end->next = p1->next;
		ListNode* tmp = p1->next->next;
		p1->next->next = p1;
		p1->next = tmp;
		end = p1;
		p1 = p1->next;
	}
	return dummy.next;
}

void show(ListNode* head)
{
	ListNode* cur = head;
	while (cur)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
}

int main(void)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	show(swapPairs(head));
	int aa;
	cin >> aa;
}