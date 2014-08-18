#include <iostream>
#include <vector>

using namespace std;


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//以后链表问题可以加个虚节点，否则很容易出错
ListNode *partition(ListNode *head, int x)
{
	if (head == NULL)
		return NULL;

	ListNode* sHead = NULL;
	ListNode* hHead = NULL;

	ListNode* sCur = NULL;
	ListNode* hCur = NULL;
	ListNode* cur = head;
	while (cur)
	{
		if (cur->val < x)
		{
			if (sCur == NULL)
			{
				sHead = cur;
				sCur = cur;
			}
			else
			{
				sCur->next = cur;
				sCur = sCur->next;
			}
		}
		else
		{
			if (hCur == NULL)
			{
				hHead = cur;
				hCur = cur;
			}
			else
			{
				hCur->next = cur;
				hCur = hCur->next;
			}
		}
		cur = cur->next;
	}
	if (sCur)
	{
		sCur->next = hHead;
	}
	else
	{
		sHead = hHead;
	}
	if (hCur)
	{
		hCur->next = NULL;
	}
	return sHead;
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
}

//leetcode 另一个题目，dp
int climbStairs(int n) {
	vector<int> f(n, 0);
	f[0] = 1;
	f[1] = 2;

	for (int i = 2; i < f.size(); i++)
		f[i] = f[i - 1] + f[i - 2];

	return f[n-1];
        
}

int main(void)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	/*head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);*/

	show(head);
	ListNode* res = partition(head, 0);
	show(res);
	climbStairs(3);
	int aa;
	cin >> aa;
	return 0;
}