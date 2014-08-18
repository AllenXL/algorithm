#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> res;

//判断当前搜索的子串是否符合IP要求
bool is_valid(string& s, int begin, int end)
{
	string substr(s, begin, end - begin + 1);

	if (substr.size() == 1)
		return substr >= "0" && substr <= "9";
	else if (substr.size() == 2)
		return substr >= "10" && substr <= "99";
	else if (substr.size() == 3)
		return substr >= "100" && substr <= "255";
	else
		return false;
}

void dfs(string&s, int beg, int dep, int max_dep, string& addr)
{
	if (dep == max_dep)
	{
		if (beg == s.size())
		{
			res.push_back(addr);
		}
		return;
	}

	for (int i = beg; i < s.size(); i++)
	{
		if (is_valid(s, beg, i))
		{
			int len = i - beg + 1;
			if (!addr.empty())
			{
				addr += string(".");
				len++;
			}
			addr += s.substr(beg, i - beg + 1);
			dfs(s, i + 1, dep+1, max_dep, addr);
			addr.erase(addr.end() - len, addr.end());
		}
	}
}

vector<string> restoreIpAddresses(string s)
{
	string addr;
	dfs(s, 0, 0, 4, addr); 
	return res;
}


int main(void)
{
	vector<string> ips= restoreIpAddresses("25525511135");

	for (int i = 0; i < ips.size(); i++)
	{
		cout << ips[i] << endl;
	}
	int aa;
	cin >> aa;
	return 0;
}