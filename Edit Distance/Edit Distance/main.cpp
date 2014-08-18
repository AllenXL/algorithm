#include <iostream>
#include <string>
#include <vector>

using namespace std;

//DP
//这里D[i,j]就是取s1前i个character和s2前j个character所得minimal edit distance

//三个操作动态进行更新：

//D(i,j)=min { D(i-1, j) +1, D(i, j-1) +1 , D(i-1, j-1) + s1[i - 1]==s2[j - 1] ? 0 : 1}；中的三项分别对应D，I，S。

int minDistance(string word1, string word2)
{
	int len1 = word1.size();
	int len2 = word2.size();

	if (len1 == 0)
		return len2;
	if (len2 == 0)
		return len1;

	vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));

	for (int j = 0; j < dp[0].size(); ++j)
	{
		dp[0][j] = j;
	}
	for (int i = 0; i < dp.size(); ++i)
	{
		dp[i][0] = i;
	}

	for (int i = 1; i < dp.size(); ++i)
	{
		for (int j = 1; j < dp[0].size(); ++j)
		{
			int s1 = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
			int s2 = s1 < dp[i - 1][j] + 1 ? s1 : dp[i - 1][j] + 1;
			int s3 = s2 < dp[i][j - 1] + 1 ? s2 : dp[i][j - 1] + 1;
			dp[i][j] = s3;
		}
	}

	return dp[len1][len2];
}


int main(void)
{
	string word1("a");
	string word2("b");
	cout << minDistance(word1, word2) << endl;
	int aa;
	cin >> aa;
}