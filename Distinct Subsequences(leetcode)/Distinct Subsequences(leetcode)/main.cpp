#include <iostream>
#include <vector>
#include <string>

using namespace std;

//DP, f(i, j)表示，S(0-i)转换到S(0-j)的所有可行变换数
//f(i, j) = f(i-1, j) + S[i]==T[j] ? f(i-1, j-1) : 0; 
int numDistinct(string S, string T) 
{
	if (T.size() == 0)
		return 1;
	vector<int> num(T.size(), 0);

	int prev_old;
	int cur_old;
	for (int i = 0; i < S.size(); i++)
	{
		prev_old = 1;
		for (int j = 0; j < T.size(); j++)
		{
			cur_old = num[j];

			if (S[i] == T[j])
				num[j] += prev_old;

			prev_old = cur_old;
		}
	}

	return num.back();
}



int main(void)
{
	string S("rabbbit");
	string T("rabbit");
	cout << numDistinct(S, T) << endl;
	int aa;
	cin >> aa;
}