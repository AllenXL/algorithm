#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> depth; //compress path

int Find(int i)
{
	if (parent[i] == i)
		return i;
	else
	{
		int res = Find(parent[i]);
		parent[i] = res;
		return res;
	}
}

void Union(int i , int j)
{
	int iParent = Find(i);
	int jParent = Find(j);
	int iRank = depth[iParent];
	int jRank = depth[jParent];

	if (iParent == jParent)
		return;
	if (iRank < jRank)
	{
		parent[iParent] = jParent;
	}
	else if (iRank > jRank)
	{
		parent[jParent] = iParent;
	}
	else
	{
		parent[iParent] = jParent;
		depth[jParent]++;
	}
}

int main()
{
	unordered_map<string, int> nameMap;
	int n;
	int op;
	string name1, name2;
	int idx = 0;
	cin >> n;
	while (n--)
	{
		cin >> op >> name1 >> name2;
		if (nameMap.find(name1) == nameMap.end())
		{
			nameMap[name1] = idx++;
			parent.push_back(parent.size());
			depth.push_back(0);
		}
		if (nameMap.find(name2) == nameMap.end())
		{
			nameMap[name2] = idx++;
			parent.push_back(parent.size());
			depth.push_back(0);
		}

		if (op == 1)  //find
		{
			int i = Find(nameMap[name1]);
			int j = Find(nameMap[name2]);
			if (i == j)
				cout << "yes" << endl;
			else
				cout << "no" <<  endl;
		}
		else
		{
			Union(nameMap[name1], nameMap[name2]);
		}

	}
}