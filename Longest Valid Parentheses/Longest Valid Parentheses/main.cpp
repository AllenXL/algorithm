#include <string>
#include <stack>
#include <iostream>

using namespace std;

int longestValidParentheses(string s)
{
	int max = 0;
	int left = -1;

	stack<int> tmp;
	
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			tmp.push(i);
		}
		else
		{
			if (tmp.empty())
			{
				left = i;
			}
			else
			{
				tmp.pop();
				if (tmp.empty())
				{
					max = max > (i - left) ? max : (i - left);
				}
				else
				{
					max = max > (i - tmp.top()) ? max : (i - tmp.top());
				}
			}
		}
	}
	return max;
}

int main()
{
	cout << longestValidParentheses(string("(((()))")) << endl;
	int a;
	cin >> a;
}