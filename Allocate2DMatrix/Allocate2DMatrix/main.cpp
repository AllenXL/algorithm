#include <iostream>

using namespace std;

int** Alloc2DMatrix(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
		return NULL;

	int** head;
	int len1 = sizeof(int*) * rows;
	int len2 = sizeof(int) * cols * rows;
	head = (int**)new char[len1 + len2];
	if (head == NULL)
		return NULL;

	int* start = (int*)(head + rows);
	for (int i = 0; i < rows; ++i)
	{
		head[i] = start + i * cols;
	}
	return head;
}

int main()
{
	int** m = Alloc2DMatrix(2, 2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;
	
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			cout << m[i][j] << endl;
	delete[] m;
	int aa;
	cin >> aa;
}