#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int firstMissingPositive(int A[], int n)
{
	if (n <= 0)
		return 1;
	//vector<int> vec(A, A + n);
	sort(A, A + n);
	
	int missing = 1;
	for (int i = 0; i < n; ++i)
	{
		//cout << A[i] << endl;
		if (A[i] == missing)
		{
			missing++;
		}
	}
	return missing;
}

int main()
{
	int A[] = {0};
	cout << firstMissingPositive(A, 1) << endl;
	int aa;
	cin >> aa;
	return 0;
}