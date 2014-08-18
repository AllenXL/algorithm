#include <iostream>
#include <vector>
#include <stack>
using namespace std;


template <typename T>
void show_matrix(vector<vector<T> > v)
{
	cout << "show:" << endl;
	for (vector<vector<T> >::iterator itr = v.begin(); itr != v.end(); ++itr)
	{
		for (vector<T>::iterator i = (*itr).begin(); i != (*itr).end(); ++i)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
}


int rows = 0;
int cols = 0;

void dfs(int row, int col, vector<vector<char> >& board) 
{
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return;
	if (board[row][col] != 'O') return;
	board[row][col] = '+';
	dfs(row - 1, col, board);
	dfs(row, col + 1, board);
	dfs(row + 1, col, board);
	dfs(row, col - 1, board);
}

void solve(vector<vector<char> > &board)
{
	if (board.size() == 0 || board[0].size() == 0)
		return;

	rows = board.size();
	cols = board[0].size();

	for (int i = 0; i < rows; i++)
	{
		dfs(i, 0, board);
		dfs(i, cols - 1, board);
	}
	for (int j = 1; j < cols - 1; j++)
	{
		dfs(0, j, board);
		dfs(rows - 1, j, board);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == '+')
				board[i][j] = 'O';
			else if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
}

//用递归导致栈溢出，改用stack
void dfs2(int row, int col, vector<vector<char> >& board)
{
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return;

	stack<int> s;
	int idx = row * cols + col;
	s.push(idx);

	while (!s.empty())
	{
		int tmp = s.top();
		s.pop();
		row = tmp / cols;
        col = tmp % cols;
		char c = board[row][col];

		if (c == 'O')
		{
			board[row][col] = '+';
			if (row > 0 && board[row - 1][col] == 'O')
			{
				s.push((row - 1) * cols + col);
			}
			if (col < cols - 1 && board[row][col + 1] == 'O')
			{
				s.push(row * cols + col + 1);
			}
			if (row < rows - 1 && board[row + 1][col] == 'O')
			{
				s.push((row + 1) * cols + col);
			}
			if (col > 0 && board[row][col - 1] == 'O')
			{
				s.push(row * cols + col - 1);
			}
		}
	}

	//show_matrix(board);
}

void solve2(vector<vector<char> > &board)
{
	if (board.size() == 0 || board[0].size() == 0)
		return;

	rows = board.size();
	cols = board[0].size();

	for (int i = 0; i < rows; i++)
	{
		dfs2(i, 0, board);
		dfs2(i, cols - 1, board);
	}
	for (int j = 1; j < cols - 1; j++)
	{
		dfs2(0, j, board);
		dfs2(rows - 1, j, board);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == '+')
				board[i][j] = 'O';
			else if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
}


void main()
{
	cout << "hello world" << endl;

	vector<vector<char> > v;
	
	/*vector<char> v1(3, 'X');
	v.push_back(v1);

	v1[1] = 'O';
	v.push_back(v1);

	v1[1] = 'X';
	v.push_back(v1);*/

	char c1[6] = {'O', 'O', 'O', 'O', 'X', 'X'};
	vector<char> v1(c1, c1 + 6);
	v.push_back(v1);

	char c2[6] = {'O', 'O', 'O', 'O', 'O', 'O'};
	vector<char> v2(c2, c2 + 6);
	v.push_back(v2);

	char c3[6] = {'O', 'X', 'O', 'X', 'O', 'O'};
	vector<char> v3(c3, c3 + 6);
	v.push_back(v3);

	char c4[6] = {'O', 'X', 'O', 'O', 'X', 'O'};
	vector<char> v4(c4, c4 + 6);
	v.push_back(v4);

	char c5[6] = {'O', 'X', 'O', 'X', 'O', 'O'};
	vector<char> v5(c5, c5 + 6);
	v.push_back(v5);

	char c6[6] = {'O', 'X', 'O', 'O', 'O', 'O'};
	vector<char> v6(c6, c6 + 6);
	v.push_back(v6);

	


	show_matrix(v);
	solve2(v);
	cout << "res:" << endl;
	show_matrix(v);


	int a;
	cin >> a;
}