#include <iostream>
#include <string>
#include <vector>

using namespace std;

//一个单词  左对齐
//n个单词   两端对齐
//最后一行  左对齐，此间一空格

string justify_line(vector<string>& words, int L, int word_len)
{
	string tmp;

	if (words.size() == 1)
	{
		tmp += words[0];
		for (int i = 0; i < (L - word_len); ++i)
		{
			tmp += " ";
		}
		return tmp;
	}
	
	int space_avg = (L - word_len) / (words.size() - 1);
	int extra = (L - word_len) % (words.size() - 1);

	tmp = words[0];
	for (int i = 1; i < words.size(); ++i)
	{
		for (int j = 0; j < space_avg; j++)
		{
			tmp += " ";
		}
		if (extra > 0)
		{
			tmp += " ";
			extra--;
		}
		tmp += words[i];
	}
	return tmp;
}

string justify_end(vector<string>& words, int L)
{
	string res;
	res = words[0];
	int word_len = words[0].size();
	for (int i = 1; i < words.size(); ++i)
	{
		res += " " + words[i];
		word_len += words[i].size() + 1;
	}
	
	for (int i = 0; i < (L - word_len); ++i)
	{
		res += " ";
	}
	return res;
}

vector<string> fullJustify(vector<string> &words, int L)
{
	vector<string> res;
	int total_len = 0;
	int word_len = 0;
	vector<string> tmp;
	for (int i = 0; i < words.size(); ++i)
	{
		if (total_len + words[i].size() + 1 > L + 1)
		{
			res.push_back(justify_line(tmp, L, word_len));
			total_len = 0;
			word_len = 0;
			tmp.clear();
		}
		tmp.push_back(words[i]);
		total_len += words[i].size() + 1;
		word_len += words[i].size();
	}

	if (tmp.size() > 0)
		res.push_back(justify_end(tmp, L));
	return res;
}

void show(vector<string>& res)
{
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << "*" << endl;
}

int main(void)
{
	vector<string> src;
	src.push_back("What");
	src.push_back("must");
	src.push_back("be");
	src.push_back("shall");
	src.push_back("be.");
	//src.push_back("text");
	//src.push_back("justification.");

	show(src);
	vector<string> res = fullJustify(src, 12);
	cout << endl;
	show(res);


	int aa;
	cin >> aa;
	return 0;
}