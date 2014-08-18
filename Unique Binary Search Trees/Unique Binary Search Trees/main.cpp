#include <iostream>

using namespace std;

//n个数可构成的BST为f(n), （每个数都可作为根节点）则有f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ...
int numTrees(int n) 
{
	int* a = new int[n + 1];

	a[0]=1;
	a[1]=1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = 0;
		for (int j = 1; j <= i; j++)
		{
			a[i] += (a[j - 1] * a[i - j]); 
		}
	}
	int res = a[n];
	delete a;
	return res;
}

int main(void)
{
	cout << numTrees(3) << endl;
	int aa;
	cin >> aa;
	return 0;
}