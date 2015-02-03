#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//n个人，从k开始报数，数到m的出列，求最后那个人的编号
int LastRemaining(int n, int k, int m)
{
	if (n <= 0 || k > n - 1)
		return -1;

	//create circular linked list
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	for (int i = 1; i < n; ++i)
	{
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	cur->next = head;

	//find the first person
	ListNode* prev = NULL;
	while (cur->val != k)
	{
		prev = cur;
		cur = cur->next;
	}

	//begin game
	while (n > 1)
	{
		int i = m - 1;
		while (i--)
		{
			prev = cur;
			cur = cur->next;
		}

		//delete node
		prev->next = cur->next;
		cout << cur->val << endl;
		delete cur;
		cur = prev->next;
		n--;
	}

	return cur->val;
}

int main()
{
	cout << LastRemaining(3, 0, 1) << endl;
	int aa;
	cin >> aa;
}