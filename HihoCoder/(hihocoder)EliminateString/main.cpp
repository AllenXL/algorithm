#include <iostream>
#include <string>

using namespace std;

int reduceStr(string str)
{
    int len = str.size();
    if (len <= 1)
    {
        return 0;
    }

    string reduced;
    for (int i = 0; i < len; ++i)
    {
        if ((i > 0) && str[i] == str[i - 1])
        {
            continue;
        }

        if (i < len - 1 && str[i] == str[i + 1])
        {
            continue;
        }
        reduced += str.substr(i, 1);
    }

    int res = str.size() - reduced.size();
    if (res == 0)
        return res;
    res += reduceStr(reduced);

    return res;
}

int getScore(string str)
{
    int len = str.size();
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
        string tmp = str;
        tmp.insert(i, "A");
        res = max(res, reduceStr(tmp));

        tmp = str;
        tmp.insert(i, "B");
        res = max(res, reduceStr(tmp));

        tmp = str;
        tmp.insert(i, "C");
        res = max(res, reduceStr(tmp));
    }
    return res;
}

int main()
{
    int n;
    string str;

    cin >> n;
    while (n--)
    {
        cin >> str;
        cout << getScore(str) << endl;
    }

    return 0;
}
