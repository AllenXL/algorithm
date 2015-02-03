#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODE_NUM = 100;

//c--ajacent matrix
//n--num of nodes
//src--src node
//dist--shortest dist from src to the node i
//prev--prev node in the shortest path to node i
//其实就是二步，选距离最近的节点; 更新距离
void Dijkstra(int c[MAX_NODE_NUM][MAX_NODE_NUM], int n, int src, int* dist, int* prev)
{
	if (c == NULL || dist == NULL || prev == NULL || n <= 0)
	{
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[src][i];
		prev[i] = dist[i] != INT_MAX ? src : 0;
	}

	bool S[MAX_NODE_NUM] = {0};
	S[src] = true;

	for (int i = 2; i <= n; ++i)
	{
		//choose node
		int cur_min = INT_MAX;
		int chosen_node = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (!S[j] && dist[j] < cur_min)
			{
				cur_min = dist[j];
				chosen_node = j;
			}
		}
		S[chosen_node] = true;

		//update dist
		for (int j = 1; j <= n; ++j)
		{
			if (!S[j] && c[chosen_node][j] != INT_MAX)
			{
				int new_dist = dist[chosen_node] + c[chosen_node][j];
				if (dist[j] > new_dist)
				{
					dist[j] = new_dist;
					prev[j] = chosen_node;
				}
			}
		}

	}
}

void SearchPath(int* prev, int src, int dst)
{
	if (prev == NULL)
		return;
	stack<int> path;
	
	path.push(dst);

	int cur = prev[dst];
	while (cur != src)
	{
		path.push(cur);
		cur = prev[cur];
	}
	path.push(src);

	//print path
	while (!path.empty())
	{
		cout << path.top() << " -> ";
		path.pop();
	}
}

/*
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
*/
int main()
{
	int c[MAX_NODE_NUM][MAX_NODE_NUM];
	int prev[MAX_NODE_NUM];
	int dist[MAX_NODE_NUM];

	int nodes;
	int edges;
	
	cin >> nodes >> edges;

	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			c[i][j] = INT_MAX;
		}
	}

	int p, q, w;
	for (int i = 0; i < edges; ++i)
	{
		cin >> p >> q >> w;
		c[p][q] = w;
	}

	//print adjacent matrix
	for (int i = 1; i <= nodes; ++i)
	{
		for (int j = 1; j <= nodes; ++j)
		{
			if (c[i][j] == INT_MAX)
			{
				printf("%8s", "~");
			}
			else
				printf("%8d", c[i][j]);
		}
		cout << endl;
	}

	//compute Dijkstra algorithm
	Dijkstra(c, nodes, 1, dist, prev);

	//search a path
	cout << "shortest dist from node 1 to the last node is " << dist[nodes] << endl;
	cout << "and the detail path is: " << endl;
	SearchPath(prev, 1, nodes);

	int aa;
	cin >> aa;
}





/*
#include <iostream>
using namespace std;
 
const int maxnum = 100;
const int maxint = 999999;


// n -- n nodes
// v -- the source node
// dist[] -- the distance from the ith node to the source node
// prev[] -- the previous node of the ith node
// c[][] -- every two nodes' distance
void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum])
{
	bool s[maxnum];    // 判断是否已存入该点到S集合中
	for(int i=1; i<=n; ++i)
	{
		dist[i] = c[v][i];
		s[i] = 0;     // 初始都未用过该点
		if(dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;
 
	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
         // 注意是从第二个节点开始，第一个为源点
	for(int i=2; i<=n; ++i)
	{
		int tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for(int j=1; j<=n; ++j)
			if((!s[j]) && dist[j]<tmp)
			{
				u = j;              // u保存当前邻接点中距离最小的点的号码
				tmp = dist[j];
			}
		s[u] = 1;    // 表示u点已存入S集合中
 
		// 更新dist
		for(int j=1; j<=n; ++j)
			if((!s[j]) && c[u][j]<maxint)
			{
				int newdist = dist[u] + c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}

// 查找从源点v到终点u的路径，并输出
void searchPath(int *prev,int v, int u)
{
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while(tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	for(int i=tot; i>=1; --i)
		if(i != 1)
			cout << que[i] << " -> ";
		else
			cout << que[i] << endl;
}
*/

/*
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
*/

/*
int main()
{
	// 各数组都从下标1开始
	int dist[maxnum];     // 表示当前点到源点的最短路径长度
	int prev[maxnum];     // 记录当前点的前一个结点
	int c[maxnum][maxnum];   // 记录图的两点间路径长度
	int n, line;             // 图的结点数和路径数

	//freopen("input.txt", "r", stdin);
	// 各数组都从下标1开始
 
	// 输入结点数
	cin >> n;
	// 输入路径数
	cin >> line;
	int p, q, len;          // 输入p, q两点及其路径长度
 
	// 初始化c[][]为maxint
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			c[i][j] = maxint;
 
	for(int i=1; i<=line; ++i)  
	{
		cin >> p >> q >> len;
		if(len < c[p][q])       // 有重边
		{
			c[p][q] = len;      // p指向q
			//c[q][p] = len;      // q指向p，这样表示无向图
		}
	}
 
	for(int i=1; i<=n; ++i)
		dist[i] = maxint;

	cout << "adjacent matrix:" << endl;
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
			printf("%8d", c[i][j]);
		printf("\n");
	}
 
	Dijkstra(n, 1, dist, prev, c);
 
	// 最短路径长度
	cout << "源点到最后一个顶点的最短路径长度: " << dist[n] << endl;
 
	// 路径
	cout << "源点到最后一个顶点的路径为: ";
	searchPath(prev, 1, n);

	int aa;
	cin >> aa;
}
*/