#include <iostream>
#include <stack>
#include <string>

using namespace std;

//利用堆栈，遍历一遍字符串即可
string simplifyPath(string path)
{
	stack<string> dir;
	string tmp;

	path += '/';
	for (int i = 0; i < path.size(); ++i)
	{
		if (path[i] == '/')
		{
			if (tmp == "" || tmp == ".")
			{
				tmp = "";
				continue;
			}
			else
			{
				if (tmp == "..")
				{
					if (!dir.empty())
						dir.pop();
				}
				else
				{
					dir.push(tmp);
				}
				tmp = "";
			}
		}
		else
		{
			tmp += path[i];
		}

	}

	if (dir.empty())
		return string("/");
	else
	{
		string res;
		while (!dir.empty())
		{
			res = "/" + dir.top() + res;
			dir.pop();
		}
		return res;
	}
}

int main(void)
{
	
	cout << simplifyPath(string("/a/./b/../../c/"));

	int aa;
	cin >> aa;
	return 0;
}