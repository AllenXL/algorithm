#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <unordered_set>

using namespace std;

//递归方法，超时
/*bool is_arrived(string a, string b)
{
	int diff = 0;
	
	if (a.length() != b.length())
		return false;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] != b[i])
			diff++;
		if (diff >= 2)
			return false;
	}
	return true;
}
vector<int> len;
void ladderLength1(string start, string end, unordered_set<string>& dict, unordered_set<string>& path) 
{
	//path.insert(start);
	if (is_arrived(start, end))
	{
		//path.insert(end);
		cout << path.size() + 1 << endl;
		len.push_back(path.size() + 1);
		return;
	}
	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		if ((path.find(*iter) == path.end()) && is_arrived(*iter, start))
		{
			cout << *iter << endl;
			path.insert(*iter);
			ladderLength1(*iter, end, dict, path);
			path.erase(*iter);
		}
	}
}


int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	unordered_set<string> path;
	path.insert(start);
	ladderLength1(start, end, dict, path);
    if (len.size() == 0)
		return 0;
	int min =len[0];
	for (int i = 1; i < len.size(); ++i)
	{
		if (len[i] < min)
			min = len[i];
	}
	return min;
}*/



//构造图，节点相连代表两个词可以一步转换，然后BFS即可

/*bool is_diff1(string a, string b)
{
	int diff = 0;
	
	if (a.length() != b.length())
		return false;
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] != b[i])
			diff++;
		if (diff >= 2)
			return false;
	}
	return diff == 1;
}

int ladderLength(string start, string end, unordered_set<string> &dict)
{
	if (start.length() != end.length() || start.length() == 0 || end.length() == 0 || start == end)
	{
		return 0;
	}

	dict.insert(start);
	dict.insert(end);

	vector<string> dicts;

	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		dicts.push_back(*iter);
	}

	int len = dicts.size();
	int node_s, node_e;
	//vector<vector<bool> > word_graph(len, vector<bool>(len, false));
	vector<vector<int> > word_graph(len);
	for (int i = 0; i < len; i++)
	{
		if (dicts[i] == start)
			node_s = i;
		if (dicts[i] == end)
			node_e = i;
		for (int j = 0; j < len; j++)
		{
			if (is_diff1(dicts[i], dicts[j]))
			{
				word_graph[i].push_back(j);
				//word_graph[i][j] = true;
				//cout << dicts[i] << " " << dicts[j] << endl;
			}
		}
	}

	//图的BFS遍历，要注意记录某个几点是否已访问过
	queue<int> q;
	q.push(node_s);
	map<int, int> word_layer;
	word_layer[node_s] = 1;
	//cout << "begin" << endl;
	while(!q.empty())
	{
		int idx = q.front();
		//cout << dicts[idx] << endl;
		q.pop();
		if (idx == node_e)
			return word_layer[idx];
		for (int i = 0; i < word_graph[idx].size(); i++)
		{
			if (word_layer.find(word_graph[idx][i]) == word_layer.end())
			{
				q.push(word_graph[idx][i]);
				word_layer[word_graph[idx][i]] = word_layer[idx] + 1;
				//cout << "add " << dicts[i] << endl;
			}
		}
	}

	return 0;

}*/

//is_diff1 的方法对于大词典太耗时，直接用每一位置替换a~z的方法
/*int ladderLength(string start, string end, unordered_set<string> &dict)
{
	if (start.length() != end.length() || start.length() == 0 || end.length() == 0 || start == end)
	{
		return 0;
	}

	dict.insert(start);
	dict.insert(end);

	vector<string> dicts;

	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		dicts.push_back(*iter);
	}

	int len = dicts.size();
	
	map<string, vector<string> > word_graph;
	for (int i = 0; i < len; i++)
	{
		string str = dicts[i];
		vector<string> vec;
		//cout << "for: " << str << endl;
		for (int x = 0; x < str.length(); x++)
		{
			for (char j = 'a'; j <= 'z'; j++)
			{	
				string s(str);
				if (j == s[x]) continue;
				s[x] = j;
				if (dict.find(s) != dict.end())
				{
					vec.push_back(s);
					//cout << "add: " << s << endl;
				}
			}
		}
		word_graph[str] = vec;
	}

	//图的BFS遍历，要注意记录某个几点是否已访问过
	queue<string> q;
	q.push(start);
	map<string, int> word_layer;
	word_layer[start] = 1;
	//cout << "begin" << endl;
	while(!q.empty())
	{
		string idx = q.front();
		//cout << dicts[idx] << endl;
		q.pop();
		if (idx == end)
			return word_layer[idx];

		vector<string>& list = word_graph[idx];
		for (int i = 0; i < list.size(); i++)
		{
			if (word_layer.find(list[i]) == word_layer.end())
			{
				q.push(list[i]);
				word_layer[list[i]] = word_layer[idx] + 1;
				//cout << "add " << dicts[i] << endl;
			}
		}
	}

	return 0;

}*/

// Word LadderII  

void generate_path(map<string, vector<string> >& parents, vector<vector<string> >& res,
					vector<string>& path, string word)
{
	if (parents.find(word) == parents.end())
	{
		path.insert(path.begin(), word);
		res.push_back(path);
		path.erase(path.begin());
		return;
	}

	path.insert(path.begin(), word);

	for (int i = 0; i < parents[word].size(); ++i)
	{
		generate_path(parents, res, path, parents[word][i]);
	}
	
	path.erase(path.begin());
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string>> result;
	if (start.length() != end.length() || start.length() == 0 || end.length() == 0 || start == end)
	{
		return result;
	}

	dict.insert(start);
	dict.insert(end);

	vector<string> dicts;

	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		dicts.push_back(*iter);
	}

	int len = dicts.size();
	
	map<string, vector<string> > word_graph;
	for (int i = 0; i < len; i++)
	{
		string str = dicts[i];
		vector<string> vec;
		//cout << "for: " << str << endl;
		for (int x = 0; x < str.length(); x++)
		{
			for (char j = 'a'; j <= 'z'; j++)
			{	
				string s(str);
				if (j == s[x]) continue;
				s[x] = j;
				if (dict.find(s) != dict.end())
				{
					vec.push_back(s);
					//cout << "add: " << s << endl;
				}
			}
		}
		word_graph[str] = vec;
	}

	//图的BFS遍历，要注意记录某个几点是否已访问过
	queue<string> q;
	q.push(start);
	map<string, int> word_layer;
	word_layer[start] = 1;
	
	//cout << "begin" << endl;
	bool flag = false;
	while(!q.empty())
	{
		string idx = q.front();
		//cout << dicts[idx] << endl;
		q.pop();
		if (idx == end)
		{
			flag = true;
			break;
		}

		vector<string>& list = word_graph[idx];
		for (int i = 0; i < list.size(); i++)
		{
			if (word_layer.find(list[i]) == word_layer.end())
			{
				q.push(list[i]);
				word_layer[list[i]] = word_layer[idx] + 1;
				//cout << "add " << list[i] << endl;
			}
		}
	}

	if (!flag)
		return result;

	//begin to get paths，构造有向图来求路径
	map<string, vector<string> > parents;
	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		int cur_layer = word_layer[*iter];

		vector<string>& connected_nodes = word_graph[*iter];
		for (int i = 0; i < connected_nodes.size(); ++i)
		{
			if (word_layer[connected_nodes[i]] == cur_layer - 1)
			{
				parents[*iter].push_back(connected_nodes[i]);
				//cout << *iter << "'s parents is " << connected_nodes[i] << endl;
			}
		}
	}

	vector<string> path;
	generate_path(parents, result, path, end);

	return result;

}

void main()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
	{
		cout << *iter << endl;
	}

	//cout << "res=" << ladderLength(string("hot"), string("dog"), dict) << endl;
	vector<vector<string> > res = findLadders(string("hit"), string("cog"), dict);

	for (int i = 0; i < res.size(); ++i)
	{
		for(int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";

		cout << endl;
	}

	int aa;
	cin >> aa;
}