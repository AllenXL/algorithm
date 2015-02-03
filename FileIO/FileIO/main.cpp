#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_LEN = 1024;

int main()
{
	ifstream ifs("in1.txt");
	if (!ifs)
	{
		cout << "open file error" << endl;
		return -1;
	}
	string str;
	char s[MAX_LEN + 1] = {0};
	while (!ifs.eof())
	{
		ifs.getline(s, 1024);
		cout << setw(50) << s << endl;
	}
	ifs.close();

	ofstream ofs("out.txt");
	ofs << "out data:" << endl;
	ofs << "haha" << endl;
	ofs.close();

	int aa;
	cin >> aa;
}