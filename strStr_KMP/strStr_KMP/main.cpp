#include <iostream>

using namespace std;

void cal_next(const char* p, int next[])
{
	int n = strlen(p);
	if (!p || !next || n <= 0)
		return;
	
	next[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		int k = next[i - 1];
		while (k >= 0 && p[k] != p[i - 1])
			k = next[k];

		if (k < 0)
			next[i] = 0;
		else
			next[i] = k + 1;
	}
	return;
}

int KMP(const char* s, const char* p)
{
	int s_len = strlen(s);
	int p_len = strlen(p);

	int* next = new int[p_len];
	cal_next(p, next);

	int i = 0;
	int j = 0;
	int res = -1;

	while (i < s_len)
	{
		if (j == -1 || s[i] == p[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
		if (j == p_len)
		{
			res = i - p_len;
			break;
		}
	}
	delete next;
	return res;
}


int main()
{
	cout << KMP("abcxulongx", "xulong") << endl;
	int aa;
	cin >> aa;
}