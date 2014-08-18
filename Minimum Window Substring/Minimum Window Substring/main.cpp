#include <string>
#include <iostream>

using namespace std;

//双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，
//再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的
//何时停止收缩指针？当hasFind[S[start]] == needFind[S[start]]时，因为此时start和end间字符S[start]的个数刚好满足要求，
//不能再缩了

string minWindow(string S, string T)
{
	int needFind[256] = {0}; //记录原始T字符串的patter，即字符直方图
	int hasFind[256] = {0}; //始终保存当前start和end间T中字符的个数

	for (int i = 0; i < T.size(); ++i)
	{
		needFind[T[i]]++;
	}


	int begin = 0;
	int end = 0;
	int count = 0; //记录begin~end间已找到T中字符的个数， 如果aaa，但T中只有两个aa,则count=2

	int minLen = INT_MAX;
	int minBegin = 0;

	for (; end < S.size(); end++)
	{
		if (needFind[S[end]] == 0)
			continue;

		hasFind[S[end]]++;
		
		if (hasFind[S[end]] <= needFind[S[end]])
			count++;

		if (count == T.size())
		{
			while (true)
			{
				if (needFind[S[begin]] == 0)
				{
					begin++;
					continue;
				}
				else
				{
					if (hasFind[S[begin]] > needFind[S[begin]])
					{
						hasFind[S[begin]]--;
						begin++;
						continue;
					}
					else
					{
						break;
					}
				}
			}
			int cur_len = end - begin + 1;
			if (minLen >= cur_len)
			{
				minLen = cur_len;
				minBegin = begin;
			}
		}
	}

	if (minLen == INT_MAX)
		return "";
	else
		return S.substr(minBegin, minLen);

}


int main(void)
{
	//cout << numeric_limits<int>::max() << endl;
	//cout << INT_MAX << endl;

	string S("ADOBECODEBANC");
	string T("ABC");

	cout << minWindow(S, T) << endl;

	int aa;
	cin >> aa;
}