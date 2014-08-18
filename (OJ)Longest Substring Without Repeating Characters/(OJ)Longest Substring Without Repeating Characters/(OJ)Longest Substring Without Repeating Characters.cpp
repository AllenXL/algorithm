// (OJ)Longest Substring Without Repeating Characters.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
        int pos[256];
        for (int i = 0; i < 256; ++i)
        {
            pos[i] = -1;
        }
        
        int start = 0;
        int max = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (pos[s[i]] == -1)
            {
                pos[s[i]] = i;
				max = max < (i - start + 1) ? (i - start + 1) : max;
            }
            else
            {   
                for (int j = start; j < pos[s[i]]; ++j)
                {
                    pos[s[j]] = -1;
                }

				start = pos[s[i]] + 1;
                pos[s[i]] = i;
                
            }
        }
        return max;
        
}


int _tmain(int argc, _TCHAR* argv[])
{
	/*string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	cout <<str.size()<<endl;
	cout<<lengthOfLongestSubstring(str)<<endl;*/


	// test vector

	/*vector<int> iVec(10,1);
	for (int i = 0; i < iVec.size(); ++i)
	{
		cout << iVec[i] << endl;
	}

	cout << "use iterator:" << endl;
	int i = 0;
	for (vector<int>::iterator iter = iVec.begin(); iter != iVec.end(); ++iter)
	{
		*iter = ++i;
		cout << *iter << endl;
	}

	cout << "after erase the last num:"<<endl;
	iVec.erase(iVec.end() - 1);

	for (vector<int>::iterator iter = iVec.begin(); iter != iVec.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "add two nums:"<< endl;
	iVec.push_back(11);
	iVec.push_back(12);

	for (vector<int>::iterator iter = iVec.begin(); iter != iVec.end(); ++iter)
	{
		cout << *iter << endl;
	}

	iVec.front()*/


	//test set
	set<int> iSet;
	cout << iSet.size() << endl;
	iSet.insert(1);
	iSet.insert(1);
	cout << iSet.size() << endl;
	if (iSet.find(2) == iSet.end() )
		cout << "not find in set" << endl;
	cout << iSet.size() << endl;

	cout << iSet.count(1) << endl;

	iSet.erase(1);
	cout << iSet.size() << endl;

	map<string, int> iMap;
	iMap["a"]=1;
	iMap["b"]=2;
	cout << "a " << iMap["a"]<< endl;
	cout << "b " << iMap["b"]<< endl;
	cout << "c " << iMap["c"]<< endl;
	
	cout<<iMap.count("d");
	cout << iMap.size();

	if (iMap.find("d") == iMap.end())
		cout << "not find in map" << endl;
	cout << iMap.size() << endl;

	iMap.erase("a");
	cout << iMap.size() << endl;

	int a[3]={1};
	cout << a[0] << a[1] << a[2]<< endl;


	return 0;
}

