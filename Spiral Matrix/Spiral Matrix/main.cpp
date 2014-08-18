#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void show(vector<vector<T> > &a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[0].size(); ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void show_v(vector<T> &a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

//一层层的输出，抓住每层对角线上的两个点即可
vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> res;
	if (matrix.size() == 0)
		return res;

	int x1 = 0;
	int y1 = 0;
	int x2 = matrix.size() - 1;
	int y2 = matrix[0].size() - 1;

	while (x1 <= x2 && y1 <= y2)
	{
		//up row
		for (int j = y1; j <= y2; ++j)
			res.push_back(matrix[x1][j]);

		//right colomn
		for (int i = x1 + 1; i <= x2; ++i)
			res.push_back(matrix[i][y2]);

		//bottom row
		if (x1 != x2)
		{
			for (int j = y2 - 1; j >= y1; --j)
				res.push_back(matrix[x2][j]);
		}

		//left colomn
		if (y1 != y2)
		{
			for (int i = x2 - 1; i >= x1 + 1; --i)
				res.push_back(matrix[i][y1]);
		}

		x1++;
		y1++;
		x2--;
		y2--;
	}

	return res;

}

int main()
{
	int m1[] = {1, 2, 3};
	int m2[] = {4, 5, 6};
	int m3[] = {7, 8, 9};

	vector<vector<int> > m;
	m.push_back(vector<int>(m1, m1 + 2));
	//m.push_back(vector<int>(m2, m2 + 3));
	//m.push_back(vector<int>(m3, m3 + 3));
	show(m);

	cout << "spiral matrix res:" << endl;

	//vector<int> res = spiralorder(m);
	show_v(spiralOrder(m));

	int aa;
	cin >> aa;
	return 0;
}