#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;  

//�������⣬���ַ����� DFS�� DP�� next_permulation
//����һ��DFS
void swapChar(char* p1, char* p2)
{
	char tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void PermulationDFS(char* str, int idx)
{
	if (idx == strlen(str))
	{
		cout << str << endl;
		return;
	}

	for (int i = idx; i < strlen(str); ++i)
	{
		if (i > idx && str[i] == str[i - 1])
			continue;
		swapChar(str + idx, str + i);  //�������⿪���ڴ�
		PermulationDFS(str, idx + 1);
		swapChar(str + idx, str + i);
	}
}


void Permulation(char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	sort(str, str + strlen(str));
	PermulationDFS(str, 0);
}

//DP�����Ӵ�f(i - 1)��������֪����f(i)�����У�ֻ�轫str[i]��f(i - 1)�����д��Ŀ�϶��������Ȼ���˵��ƹ�ʽ���õݹ�Ҳ�ǿ���ʵ�ֵ�
//�����õݹ�ʵ��

vector<string> PermulationHelper(char* str, int len) 
{
	int total = strlen(str);
    vector<string> res;
	if (len <= 0 || len > total || str == NULL)
	{
		res.push_back("");
		return res;
	}

	vector<string> subRes = PermulationHelper(str, len - 1);

	char cur = str[len - 1];
	
	for (int i = 0; i < subRes.size(); ++i)
	{
		//���ַ����и�λ�ò��뵱ǰ�ַ�
		res.push_back(string(subRes[i] + cur));
		for (int j = 0; j < subRes[i].size(); j++)
		{
			string tmp = subRes[i];
			res.push_back(tmp.insert(j, string("") + cur));
		}
	}
	return res;
}

void PermulationRecur(char* str)
{
	if (str == NULL)
		return;

	vector<string> res = PermulationHelper(str, strlen(str));
	for (int i = 0; i < res.size(); ++i)
	{
		if (res[i].size() != 0)
			cout << res[i] << endl;
	}
}

//������⣬ʵ�ʾ�����һ�����ϵ������Ӽ��������ַ�����DFS, DP, ����ѡȡ�벻ѡȡ��λ��������
//����һ
void CombinationDFS(char* str, int idx, string& res)
{
	if (res.size() > 0)
		cout << res << endl;

	if (idx == strlen(str))
		return;

	for (int i = idx; i < strlen(str); ++i)
	{
		if (i > idx && str[i] == str[i - 1]) //��ֹ�ظ�
			continue;
		res.push_back(str[i]);
		CombinationDFS(str, i + 1, res);     //ֱ�Ӵ�i+1��ʼ�������ظ�
		res.pop_back();
	}
}

void Combination(char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	sort(str, str + strlen(str));
	string res;
	CombinationDFS(str, 0, res);
}


//������
//�Ӵ�f(i-1)�����������֪����f(i)���������ʵ���Ͼ���f(i-1)��������ϣ��ټ���f(i-1) + str[i]�����������ַ��ӵ�֮ǰ������ϣ�
//�õݹ�ʵ��Ҳ����
void CombinationDP(const char* str)
{
	if (str == NULL || strlen(str) == 0)
		return;

	vector<string> res;

	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		vector<string> tmp;

		if (i == 0 || str[i] != str[i - 1])
			tmp.push_back(string("") + str[i]);

		for (int j = 0; j < res.size(); ++j)
		{
			tmp.push_back(res[j] + str[i]);
		}

		for (int k = 0; k < tmp.size(); ++k)
			res.push_back(tmp[k]);
	}

	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return;
}

//����λ�����ķ��������õݹ飬���ÿ������顣����ĳ��Ԫ�أ���ѡȡ�Ͳ�ѡȡ����״̬������Ӽ���������2^n��
//Ҳ����˵��n��Ԫ�صļ��ϣ���Ӧ2^n���Ӽ���ÿ���Ӽ�ʵ����������Ԫ�ص�״̬���ϣ���ֵ����
//�ⲻ����nλ������������Ӧ����������Got it! ����Ԫ��С��32����һ��unsign int �Ϳ����ˡ�
//����������ظ���������ظ������������setȥ��

void CombinationBit(char* str)
{
	if (str == NULL || strlen(str) == 0)
	{
		return;
	}
	int len = strlen(str);

	unsigned int i = 1; //��Ӧ�����������
	unsigned int end_flag = 1 << len;
	for (; i < end_flag; i++)
	{
		int mask = 1;
		int n = len;
		while (n--)
		{
			if (i & mask)
			{
				cout << str[n] << " "; 
			}
			mask <<= 1;
		}
		cout << endl;
	}
}


int main()
{
	char str[] = {"abc"};
	
	cout << "original:" << endl;
	cout << str << endl;

	cout << "permulation:" << endl;
	Permulation(str);

	cout << "PermulationRecur:" << endl;
	PermulationRecur(str);

	cout << "combination:" << endl;
	Combination(str);

	cout << "combination DP:" << endl;
	CombinationDP(str);

	cout << "combination Bit: " << endl;
	CombinationBit(str);

	int aa;
	cin >> aa;
}