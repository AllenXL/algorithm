#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

//ֱ�ӽ�ȡS���ֵ䳤�ȵ��ַ�����һ�ηָ����word����ֱ��ͼ���Ƚ��Ƿ����ֵ��е�wordsһ�£� accept
/*vector<int> findSubstring(string S, vector<string> &L)
{
	vector<int> res;
	int dic_size = L.size();
	if (dic_size == 0)
	{
		return res;
	}

	int word_size = L[0].size();

	map<string, int> word_cnt;
	for (int i = 0; i < L.size(); ++i)
	{
		word_cnt[L[i]]++;
	}

	map<string, int> tmp_map;
	for (int i = 0; i < S.size() - dic_size * word_size + 1; ++i)
	{
		int j;
		tmp_map.clear();
		for (j = 0; j < dic_size; ++j)
		{
			string word = S.substr(i + j * word_size, word_size);
			if (word_cnt.find(word) == word_cnt.end())
				break;
			tmp_map[word]++;
			if (tmp_map[word] > word_cnt[word])
				break;
		}
		if (j == dic_size)
			res.push_back(i);
	}
	return res;
}*/

//

int main()
{
	string s("foobarhahabarfooxx");
	vector<string> dic;
	dic.push_back(string("foo"));
	dic.push_back(string("bar"));

	vector<int> res = findSubstring(s, dic);

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	int aa;
	cin >> aa;
}