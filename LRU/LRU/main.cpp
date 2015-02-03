#include <iostream>
#include <unordered_map>

using namespace std;

/*struct CacheNode
{
    int key;
    int val;
    CacheNode* prev;
    CacheNode* next;
    CacheNode(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache
{
public:

LRUCache(int size)
{
    capacity = size;
    head = new CacheNode(-1, -1);
    tail = new CacheNode(-1, -1);
    head->next = tail;
    tail->prev = head;
    cache_map.clear();
}

~LRUCache()
{
    CacheNode* cur = head;
    CacheNode* next;
    while (cur)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

int get(int key)
{
    unordered_map<int, CacheNode*>::iterator iter = cache_map.find(key);
    if (iter == cache_map.end())
    {
        return -1;
    }
    else
    {
        CacheNode* cur = iter->second;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        moveToHead(cur);
        return cur->val;
    }
}

void set(int key, int val)
{
    if (capacity < 1)
        return;
    unordered_map<int, CacheNode*>::iterator iter = cache_map.find(key);
    if (iter != cache_map.end())
    {
        CacheNode* cur = iter->second;
        cur->val = val;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        moveToHead(cur);
    }
    else
    {
        CacheNode* cur = new CacheNode(key, val);
        moveToHead(cur);
        cache_map[key] = cur;
        if (cache_map.size() > capacity)
        {
            cur = tail->prev;
            tail->prev = cur->prev;
            cur->prev->next = tail;
            cache_map.erase(cur->key);
            delete cur;
        }
    }
}

void moveToHead(CacheNode* cur)
{
    cur->next = head->next;
    head->next->prev = cur;
    cur->prev = head;
    head->next = cur;
}

void show()
{
	CacheNode* cur = head;
	while (cur)
	{
		cout << cur->key << ":" << cur->val << endl;
		cur = cur->next;
	}
}

private:

int capacity;
CacheNode* head;
CacheNode* tail;
unordered_map<int, CacheNode*> cache_map;
    
};*/

struct CacheNode
{
	int key;
	int val;
	CacheNode* prev;
	CacheNode* next;
	CacheNode(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
};

class LRUCache
{
public:
	LRUCache(int c) : capacity(c)
	{
		head = new CacheNode(-1, -1);
		tail = new CacheNode(-1, -1);
		head->next = tail;
		tail->prev = head;
		cache_map.clear();
	};
	~LRUCache()
	{
		CacheNode* cur = head;
		CacheNode* next;
		while (cur)
		{
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
	int get(int key)
	{
		unordered_map<int ,CacheNode*>::iterator iter = cache_map.find(key);
		if (iter == cache_map.end())
		{
			return -1;
		}
		else
		{
			CacheNode* cur = iter->second;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			moveToHead(cur);
			return cur->val;
		}
	}
	void set(int key, int val)
	{
		unordered_map<int, CacheNode*>::iterator iter = cache_map.find(key);
		if (iter == cache_map.end())
		{
			CacheNode* cur = new CacheNode(key, val);
			moveToHead(cur);
			cache_map[key] = cur;
			if (cache_map.size() > capacity)
			{
				cur = tail->prev;
				tail->prev = cur->prev;
				cur->prev->next = tail;
				cache_map.erase(cur->key);
				delete cur;
			}
		}
		else
		{
			CacheNode* cur = iter->second;
			cur->val = val;
			moveToHead(cur);
		}
	}
	void moveToHead(CacheNode* cur)
	{
		cur->next = head->next;
		head->next->prev = cur;
		cur->prev = head;
		head->next = cur;
	}
	void show()
	{
		CacheNode* cur = head;
		while (cur)
		{
			cout << cur->key << ":" << cur->val << endl;
			cur = cur->next;
		}
	}
private:
	const int capacity;
	CacheNode* head;
	CacheNode* tail;
	unordered_map<int, CacheNode*> cache_map;
};

int main()
{
	LRUCache cache(2);
	
	cache.set(2, 1);
	cache.show();
	cache.set(3, 2);
	cache.show();
	cache.get(3);
	cache.show();
	cache.get(2);
	cache.show();
	cache.set(4, 3);
	cache.show();
	cache.get(2);
	cache.show();
	cache.get(3);
	cache.show();
	cache.get(4);
	cache.show();
	//cout << cache.get(2) << endl;
	int aa;
	cin >> aa;
}