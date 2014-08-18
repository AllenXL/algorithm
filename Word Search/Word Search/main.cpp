#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool res = false;
int Dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(vector<vector<char> >& board, int i, int j, string& word, int dep, vector<vector<bool> >& visited)
{
	if (res || dep == word.size())
	{
		res = true;
		return;
	}

	for (int d = 0; d < 4; ++d)  
        {  
            int nextX = i+Dir[d][0];  
            int nextY = j+Dir[d][1];  
            if(nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board[0].size())  
            {  
                if(!visited[nextX][nextY] && word[dep] == board[nextX][nextY])  
                {  
                    visited[nextX][nextY] = true;  
                    dfs(board, nextX, nextY, word, dep + 1, visited); 
                    visited[nextX][nextY] = false;  
                }  
            }  
  
        }  


}

bool exist(vector<vector<char> > &board, string word)
{
	res = false;
	vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (res)
				return true;
			if (board[i][j] == word[0])
			{
				visited[i][j] = true;
				dfs(board, i, j, word, 1, visited);
				visited[i][j] = false;
			}
		}
	}
	
	return res;
}

int main(void)
{
	char a[3][4] = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	vector<vector<char> > data(3, vector<char>(4));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; j++)
		{
			data[i][j] = a[i][j];
		}
	}

	//char a[2][2] = {
	//	{'A', 'B'},
	//	{'S', 'F'}
	//};
	//vector<vector<char> > data(2, vector<char>(2));
	//for (int i = 0; i < 2; ++i)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		data[i][j] = a[i][j];
	//	}
	//}
	
	cout << exist(data, string("ECB")) << endl;

	int aa;
	cin >> aa;
}