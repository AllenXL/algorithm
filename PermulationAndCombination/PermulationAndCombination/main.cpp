#include <iostream>
#include <string>

using namespace std;

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

	PermulationDFS(str, 0);
}


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

	string res;
	CombinationDFS(str, 0, res);
}



int main()
{
	char str[] = {"aa"};
	
	cout << "original:" << endl;
	cout << str << endl;

	cout << "permulation:" << endl;
	Permulation(str);

	cout << "combination:" << endl;
	Combination(str);

	int aa;
	cin >> aa;
}