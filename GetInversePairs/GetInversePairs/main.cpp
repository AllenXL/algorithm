#include <iostream>

using namespace std;

int InversPairsHelper(int* data, int* copy, int begin, int end)
{
	if (begin == end)
	{
		copy[begin] = data[begin];
		return 0;
	}

	int mid = begin + (end - begin) / 2;

	int left = InversPairsHelper(copy, data, begin, mid);
	int right = InversPairsHelper(copy, data, mid + 1, end);

	int i = mid;
	int j = end;
	int cnt = 0;
	int copy_idx = end;

	while (i >= begin && j >= mid + 1)
	{
		if (data[i] > data[j])
		{
			cnt += j - mid;
			copy[copy_idx] = data[i];
			copy_idx--;
			i--;
		}
		else
		{
			copy[copy_idx] = data[j];
			j--;
			copy_idx--;
		}
	}

	while (i >= begin)
	{
		copy[copy_idx--] = data[i--];
	}
	while (j >= mid + 1)
	{
		copy[copy_idx--] = data[j--];
	}
	return cnt + left + right;
}

//将上面函数再练习一遍
int InversePairesHelper2(int* data, int* copy, int s, int e)
{
	if (s == e)
	{
		copy[s] = data[s];
		return 0;
	}

	int m = s + (e - s) / 2;
	int left = InversePairesHelper2(data, copy, s, m);
	int right = InversePairesHelper2(data, copy, m + 1, e);

	int i = m;
	int j = e;
	int cnt = left + right;
	int idx = e;
	while (i >= s && j >= m + 1)
	{
		if (copy[j] >= copy[i])
		{
			data[idx] = copy[j];
			idx--;
			j--;
		}
		else
		{
			data[idx] = copy[i];
			idx--;
			cnt += j - m;
			i--;
		}
	}

	while (i >= e)
	{
		data[idx] = copy[i];
		i--;
		idx--;
	}

	while (j >= m + 1)
	{
		data[idx] = copy[j];
		j--;
		idx--;
	}

	for (int i = s; i <= e; ++i)
	{
		copy[i] = data[i];
	}
	return cnt;
}

int InversePairs(int* data, int len)
{
	if (data == NULL || len == 0)
		return 0;

	int * copy = new int[len];

	for (int i = 0; i < len; ++i)
	{
		copy[i] = data[i];
	}

	int count = InversePairesHelper2(data, copy, 0, len - 1);

	delete[] copy;

	return count;
}

int main()
{
	int data[] = {7, 5, 8, 2};
	cout << InversePairs(data, sizeof(data) / sizeof(int)) << endl;
    
	int aa;
	cin >> aa;
}