// sortList-selectSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* createList(int* a, int len)
{
	ListNode * head = NULL;
	ListNode * cur = NULL;
	for (int i=0; i<len; i++)
	{
		ListNode* temp = new ListNode(a[i]);
		if (i == 0)
		{
			head = temp;
			cur = temp;
			continue;
		}
		cur -> next = temp;
		cur = temp;
	}
	return head;
}

void printList(ListNode* head)
{
	ListNode* cur = head;
	while (cur)
	{
		cout << (cur -> val) << " ";
		cur = cur -> next;
	}
	cout << endl;
}

ListNode *insertionSortList(ListNode *head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	ListNode* pre_node = head;
	ListNode* cur_node = head -> next;
	while(cur_node)
	{
		if (cur_node -> val < head -> val)
		{
			pre_node -> next = cur_node -> next;
			cur_node -> next = head;
			head = cur_node;
			cur_node = pre_node -> next;
		}
		else
		{
			ListNode* i = head;
			while(i -> next -> val <= cur_node -> val && i -> next != cur_node)
			{
				i = i -> next;
			}
			if (i -> next != cur_node)
			{
				pre_node -> next = cur_node -> next;
				cur_node -> next = i -> next;
				i -> next = cur_node;
				cur_node = pre_node -> next;
			}
			else
			{
				pre_node = cur_node;
				cur_node = cur_node -> next;
			}
		}
	}

	return head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[1] = {1};
	ListNode* aList = createList(a, 1);
	ListNode* sortedList = insertionSortList(aList);
	printList(sortedList);
	return 0;
}

