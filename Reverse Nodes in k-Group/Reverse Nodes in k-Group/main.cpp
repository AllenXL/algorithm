#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
	if (head == NULL || k == 1)
		return head;
	ListNode* cur = head;
	int len = 0;
	while (cur)
	{
		++len;
		cur = cur->next;
	}
	if (len < k)
		return head;

	int group = len / k;

	ListNode dummy(-1);
	ListNode* end = &dummy;
	ListNode* p1 = head;

	for (int i = 0; i < group; ++i)
	{
		ListNode* begin = p1;
		ListNode* tmp_end = NULL;
		int num = k;
		while (num--)
		{
			ListNode* tmp = p1->next;
			p1->next = tmp_end;
			tmp_end = p1;
			p1 = tmp;
		}
		end->next = tmp_end;
		end = begin;
	}
	end->next = p1;
	return dummy.next;
}


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next =new ListNode(5);

	ListNode* res = reverseKGroup(head, 2);

	while (res)
	{
		cout << res->val << " ";
		res = res->next;
	}
	int aa;
	cin >> aa;
}