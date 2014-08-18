// words_break(leetcode).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;

void get_sentences(string s, int len, map<int, vector<int> > &wordsMap, string sentence, vector<string>& res)
    {
        if (len == 0)
        {
            res.push_back(sentence);
            sentence.clear();
            return;
        }
        vector<int> words = wordsMap[len];
        for (int i = 0; i < words.size(); i++)
        {
            string cur = s.substr(words[i], len - words[i]);
            if (sentence.size() != 0)
            {
                cur += string(" ");
                cur += sentence;
            }           
            get_sentences(s, words[i], wordsMap, cur, res);
            
        }
    }

vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (s.length() == 0 || dict.size() == 0)
        {
            return res;
        }
        //DP  可以优化为一维数组
        int len = s.length();
        bool* seg = new bool[len + 1];
        memset(seg, 0, sizeof(bool) * (len + 1));
        seg[0] = true;
        
        map<int, vector<int> > wordsMap;
        //从0开始，长度为i的字符串，seg[i]=true, if seg[k] == true && s.substr(k, i-k) is in dict
        for (int i = 1; i <= len; i++)
        {
            for (int k = 0; k < i; k++)
            {
                if (seg[k] && dict.find(s.substr(k, i - k)) != dict.end())
                {
                    seg[i] = true;
                    wordsMap[i].push_back(k);
                }
            }
        }
        
        if (seg[len])
        {
            string sentence;
            get_sentences(s, len, wordsMap, sentence, res);
            return res;
        }
        return res;
        
    }
    
    



int _tmain(int argc, _TCHAR* argv[])
{
	unordered_set<string> dict;
	dict.insert(string("cat"));
	dict.insert(string("cats"));
	dict.insert(string("and"));
	dict.insert(string("sand"));
	dict.insert(string("dog"));
	string str = "catsanddog";
	vector<string> res;
	res = wordBreak(str, dict);

	for (vector<string>::iterator it = res.begin(); it != res.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}