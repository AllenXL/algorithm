#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
	int l = 0;
	int r = height.size() - 1;

	int max = 0;
	while (l < r)
	{
		int area = min(height[l], height[r]) * (r - l);
		max = max < area ? area : max;

		if (height[l] < height[r])
			l++;
		else
			r--;
	}
	return max;
}

int main()
{
	int aa;
	cin >> aa;
}