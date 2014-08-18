// palidrome（leetcode）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;


 vector<string> tmp;
 vector<vector<string>> res;
 vector<int> cut_num;

void dp(string s, vector<vector<bool>>& palindrome_table)
    {
        int len = s.length();
        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i; j <= len - 1; j++)
            {
                if (i == j)
                {
                    palindrome_table[i][j] = true;
                }
                else if (j == (i + 1))
                {
                    if (s[i] == s[j])
                        palindrome_table[i][j] = true;
                }
                else
                {
                    if (s[i] == s[j] && palindrome_table[i+1][j-1] == true)
                        palindrome_table[i][j] = true;
                }
            }
        }
    }
    
    void dfs(int begin, string& s, int cut, vector<vector<bool>>& p_table)
    {
        if (begin == s.length())
        {
			cut_num.push_back(cut);
            res.push_back(tmp);
            return;
        }
        
        for (int i = begin; i < s.length(); ++i)
        {
            if (p_table[begin][i])
            {
				cut++;
                tmp.push_back(s.substr(begin, i - begin + 1));
                dfs(i + 1, s, cut, p_table);
                tmp.pop_back();
				cut--;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int len = s.length();
        if (len == 0)
        {
            return res;
        }
        
        vector<vector<bool>> pali_table(len, vector<bool>(len, false));
        dp(s, pali_table);
        dfs(0, s, 0, pali_table);
        return res;
    }

   void show(vector<vector<string>> str)
   {
	   for (vector<vector<string>>::iterator iter = str.begin(); iter != str.end(); iter++)
	   {
		   for(vector<string>::iterator i = (*iter).begin(); i != (*iter).end(); ++i)
		   {
			   cout << *i << " ";
		   }
		   cout << endl;
	   }
   }

   int minCut1(string s) 
   {
        vector<vector<string>> str = partition(s);
		if (str.size() == 0)
			return 0;
		int min = cut_num[0];
		for (vector<int>::iterator iter = cut_num.begin() + 1; iter != cut_num.end(); ++iter)
		{
			if (min > *iter)
				min = *iter;
		}
		return min;

   }

    int minCut(string s) 
   {
        int len = s.length();
        vector<vector<bool>> pali_table(len, vector<bool>(len, false));
        dp(s, pali_table);
        
        vector<int> cut(len+1, 0);
        for (int i = len - 1; i >= 0; --i)
        {
            cut[i] = len - i;
            for (int j = i; j < len; ++j)
            {
                if (pali_table[i][j])
                {
                    cut[i]  = cut[i] < 1+cut[j+1] ? cut[i] : 1+cut[j+1];
                }
            }
        }
        
        return cut[0] - 1;

   }

	//判断字符串是否是回文，不包含字母外的字符

	bool is_palindrome1(string s)
	{
		int len = s.length();
		if (len <= 1)
		{
			return true;
		}
		int i = 0;
		int j = len - 1;

		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}

	//判断字符串是否是回文，包含字母外的字符"A man, a plan, a canal: Panama" is a palindrome.
	bool is_char(char& c)
	{
		if (c >= '0' && c <='9')
			return true;
		if (c >= 'a' && c <= 'z')
			return true;
		if (c >= 'A' && c <= 'Z')
		{
			c += 32;
			return true;
		}
		return false;	
	}
	bool is_palindrome2(string s)
	{
		int len = s.length();
		if (len == 0)
		{
			return true;
		}
		int i = 0;
		int j = len - 1;
		while(i < j)
		{
			while(!is_char(s[i]) && i < j)
				i++;
			while(!is_char(s[j]) && i < j)
				j--;
			if (i >= j)
				return true;
			if (s[i] != s[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
	}

	 bool isPalindrome(int x) {
        //cout<<sizeof(long long);
        if(x < 0)
            return false;
        long long xx = x;
        long long s = 1;
        while(xx / s)
            s *= 10;
        s /= 10;
        long long e = 10;
        //if(s < e) cout<<s<<"vs"<<e<<"forx"<<x;
        while(s >= e) {
            long long sd = (xx / s);
            long long ed = (xx % e) / (e / 10);
			cout << sd << " " << ed << endl;
            if(sd!=ed) {
                //cout<<sd<<"vs"<<ed<<"at"<<s;
                return false;
            }
            //cout<<sd<<"vs"<<ed<<"at"<<s;
            xx = xx % s;
			cout << xx << endl;
            s /= 10;
            e *= 10;
        }
        return true;
    }
	 //对高位，先取余再除，对低位，先除再取余
	 bool isPalindrome2(int x) {
        if (x < 0)
        {
            return false;
        }
        
        long long div = 10;
		long long  cnt = 1;
        while (x/div)
        {
			cout << "div: " << div << endl;
			cnt++;
            div *= 10;
        }
		cout << "div1: " << div << endl;
		div = div / 10;
		cnt /= 2;
		cout << cnt << endl;
        cout << "div: " << div << endl;
        while (cnt)
        {
			cnt--;
            long long  high = x / div;
            long long  low = x % 10;
            
			cout << high << " " << low << endl;
            if (high != low)
            {
                return false;
            }
            x = (x % div) / 10;
            div = div / 100;
        }
        return true;
    }

	 bool isPalindrome3(int x) {
        if (x < 0)
        {
            return false;
        }
        
        long long div = 1;
        long long cnt = 1;
        while (x / div)
        {
            div *= 10;
            cnt++;
        }
        div = div / 10;
        cnt /= 2;
        
        long long div2 = 10;
        while (cnt > 0)
        {
            cnt--;
			cout << div << " " << div2 << endl;
            long long high = (x / div) % 10;
            long long low = (x % div2) / (div2 / 10);
			cout << high << " " << low <<endl;
            if (high != low)
            {
                return false;
            }
            div /= 10;
            div2 *= 10;
        }
        return true;
    }
int _tmain(int argc, _TCHAR* argv[])
{
	string s("abc");
	vector<vector<string>> str = partition(s);
	show(str);
	cout << minCut(s) << endl;
	
	s=string("abba");
	cout << is_palindrome1(s) << endl;
	
	s=string("A man, a plan, a canal: Panama");
	cout << is_palindrome2(s) << endl;
	cout << "begin"<< endl;
	cout << isPalindrome3(1000000001) << endl;
	return 0;
}

