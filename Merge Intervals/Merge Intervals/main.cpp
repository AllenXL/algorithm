#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void show(vector<Interval>& in)
{
	for (int i = 0; i < in.size(); ++i)
	{
		cout << in[i].start << " " << in[i].end << endl;
	}
}


//merge sorted intervals
bool comp(const Interval &lhs, const Interval &rhs)
{     
	return lhs.start < rhs.start;
}
vector<Interval> merge(vector<Interval> &intervals)
{
	vector<Interval> res;
	if (intervals.size() == 0)
		return res;

	sort(intervals.begin(), intervals.end(), comp);

	//begin to merge intervals
	int start = intervals[0].start;
	int end = intervals[0].end;     //start-end 为当前归并后的区间

	for (int i = 1; i < intervals.size(); ++i)
	{
		Interval& temp = intervals[i];
		if (temp.start <= end)
		{
			end = end > temp.end ? end : temp.end;
		}
		else  //如果无法再归并了，就存储当前结果，并开始下一轮归并
		{
			res.push_back(Interval(start, end));
			start = temp.start;
			end = temp.end;
		}
	}

	res.push_back(Interval(start, end));
	return res;
}


int main()
{
	vector<Interval> in;
	in.push_back(Interval(1, 3));
	in.push_back(Interval(8, 10));
	in.push_back(Interval(2, 6));

	show(merge(in));
	int aa;
	cin >> aa;
	return 0;
}