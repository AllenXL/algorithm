#include <iostream>
#include <vector>

using namespace std;

int binary_search(int A[], int n, int target)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (A[mid] == target)
			return mid;
		else if (A[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return -1;
}

//改进一下二分法就可以了
vector<int> searchRange(int A[], int n, int target)
{
	int left = 0;
	int right = n - 1;
	vector<int> res;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (A[mid] == target)
		{
			int l = mid;
			while (l >= 0 && A[l] == target)
				l--;
			int r = mid;
			while (r <= n - 1 && A[r] == target)
				r++;
			res.push_back(++l);
			res.push_back(--r);
			return res;
		}		
		else if (A[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}

	res.push_back(-1);
	res.push_back(-1);
	return res;
	
}



int main()
{
	int A[] = {1, 2, 3, 8, 8, 10};
	vector<int> res = searchRange(A, 6, 8);
	cout << res[0] << endl;
	cout << res[1] << endl;
	
	int aa;
	cin >> aa;
	return 0;
}