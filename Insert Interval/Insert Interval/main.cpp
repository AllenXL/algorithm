#include <iostream>
#include <vector>

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


//����Ĺ鲢,��������  merge sorted intervals
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> res;

	int size = intervals.size();

	int i = 0;
	for (; i < size; ++i)
	{
		if (intervals[i].start > newInterval.start)
			break;
	}
	intervals.insert(intervals.begin() + i, newInterval);

	//begin to merge intervals
	int start = intervals[0].start;
	int end = intervals[0].end;     //start-end Ϊ��ǰ�鲢�������

	for (int i = 1; i < intervals.size(); ++i)
	{
		Interval& temp = intervals[i];
		if (temp.start <= end)
		{
			end = end > temp.end ? end : temp.end;
		}
		else  //����޷��ٹ鲢�ˣ��ʹ洢��ǰ���������ʼ��һ�ֹ鲢
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
	in.push_back(Interval(1, 5));
	vector<Interval> res = insert(in, Interval(2, 7));
	show(res);
	int aa;
	cin >> aa;
	return 0;
}