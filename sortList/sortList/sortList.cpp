// sortList.cpp : 定义控制台应用程序的入口点。
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

void mergeList(ListNode* a, ListNode* b, ListNode*& res)
{
	if (a == NULL)
	{
		res = b;
		return;
	}
	else if (b == NULL)
	{
		res = a;
		return;
	}
	
	ListNode* pa = a;
	ListNode* pb = b;

	if (pa -> val <= pb -> val)
	{
		res = pa;
		pa = pa -> next;
	}
	else
	{
		res = pb;
		pb = pb -> next;
	}

	ListNode* pRes = res;

	while (pa && pb)
	{
		if (pa -> val <= pb -> val)
		{
			pRes -> next = pa;
			pa = pa -> next;
			pRes = pRes -> next;
		}
		else
		{
			pRes -> next = pb;
			pb = pb -> next;
			pRes = pRes -> next;
		}
	}
	
	if (pa)
	{
		while (pa)
		{
			pRes -> next = pa;
			pa = pa -> next;
			pRes = pRes -> next;
		}
	}
	else if (pb)
	{
		while (pb)
		{
			pRes -> next = pb;
			pb = pb -> next;
			pRes = pRes -> next;
		}
	}
}

int getListLen(ListNode* a)
{
	int len = 0;
	while(a)
	{
		len++;
		a = a -> next;
	}
	return len;
}

void halfDivList(ListNode* a, int len, ListNode*& res2)
{
	int step = 0;
	while ((++step) < len/2)
	{
		a = a->next;
	}
	res2 = a -> next;
	a -> next = NULL;
}

void mergeSort(ListNode* a, int len, ListNode*& res)
{
	if (len == 0 || len == 1)
	{
		res = a;
		return;
	}
	
	ListNode* pLeftHead = a;
	ListNode* pRightHead = NULL;
	halfDivList(a, len, pRightHead);

	ListNode* sortedL = NULL;
	ListNode* sortedR = NULL;
	mergeSort(pLeftHead, len/2, sortedL);

	mergeSort(pRightHead, (len - len/2), sortedR);

	mergeList(sortedL, sortedR, res);

}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5] = {6, 1, 8, 7, 4};
	int b[5] = {5, 8, 11, 14, 17};
	ListNode* list1 = createList(a, 5);
	printList(list1);

	ListNode* list2 = createList(b, 5);
	printList(list2);

	ListNode* list3 = NULL;
	
	mergeSort(list1, getListLen(list1), list3);
	printList(list3);

	return 0;
}

