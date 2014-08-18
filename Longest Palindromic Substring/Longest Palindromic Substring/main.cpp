#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*string longestPalindrome(string s)
{
	int len = s.size();
	vector<vector<bool> > dp(len, vector<bool>(len, false));

	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
		{
			if (i >= j)
				dp[i][j] = true;
			else
				dp[i][j] = false;
		}

	int max = 0;
	int begin = 0;
	int end = 0;
	for (int j = 1; j < len; ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			if (s[i] == s[j])
			{
				dp[i][j] = dp[i + 1][j - 1];
				if (dp[i][j] && max < j - i + 1)
				{
					max = j - i + 1;
					begin = i;
					end =j;
				}
			}
			else
				dp[i][j] = false;
		}
	}
	return s.substr(begin, max);
}*/

string longestPalindrome(string s)
{
	int len = s.size();
	bool dp[1000][1000] = {false};  //用vector竟然超时

	int max = 1;
	int begin = 0;

	for (int i = 0; i < len; ++i)
	{
		dp[i][i] = true;
	}

	for (int i = 0; i < len - 1; ++i)
	{
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = true;
			max = 2;
			begin = i;
		}
	}

	for (int l = 3; l <= len; ++l) //按斜线填充矩阵
	{
		for (int i = 0; i < len - l + 1; ++i)
		{
			int j = i + l - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				max = l;
				begin = i;
			}
		}
	}
	
	return s.substr(begin, max);
}

int main()
{
	cout << longestPalindrome(string("ababcd")) << endl;
	int aa;
	cin >> aa;
}