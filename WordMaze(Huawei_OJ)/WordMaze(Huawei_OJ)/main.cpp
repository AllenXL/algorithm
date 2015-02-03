#include <iostream>
#include <vector>
#include <string>

using namespace std;

//迷宫中搜索单词

//dfs，由于迷宫中的字母只能用一次，所以需要设置一个标记矩阵

bool helper(vector<vector<char> >& maze, vector<vector<bool> >& flag, int i, int j, int idx, string& target)
{
	if (idx == target.size())
	{
		return true;
	}

	if (maze[i][j] != target[idx])
		return false;

	flag[i][j] = true;

	bool res = false;
	//top
	if (i - 1 >= 0 && !flag[i - 1][j])
	{
		res = helper(maze, flag, i - 1, j, idx + 1, target);
		if (res)
			return true;
	}

	//right
	if (j + 1 < maze[0].size() && !flag[i][j + 1])
	{
		res = helper(maze, flag, i, j + 1, idx + 1, target);
		if (res)
			return true;
	}

	//bottom
	if (i + 1 < maze.size() && !flag[i + 1][j])
	{
		res = helper(maze, flag, i + 1, j, idx + 1, target);
		if (res)
			return true;
	}

	//left
	if (j - 1 >= 0 && !flag[i][j - 1])
	{
		res = helper(maze, flag, i, j - 1, idx + 1, target);
		if (res)
			return true;
	}

	flag[i][j] = false;
	return false;
}

bool findWord(vector<vector<char> > & maze, vector<vector<bool> >& flag, string target)
{
	int n = maze.size();
	int m = maze[0].size();

	bool isFound = false;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (maze[i][j] == target[0])
			{
				isFound = helper(maze, flag, i, j, 0, target);
				if (isFound)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	string target;
	cin >> target;

	vector<vector<char> > maze(n, vector<char>(m));
	vector<vector<bool> > flag(n, vector<bool>(m, false));

	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			maze[i][j] = str[j];
		}
	}
	
	if (findWord(maze, flag, target))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;

	int aa;
	cin >> aa;
	return 0;
}

/*
5 5
SOLO
CPUCY
EKLQH
CRSOL
EKLQO
PGRBC 
*/