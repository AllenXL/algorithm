#include <iostream>
#include <vector>
#include <set>

using namespace std;

void show(vector<vector<int> >& m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j <m[i].size(); ++j)
			cout << m[i][j] << " ";
		cout << endl;
	}
}

void setZeroes(vector<vector<int> > &matrix)
{
	set<int> col_del;
	set<int> row_del;

	if (matrix.size() == 0)
		return;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == 0)
			{
				col_del.insert(j);
				row_del.insert(i);
			}
		}
	}

	for (set<int>::iterator iter = col_del.begin(); iter != col_del.end(); ++iter)
	{
		for (int i = 0; i < matrix.size(); ++i)
			matrix[i][*iter] = 0;
	}
	for (set<int>::iterator iter = row_del.begin(); iter != row_del.end(); ++iter)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			matrix[*iter][j] = 0;
		}
	}
}


int main(void)
{
	vector<vector<int> > m;
	vector<int> tmp;
	tmp.push_back(0);
	tmp.push_back(1);
	m.push_back(tmp);

	show(m);
	cout << endl;
	setZeroes(m);
	show(m);
	int aa;
	cin >> aa;
	return 0;
}