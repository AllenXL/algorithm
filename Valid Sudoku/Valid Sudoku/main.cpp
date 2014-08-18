#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board)
{
	vector<vector<bool> > rows(9, vector<bool>(9, false));
	vector<vector<bool> > cols(9, vector<bool>(9, false));
	vector<vector<bool> > blocks(9, vector<bool>(9, false));

	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '1';
			if (rows[i][num] || cols[j][num] || blocks[i / 3 * 3 + j / 3][num])
				return false;

			rows[i][num] = true;
			cols[j][num] = true;
			blocks[i / 3 * 3 + j / 3][num] = true;
		}
	}
	return true;
}

int main()
{
	vector<vector<char> > in(9, vector<char>(9, '1'));
	isValidSudoku(in);
	int a;
	cin >> a;
}