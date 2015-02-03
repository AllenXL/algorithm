#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>

using namespace std;

void ShowGraph(int graph[][4], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(int graph[][4], int row, int col)
{
	char nodes[] = {'a', 'b', 'c', 'd'};

	map<int, int> visited;
	queue<int> q;

	cout << nodes[0];
	visited[0] = 0;
	q.push(0);

	int print_layer = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int cur_layer = visited[cur] + 1;

		for (int i = 0; i < 4; ++i)
		{
			if (graph[cur][i] == 1 && visited.find(i) == visited.end())
			{
				if (print_layer != cur_layer)
				{
					cout << endl;
					print_layer = cur_layer;
				}
				cout << nodes[i] << " ";
				q.push(i);
				visited[i] = cur_layer;
			}
		}
	}

}

   int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        
        s.push_back(')');
        stack<int> st;
        int max = 0;
        int left = -1;
        int i = 0;
        for (; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if (i == s.size() - 1 || st.empty())
                {
                    max = max < (i - left - 1) ? (i - left - 1) : max;
                    left = i;
                }
                else
                {
                    st.pop();
                }
            }
        }

        return max;
        
    }

    int sqrt(int x) {
        if (x < 0)
            return -1;
        int i = 0;
        int j = x;
        while (i <= j)
        {
            int m = i + (j - i) / 2;

            if (m * 1.0 * m - x == 0)
            {
                return m;
            }
            else if (m * 1.0 * m - x < 0)
            {
                i = m + 1;
            }
            else
            {
                j = m - 1;
            }
        }
        return j;
    }


	bool helper(string s1, int idx1, string s2, int idx2, string s3, int idx3)
    {
        if (idx1 == s1.size())
        {
            return s2.substr(idx2) == s3.substr(idx3);
        }
        
        if (idx2 == s2.size())
        {
            return s1.substr(idx1) == s3.substr(idx3);
        }
        int len1 = s1.size() - idx1;
        int len2 = s2.size() - idx2;
        int len3 = s3.size() - idx3;
        if (len1 + len2 != len3)
        {
            return false;
        }
        
        if (s3[idx3] == s1[idx1])
        {
            return helper(s1, idx1 + 1, s2, idx2, s3, idx3 + 1);
        }
        else if (s3[idx3] == s2[idx2])
        {
            return helper(s1, idx1, s2, idx2 + 1, s3, idx3 + 1);
        }
        else
        {
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0)
			return s2 == s3;
		if (s2.size() == 0)
			return s1 == s3;
		
		if (s1.size() + s2.size() != s3.size())
			return false;

		vector<vector<bool> > dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		dp[0][0] = true;
		for (int i = 1; i < dp[0].size(); ++i)
		{
			dp[0][i] = (s2.substr(0, i) == s3.substr(0, i));
		}
		for (int j = 1; j < dp.size(); ++j)
		{
			dp[j][0] = (s1.substr(0, j) == s3.substr(0, j));
		}

		for (int i = 1; i <= s1.size(); ++i)
		{
			for (int j = 1; j <= s2.size(); ++j)
			{
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[s1.size()][s2.size()];
    }

	   int minPathSum(vector<vector<int> > &grid) {
        if (grid.size() == 0)
            return 0;
            
        int len1 = grid.size();
        int len2 = grid[0].size();
        vector<vector<int> > dp(len1, vector<int>(len2, 0));
        
        dp[0][0] = grid[0][0];
        for (int j = 1; j < len2; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < len1; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        cout << dp[1][0] << endl;
        for (int i = 1; i < len1; ++i)
        {
            for (int j = 1; j < len2; ++j)
            {
                dp[i][j] = grid[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
            }
        }
        
        return dp[len1 - 1][len2 - 1];
    }


void GetNext(char* p, int* next)
    {
        int len = strlen(p);
        next[0] = -1;
        
        int i = 0;
        int k = -1;
		cout << "len = " << len << endl;
        while (i < len - 1)
        {
			cout << "ok" << endl;
			cout << i << endl;
            if (k == -1 || p[k] == p[i])
            {
                i++;
                k++;
                next[i] = k;
				cout << i << " " << k << endl;
            }
            else
            {
                k = next[k];
            }
        }
    }
    
    int KMP(char* s, char* p)
    {
        if (s == NULL || p == NULL)
            return -1;
        
        int lenS = strlen(s);
        int lenP = strlen(p);
        int i = 0;
        int j = 0;
        
        int* next = new int[lenP];
        GetNext(p, next);
        
        while (i < lenS && j < lenP)
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
        }
        
        delete[] next;
        if (j == lenP)
        {
            return i - lenP;
        }
        else
        {
            return -1;
        }
    }
    


int main()
{
	int adjacent[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
	ShowGraph(adjacent, 4, 4);
	BFS(adjacent, 4, 4);
	
	cout << endl;
	string str("(");
	cout << longestValidParentheses(str) << endl;
	cout << sqrt(2147395599) << endl;


	string s1("aa");
	string s2("b");
	string s3("aba");
	cout << isInterleave(s1, s2, s3) << endl;

	vector<vector<int> > a;
	vector<int> b;
	b.push_back(0);
	b.push_back(1);
	a.push_back(b);
	b.clear();
	b.push_back(1);
	b.push_back(0);
	a.push_back(b);
	cout << minPathSum(a) << endl;

	cout << "KMP: " << KMP("abcd", "bc") << endl;
	int aa;
	cin >> aa;
}