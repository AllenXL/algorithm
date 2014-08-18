#include <string>
#include <iostream>

using namespace std;

//˫ָ�룬��̬ά��һ�����䡣βָ�벻������ɨ����ɨ����һ�����ڰ���������T���ַ���
//������ͷָ�룬ֱ������������Ϊֹ������¼���п��ܵ�����д�����С��
//��ʱֹͣ����ָ�룿��hasFind[S[start]] == needFind[S[start]]ʱ����Ϊ��ʱstart��end���ַ�S[start]�ĸ����պ�����Ҫ��
//����������

string minWindow(string S, string T)
{
	int needFind[256] = {0}; //��¼ԭʼT�ַ�����patter�����ַ�ֱ��ͼ
	int hasFind[256] = {0}; //ʼ�ձ��浱ǰstart��end��T���ַ��ĸ���

	for (int i = 0; i < T.size(); ++i)
	{
		needFind[T[i]]++;
	}


	int begin = 0;
	int end = 0;
	int count = 0; //��¼begin~end�����ҵ�T���ַ��ĸ����� ���aaa����T��ֻ������aa,��count=2

	int minLen = INT_MAX;
	int minBegin = 0;

	for (; end < S.size(); end++)
	{
		if (needFind[S[end]] == 0)
			continue;

		hasFind[S[end]]++;
		
		if (hasFind[S[end]] <= needFind[S[end]])
			count++;

		if (count == T.size())
		{
			while (true)
			{
				if (needFind[S[begin]] == 0)
				{
					begin++;
					continue;
				}
				else
				{
					if (hasFind[S[begin]] > needFind[S[begin]])
					{
						hasFind[S[begin]]--;
						begin++;
						continue;
					}
					else
					{
						break;
					}
				}
			}
			int cur_len = end - begin + 1;
			if (minLen >= cur_len)
			{
				minLen = cur_len;
				minBegin = begin;
			}
		}
	}

	if (minLen == INT_MAX)
		return "";
	else
		return S.substr(minBegin, minLen);

}


int main(void)
{
	//cout << numeric_limits<int>::max() << endl;
	//cout << INT_MAX << endl;

	string S("ADOBECODEBANC");
	string T("ABC");

	cout << minWindow(S, T) << endl;

	int aa;
	cin >> aa;
}