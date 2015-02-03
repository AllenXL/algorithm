#include <string.h>
#include <iostream>
#include <string>

using namespace std;

void GetNext(char* p, int* next)
{
    if (p == NULL || next == NULL)
    {
        return;
    }
    next[0] = -1;
    int k = -1;
    int i = 0;
    int len = strlen(p);
    while (i < len - 1)
    {
        if ( k == -1 || p[k] == p[i])
        {
            k++;
            i++;
            next[i] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int KMP_Count(char* s, char* p)
{
    int cnt = 0;
    if (s == NULL || p == NULL)
    {
        return cnt;
    }

    int sLen = strlen(s);
    int pLen = strlen(p);

    int* next = new int[pLen];
    GetNext(p, next);

    int i = 0;
    int j = 0;
    while (i < sLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }

        if (j == pLen)
        {
            cnt++;
            i--;
            j = next[j - 1];
        }
    }

    delete[] next;
    return cnt;
}

int main()
{
    /*char* s = "aaa";
    char* p = "a";
    cout << KMP_Count(s, p) << endl;*/

    int n;
    cin >> n;
    char s[1000005] = {0};
    char p[10005] = {0};

    while (n--)
    {
        cin >> p;
        cin >> s;
        cout << KMP_Count(s, p) << endl;
    }
    return 0;
}
