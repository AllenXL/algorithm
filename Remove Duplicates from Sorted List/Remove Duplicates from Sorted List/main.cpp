#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

void show(ListNode* head)
{
	ListNode* cur = head;

	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

ListNode *deleteDuplicates1(ListNode *head) 
{
   if (NULL == head)
	   return NULL;
   ListNode* p1 = head;
   ListNode* p2 = head->next;

   while (p2)
   {
	   if (p2->val == p1->val)
	   {
		   p1->next = p2->next;
		   delete p2;
		   p2 = p1->next;
	   }
	   else
	   {
		   p1 = p2;
		   p2 = p2->next;
	   }
   }
   return head;
}

//Remove Duplicates from Sorted List II 
ListNode *deleteDuplicates(ListNode *head)
{
	if (head == NULL)
		return NULL;

	ListNode* dummy = new ListNode(-1);
	dummy->next = head;

	ListNode* p1 = dummy;  //��¼��ǰ����������һ���ڵ�
	ListNode* p2 = dummy->next; //����p1������Щ�ڵ��ָ��

	while (p2 && p2->next)
	{
		if (p2->val == p2->next->val) //������������ڵ���ȣ����¼ֵ�����α���ɾ��
		{
			int key = p2->val;
			while (p2 != NULL)
			{
				if (p2->val == key)
				{
					p1->next = p2->next;
					delete p2;
					p2 = p1->next;
				}
				else
					break;
			}
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
		}
	}
	ListNode* res = dummy->next;
	delete dummy;
	return res;
}

int main(void)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);

	ListNode* res = deleteDuplicates(head);
	show(res);

	int aa;
	cin >> aa;
}