#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;  

//排列问题，三种方法， DFS， DP， next_permulation
//方法一、DFS
void swapChar(char* p1, char* p2)
{
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void PermulationDFS(char* str, int idx)
{
	if (idx == strlen(str))
	{
		cout << str << endl;
		return;
	}

	for (int i = idx; i < strlen(str); ++i)
	{
		if (i > idx && str[i] == str[i - 1])
			continue;
		swapChar(str + idx, str + i);  //不用另外开辟内存
		PermulationDFS(str, idx + 1);
		swapChar(str + idx, str + i);
	}
}


void Permulation(char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	sort(str, str + strlen(str));
	PermulationDFS(str, 0);
}

//DP，若子串f(i - 1)的排列已知，求f(i)的排列，只需将str[i]往f(i - 1)的所有串的空隙中塞，当然有了递推公式，用递归也是可以实现的
//下面用递归实现

vector<string> PermulationHelper(char* str, int len) 
{
	int total = strlen(str);
    vector<string> res;
	if (len <= 0 || len > total || str == NULL)
	{
		res.push_back("");
		return res;
	}

	vector<string> subRes = PermulationHelper(str, len - 1);

	char cur = str[len - 1];
	
	for (int i = 0; i < subRes.size(); ++i)
	{
		//往字符串中各位置插入当前字符
		res.push_back(string(subRes[i] + cur));
		for (int j = 0; j < subRes[i].size(); j++)
		{
			string tmp = subRes[i];
			res.push_back(tmp.insert(j, string("") + cur));
		}
	}
	return res;
}

void PermulationRecur(char* str)
{
	if (str == NULL)
		return;

	vector<string> res = PermulationHelper(str, strlen(str));
	for (int i = 0; i < res.size(); ++i)
	{
		if (res[i].size() != 0)
			cout << res[i] << endl;
	}
}

//组合问题，实质就是求一个集合的所有子集，有三种方法，DFS, DP, 基于选取与不选取的位操作方法
//方法一
void CombinationDFS(char* str, int idx, string& res)
{
	if (res.size() > 0)
		cout << res << endl;

	if (idx == strlen(str))
		return;

	for (int i = idx; i < strlen(str); ++i)
	{
		if (i > idx && str[i] == str[i - 1]) //防止重复
			continue;
		res.push_back(str[i]);
		CombinationDFS(str, i + 1, res);     //直接从i+1开始，避免重复
		res.pop_back();
	}
}

void Combination(char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	sort(str, str + strlen(str));
	string res;
	CombinationDFS(str, 0, res);
}


//方法二
//子串f(i-1)的所有组合已知，则f(i)的所有组合实际上就是f(i-1)的所有组合，再加上f(i-1) + str[i]（把新增的字符加到之前的组合上）
//用递归实现也可以
void CombinationDP(const char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	vector<string> res;

	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		vector<string> tmp;

		if (i == 0 || str[i] != str[i - 1])
			tmp.push_back(string("") + str[i]);

		for (int j = 0; j < res.size(); ++j)
		{
			tmp.push_back(res[j] + str[i]);
		}

		for (int k = 0; k < tmp.size(); ++k)
			res.push_back(tmp[k]);
	}

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return;
}

//基于位操作的方法，不用递归，不用开辟数组。对于某个元素，有选取和不选取两种状态，因此子集和总数是2^n。
//也就是说，n个元素的集合，对应2^n种子集，每种子集实质上是所有元素的状态集合（二值）。
//这不就是n位二进制数所对应的所有数吗？Got it! 假设元素小于32，用一个unsign int 就可以了。
//如果集合有重复，会包含重复结果，可以用set去重

void CombinationBit(char* str)
{
	if (str == NULL || strlen(str) == 0)
	{
		return;
	}
	int len = strlen(str);

	unsigned int i = 1; //对应具体的组合情况
	unsigned int end_flag = 1 << len;
	for (; i < end_flag; i++)
	{
		int mask = 1;
		int n = len;
		while (n--)
		{
			if (i & mask)
			{
				cout << str[n] << " "; 
			}
			mask <<= 1;
		}
		cout << endl;
	}
}


int main()
{
	char str[] = {"abc"};
	
	cout << "original:" << endl;
	cout << str << endl;

	cout << "permulation:" << endl;
	Permulation(str);

	cout << "PermulationRecur:" << endl;
	PermulationRecur(str);

	cout << "combination:" << endl;
	Combination(str);

	cout << "combination DP:" << endl;
	CombinationDP(str);

	cout << "combination Bit: " << endl;
	CombinationBit(str);

	int aa;
	cin >> aa;
}