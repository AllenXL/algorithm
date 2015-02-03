#include <iostream>
#include <string>

using namespace std;

struct TrieNode
{
    int val;
    TrieNode* next[26];
    TrieNode(int x) : val(x)
    {
        for (int i = 0; i < 26; ++i)
        {
            next[i] = NULL;
        }
    }
};

void InsertHelper(TrieNode* root, string& str, int idx)
{
    if (root == NULL || idx >= str.size())
    {
        return;
    }

    int i = str[idx] - 'a';
    if (root->next[i])
    {
        ++(root->next[i]->val);
    }
    else
    {
        TrieNode* cur = new TrieNode(1);
        root->next[i] = cur;
    }
    InsertHelper(root->next[i], str, idx + 1);
}

void Insert(TrieNode* root, string& str)
{
    InsertHelper(root, str, 0);
}

int Query(TrieNode* root, string& str)
{
    int len = str.size();
    if (root == NULL || len <= 0)
    {
        return 0;
    }

    TrieNode* cur = root;

    for (int i = 0; i < len; ++i)
    {
        int idx = str[i] - 'a';
        if (cur->next[idx] == NULL)
        {
            return 0;
        }
        else
        {
            cur = cur->next[idx];
        }
    }
    return cur->val;
}

int main()
{
    /*TrieNode* root = new TrieNode(0);
    string str("abc");
    Insert(root, str);
    str = "abcd";
    Insert(root, str);
    str = "abcde";
    cout << Query(root, str) << endl;*/

    int n;
    string str;
    TrieNode* root = new TrieNode(0);

    cin >> n;
    while (n--)
    {
        cin >> str;
        Insert(root, str);
    }

    cin >> n;
    while (n--)
    {
        cin >> str;
        cout << Query(root, str) << endl;
    }

    return 0;
}
