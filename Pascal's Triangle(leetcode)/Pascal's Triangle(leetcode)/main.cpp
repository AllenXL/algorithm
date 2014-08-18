#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void show(vector<vector<T> > data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = 0; j < data[i].size(); ++j)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int> > generate(int numRows) 
{
	vector<vector<int> > res;

	if (numRows == 0)
		return res;

	res.push_back(vector<int>(1, 1));

	for (int i = 1; i < numRows; ++i)
	{
		vector<int> cur(i + 1);
		for (int j = 0; j < (i + 1); j++)
		{
			int sum = 0;
			if (j > 0)
			{
				sum += res[i - 1][j - 1];
			}

			if (j < res[i - 1].size())
			{
				sum += res[i - 1][j];
			}
			cur[j] = sum;
		}
		res.push_back(cur);
	}
        
    return res;
}

//get k-th row of pascal triangle
vector<int> getRow(int rowIndex) 
{
	vector<int> res(rowIndex + 1, 1);

	res[0] = 1;

	for (int i = 1; i <= rowIndex; i++)
	{
		int prev_old = res[0];
		for (int j = 1; j < i; j++)
		{
			int cur = res[j];
			res[j] = prev_old + res[j];
			prev_old = cur;
		}
	}

	return res;
}

int main(void)
{
	show(generate(5));

	vector<int> row = getRow(0);

	for (int i = 0; i < row.size(); ++i)
		cout << row[i] << " ";
	int aa;
	cin >> aa;
}