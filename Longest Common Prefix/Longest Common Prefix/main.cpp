#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
	string res;
	if (strs.size() == 0)
		return res;

	res = strs[0];
	for (int i = 1; i < strs.size(); ++i)
	{
		int l1 = res.size();
		int l2 = strs[i].size();
		int l = l1 < l2 ? l1 : l2;
		int j;
		for (j = 0; j < l; j++)
		{
			if (res[j] != strs[i][j])
			{
				res = strs[i].substr(0, j);
				break;
			}
		}
		if (j == l)
		{
			res = l1 < l2 ? res : strs[i];
		}
		
		if (res.size() == 0)
			break;
	}
	return res;
}

int main()
{
	vector<string> in;
	in.push_back("abchaha");
	in.push_back("abchdef");
	in.push_back("");
	cout << longestCommonPrefix(in) << endl;
	int aa;
	cin >> aa;
}