#include <string>
#include <iostream>

using namespace std;

//http://blog.sina.com.cn/s/blog_60b5450101016kj7.html

//row = 0 or rows - 1, step = 2 * rows - 2
//else if even colomn, step = 2 * (rows - i - 1)
//else if odd colomn, step = 2 * i

/*string convert(string s, int nRows)
{
	if (nRows <= 1 || s.size() == 0)
		return s;

	int len = s.size();
	string res;
	for (int i = 0; i < nRows; ++i)
	{
		int j = i;
		while (j < len)
		{
			res.push_back(s[j]);
			
			if (i == 0 || i == nRows - 1)
				j += 2 * nRows - 2;
			else if (j & 1)  //与运算竟然超时
				j += 2 * i;
			else
				j += 2 * (nRows - i - 1);
		}
	}
	return res;
}*/

string convert(string s, int nRows)
{
	if (nRows <= 1 || s.size() == 0)
		return s;

	int len = s.size();
	string res;
	bool flag = true;
	for (int i = 0; i < nRows; ++i)
	{
		int j = i;
		flag = true;
		while (j < len)
		{
			res.push_back(s[j]);
			
			if (i == 0 || i == nRows - 1)
				j += 2 * nRows - 2;
			else
			{
			    if (flag)
			    {
			        j += 2 * (nRows - i - 1);
			        flag = false;
			    }
			    else
			    {
			        j += 2 * i;
			        flag = true;
			    }
			}
				
		}
	}
	return res;
}

int main()
{
	cout << convert("PAYPALISHIRING", 1);
	int aa;
	cin >> aa;
}