#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char> >& board, int a, int b)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != b && board[a][i] == board[a][b])
			return false;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (i != a && board[i][b] == board[a][b])
			return false;
	}

	int x = a / 3 * 3;
	int y = b / 3 * 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if ((x + i != a || y + j != b) && board[x + i][y + j] == board[a][b])
				return false;
		}
	}

	return true;
}

bool solveSudokuDfs(vector<vector<char> > &board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] != '.')
				continue;
			for (int num = 1; num <= 9; ++num)
			{
				board[i][j] = num + '0';
				if (isValid(board, i, j) && solveSudokuDfs(board))
					return true;
				board[i][j] = '.';
			}
			return false;
		}
	}
	return true;
}

void solveSudoku(vector<vector<char> > &board)
{
	solveSudokuDfs(board);
}

int main()
{
	int a;
	cin >> a;
}