#include <iostream>
#include <string>

using namespace std;

const int NUM = 128;

struct TrieNode
{
	int val;
	TrieNode* next[NUM];

	TrieNode (int x = -1) : val(x)
	{
		for (int i = 0; i < NUM; ++i)
			next[i] = NULL;
	}
};

void Insert(TrieNode* root, const string& word, int priority)
{
	int len = word.size();

	TrieNode* cur = root;
	for (int i = 0; i < len; ++i)
	{
		if (cur->next[word[i]] == NULL)
		{
			cur->next[word[i]] = new TrieNode();
		}
		cur = cur->next[word[i]];
	}
	cur->val = priority;
}

int Query(TrieNode* root, const string& word)
{
	if (root == NULL)
		return -1;
	int len = word.size();

	int res = -1;
	TrieNode* cur = root;
	int i = 0;
	for (; i < len; ++i)
	{
		if (cur->next[word[i]] == NULL)
			break;
		else
			cur = cur->next[word[i]];
	}
	if (i == len)
	{
		res = cur->val;
	}
	return res;
}

int main()
{
	int n = 0;
	cin >> n;
	string word;
	int priority = 0;

	TrieNode* root = new TrieNode();
	while (n--)
	{
		cin >> word;
		cin >> priority;
		Insert(root, word, priority);
	}

	cout << "input query" << endl;
	while (true)
	{
		cin >> word;
		cout << Query(root, word) << endl;
	}

}