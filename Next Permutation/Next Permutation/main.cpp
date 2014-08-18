#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &num)
{
	int n = num.size();
	if (n == 0)
		return;

	int idx = n - 2;
	while (idx >= 0 && num[idx] >= num[idx + 1])
		idx--;
	
	if (idx >= 0)
	{
		int i = n - 1;
		while (num[i] <= num[idx])
			i--;

		int tmp = num[i];
		num[i] = num[idx];
		num[idx] = tmp;

		reverse(num.begin() + idx + 1, num.end());
	}
	else
	{
		reverse(num.begin(), num.end());
	}
}

int main(void)
{
	vector<int> in;
	in.push_back(1);
	in.push_back(5);
	in.push_back(1);
	nextPermutation(in);

	for (int i = 0; i < in.size(); ++i)
		cout << in[i] << endl;

	int a;
	cin >> a;
}