/*描述：已知2条地铁线路，其中A为环线，B为东西向线路，线路都是双向的。经过的站点名分别如下，两条线交叉的换乘点用T1、T2表示。
编写程序，任意输入两个站点名称，输出乘坐地铁最少需要经过的车站数量（含输入的起点和终点，换乘站点只计算一次）。 

地铁线A（环线）经过车站：A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18 

地铁线B（直线）经过车站：B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 T2 B11 B12 B13 B14 B15 

输入：输入两个不同的站名 

输出：输出最少经过的站数,含输入的起点和终点，换乘站点只计算一次 

输入样例：A1 A3 

输出样例：3*/

#include <iostream>
#include <map>
#include <string>
#include <stack>

using namespace std;

map<string, int> stationIdxMap;
int graph[35][35];
int dist[35][35];
int path[35][35];

char* station[35] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14", "A15", "A16", "A17", "A18", 
		"B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14", "B15", "T1", "T2"};

int a[21] = {0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0}; // A线

int b[17] = {18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};  // B线

void InitData()
{
	/*string str;
	char num[10] = {0};

	//A开头的18个站按0~17编号
	for (int i = 1; i <= 18; ++i)
	{
		str.clear();
		str.push_back('A');
		itoa(i, num, 10);
		str = str + string(num);
		stationIdxMap[str] = i - 1;
	}

	//B开头的15个站按18~32编号
	for (int i = 18; i <= 32; ++i)
	{
		str.clear();
		str.push_back('B');
		itoa(i - 17, num, 10);
		str = str + string(num);
		stationIdxMap[str] = i;
	}

	//T1和T2编号为33、34
	stationIdxMap[string("T1")] = 33;
	stationIdxMap[string("T2")] = 34;*/

	//这样初始化比上面注释掉的程序简洁
	for (int i = 0; i < 35; ++i)
	{
		stationIdxMap[string(station[i])] = i;
	}

	//建图
	
	//初始化
	for (int i = 0; i < 35; ++i)
	{
		for (int j = 0; j < 35; ++j)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INT_MAX;
		}
	}

	//输入A环线个点相连情况 每个边权重都为1           
         
    for(int i=0;i<20;i++)    
    {    
        graph[a[i]][a[i+1]] = 1;   
        graph[a[i+1]][a[i]] = 1;        
    }    
      
    //输入B线个点相连情况 每个边权重都为1   
       
    for(int i=0;i<16;i++)    
    {     
        graph[b[i]][b[i+1]] = 1;   
        graph[b[i+1]][b[i]] = 1;         
	}
}

void Floyd(int graph[35][35], int dist[35][35], int path[35][35])
{
	int n = 35;
	for (int i = 0; i < 35; ++i)
	{
		for (int j = 0; j < 35; ++j)
		{
			dist[i][j] = graph[i][j];
			path[i][j] = i;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
}

void printPath(string s, string e)
{
	int i = stationIdxMap[s];
	int j = stationIdxMap[e];
	stack<int> p;

	while (j != i)
	{
		p.push(j);
		j = path[i][j];
	}
	p.push(i);

	cout << station[p.top()];
	p.pop();
	while (!p.empty())
	{
		cout << "->" << station[p.top()];
		p.pop();
	}
	cout << endl;
}

int main()
{
	InitData();
	Floyd(graph, dist, path);

	string s;
	string e;
	cin >> s >> e;

	if (stationIdxMap.find(s) == stationIdxMap.end() || stationIdxMap.find(e) == stationIdxMap.end())
	{
		cout << "not exist" << endl;
		return;
	}
	cout << dist[stationIdxMap[s]][stationIdxMap[e]] + 1 << endl;

	printPath(s, e);

	int aa;
	cin >> aa;
}