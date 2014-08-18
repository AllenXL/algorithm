#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void show(vector<int>& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void show(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}

//Remove Duplicates from Sorted Array I
int removeDuplicates1(int A[], int n) 
{
	if (n == 0)
		return 0;

	int key = A[0];
	int p = 0;

	for (int i = 1; i < n; ++i)
	{
		if (A[i] == A[p])
			continue;
		A[++p] = A[i];
		key = A[i];
	}
	return p + 1;
}

//Remove Duplicates from Sorted Array II
int removeDuplicates(int A[], int n) 
{
	if (n == 0)
		return 0;

	int key = A[0];
	int p = 0;
	int cnt = 1;

	for (int i = 1; i < n; ++i)
	{
		if (A[i] != A[p])
		{
			A[++p] = A[i];
			key = A[i];
			cnt = 1;
		}
		else
		{
			if (cnt == 1)
			{
				A[++p] = A[i];
				key = A[i];
				cnt++;
			}
		}
	}
	return p + 1;
}


int main(void)
{
	int a[] = {1, 1, 1, 2, 2, 3};
	//vector<int> a1(a, a + sizeof(a)/sizeof(int));

	//show(a1);
	//sort(a1.begin(), a1.end());
	//sort(a, a + 5);
	//show(a, 5);

	cout << removeDuplicates(a, sizeof(a)/sizeof(int)) << endl;

	int aa;
	cin >> aa;
}