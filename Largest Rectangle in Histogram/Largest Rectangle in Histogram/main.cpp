#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
void show(vector<T>& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		for (int j = 0; j < a[i].size(); ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


//直接遍历，超时，也存在错误
//正确的思路是从左到右，对于每个点，记算出他所能向左和向右延伸的最大边界，
//该长度乘以该点高度就是该点所能呈现的最大值，最后扫描一遍找出最大的
/*int largestRectangleArea(vector<int> &height)
{
	int max = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		int j = i;
		while (j < height.size() && height[j] >= height[i])
			j++;
		int area = height[i] * (j - i);
		if (max < area)
			max = area;
	}
	return max;
}*/

//找到每个柱子左边和右边第一个比他小的柱子，然后计算以这个柱子为高度的最大的矩形。
int largestRectangleArea1(vector<int> &height)
{
	if (height.size() == 0)
		return 0;
	int len = height.size();
	vector<int> left(len, 0);
	vector<int> right(len, 0);

	left[0] = -1;
	for (int i = 1; i < len; i++)
	{
		int k = i - 1;
		while (k != -1 && height[k] >= height[i])
			k = left[k];
		left[i] = k;
	}

	right[len - 1] = len;
	for (int i = len - 2; i >= 0; i--)
	{
		int k = i + 1;
		while (k < len && height[k] >= height[i])
		{
			k = right[k];
		}
		right[i] = k;
	}
	
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		int area = height[i] * (right[i] - left[i] - 1);
		max = max < area ? area : max;
	}

	return max;

}


//利用一个单调栈
int largestRectangleArea(vector<int> &height)
{
	int area = 0;
	int n = height.size();
	stack<int> s;

	for (int i = 0; i < height.size(); i++)
	{
		if (s.empty() || height[s.top()] <= height[i])
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && height[s.top()] > height[i])
			{
				int start = s.top();
				s.pop();
				int width = s.empty() ? i : (i - s.top() - 1);
				int temp_area = height[start] * width;
				area = temp_area > area ? temp_area : area;
			}
			s.push(i);
		}
	}
	
	while (!s.empty())
	{
		int start = s.top();
		s.pop();

		int width = s.empty() ? height.size() : height.size() - s.top() - 1;
		int temp_area = height[start] * width;
		area = temp_area > area ? temp_area : area;
	}

	return area;
}

//借助上题求Maximal Rectangle， 每一行都是一次柱状图的最大矩形面积
int maximalRectangle(vector<vector<char> > &matrix) 
{
	if (matrix.size() == 0)
		return 0;

	vector<vector<int> > m(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (i == 0)
			{
				if (matrix[i][j] == '1')
					m[i][j] = 1;
			}
			else
			{
				if (matrix[i][j] == '1')
					m[i][j] = m[i - 1][j] + 1;
			}
		}

	show(m);
	int max = 0;
	for (int i = 0; i < m.size(); ++i)
	{		
		int cur = largestRectangleArea(m[i]);
		if (cur > max)
			max = cur;
	}
	return max;

}
int main(void)
{
	int hist[8] = {3, 6, 5, 7, 4, 8, 1, 0};

	vector<int> hists(hist, hist + 8);
	cout << largestRectangleArea(hists) << endl;

	vector<vector<char> > m(2, vector<char>(2, '0'));

	char temp[5][5] = {
	{'0', '0', '0', '1', '0'},
	{'0', '1', '1', '1', '0'},
	{'0', '1', '1', '1', '0'},
	{'0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0'}
	};

	char temp1[2][2] = {{'0', '1'}, {'1', '0'}};

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			m[i][j] = temp1[i][j];
		}
	
	cout << maximalRectangle(m) << endl;

	int aa;
	cin >> aa;
	return 0;
}