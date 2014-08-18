#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

//两个字符串的字符个数完全相同，这两个字符串是Anagrams。因此Anagrams至少指俩字符串。找出字符集合中的Anagrams组。
vector<string> anagrams(vector<string> &strs) 
{
	map<string, vector<string> > anagramMap;
	for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); ++iter)
	{
		string key(*iter);
		sort(key.begin(), key.end());
		anagramMap[key].push_back(*iter); 
	}

	vector<string> result;
	for (map<string, vector<string> >::iterator iter = anagramMap.begin(); 
		iter != anagramMap.end(); ++iter)
	{
		if ((iter->second).size() > 1)
		{
			for (int i = 0; i < (iter->second).size(); ++i)
			{
				result.push_back((iter->second)[i]);
			}
		}
	}
	return result;
}


int main(void)
{
	vector<string> in;
	in.push_back("xulong");
	in.push_back("gnolux");
	in.push_back("allon");

	vector<string> out;
	out = anagrams(in);

	for (int i = 0; i < out.size(); ++i)
		cout << out[i] << endl;

	int aa;
	cin >> aa;
	return 0;
}