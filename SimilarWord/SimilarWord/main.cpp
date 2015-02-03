#include <iostream>

using namespace std;

/*
两个长度相等的字符串，每个字符串中删掉一个字符，剩下的字符顺序不变，如果这样操作后得到的两个结果相同，就说是原来的两个字符串是相似的
*/

bool isSimilar(const char* s1, const char* s2)
{
	if (s1 == NULL || s2 == NULL)
		return false;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return false;
	int i = 0;
	int j = 0;
	int turn = -1;
	int diff = 0;
	int s = -1;
	while (i < len1 && j < len2)
	{
		//cout << i << " " << j << endl;
		if (s1[i] == s2[j])
		{
			++i;
			++j;
		}
		else
		{
			if (s == -1)
			{
				s = i;
				++j;
				turn = 1;
				diff = 0;
			}
			else if (turn == 1)
			{
				if (diff == 0)
				{
					++i;
					++diff;
				}
				else
				{
					i = s + 1;
					j = s;
					turn = 2;
					diff = 0;
				}
			}
			else if (turn == 2)
			{
				if (diff == 0)
				{
					++j;
					++diff;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	cout << "res:" << endl;
	cout << isSimilar("acf", "afe") << endl;
	int aa;
	cin >> aa;
}