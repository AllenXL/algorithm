#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Í¶Æ±¼ÆÊý

int main()
{
	map<string, int> voteMap;
	vector<string> candidates;
	int invalid = 0;

	string cmd;
	string val;

	cin >> cmd;
	while (cmd != string("getVoteResult"))
	{
		cin >> val;
		if (cmd == string("addCandidate"))
		{
			candidates.push_back(val);
			voteMap[val] = 0;
		}
		else if (cmd == string("vote"))
		{
			if (voteMap.find(val) != voteMap.end())
			{
				voteMap[val]++;
			}
			else
			{
				invalid++;
			}
		}
		cin >> cmd;
	}
	for (int i = 0; i < candidates.size(); ++i)
	{
		cout << candidates[i] << " " << voteMap[candidates[i]] << endl;
	}
	cout << invalid << endl;
}