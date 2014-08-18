#include <iostream>
#include <vector>

using namespace std;


template <typename T>
void show(vector<vector<T> >& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*
����˼·�ǰ�ͼƬ��Ϊ����/2�㣬Ȼ��һ��������ת��ÿһ�������������ĸ��У�Ȼ��Ŀ����ǰ����зŵ����У����зŵ����У����зŵ����У����зŻ����У�
�м䱣��һ����ʱ�������ɡ���Ϊÿ��Ԫ�ذ��˵Ĵ������ᳬ��һ�Σ�ʱ�临�Ӷ���O(����Ĵ�С)���ռ临�Ӷ���O(1)��
*/

void rotate(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	int layerNum = n / 2;

	for (int i = 0; i < layerNum; ++i)
	{
		for (int j = i; j < n - 1 - i; ++j)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 -j];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

int main()
{

	int aa;
	cin >> aa;
	return 0;
}
