#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODE_NUM = 100;

void Floyd(int c[MAX_NODE_NUM][MAX_NODE_NUM], int n, int dist[MAX_NODE_NUM][MAX_NODE_NUM], int path[MAX_NODE_NUM][MAX_NODE_NUM])
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = c[i][j];
			path[i][j] = i;
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


void SearchPath(int dist[MAX_NODE_NUM][MAX_NODE_NUM], int path[MAX_NODE_NUM][MAX_NODE_NUM], int n)
{
	stack<int> p;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;

			if (dist[i][j] == INT_MAX)
			{
				cout << i + 1 << " -> " << j + 1 << " Path: NA" << endl;
			}
			else
			{
				cout << i + 1 << "->" << j + 1 << " Dist: " << dist[i][j] << " Path: ";

				int k = j;
				while (k != i)
				{
					p.push(k);
					k = path[i][k];
				}

				//print path
				cout << i + 1;
				while (!p.empty())
				{
					cout << "->" << p.top() + 1;
					p.pop();
				}
				cout << endl;
			}
		}
	}
}

/*
5
7
0 1 10
0 3 30
0 4 100
1 2 50
2 4 10
3 2 20
3 4 60
*/

int main()
{
	int c[MAX_NODE_NUM][MAX_NODE_NUM];
	int dist[MAX_NODE_NUM][MAX_NODE_NUM];
	int path[MAX_NODE_NUM][MAX_NODE_NUM];

	int nodes;
	int edges;
	
	cin >> nodes >> edges;

	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
		{
			c[i][j] = i != j ? INT_MAX : 0;
		}
	}

	int p, q, w;
	for (int i = 0; i < edges; ++i)
	{
		cin >> p >> q >> w;
		c[p][q] = w;
	}

	//print adjacent matrix
	for (int i = 0; i < nodes; ++i)
	{
		for (int j = 0; j < nodes; ++j)
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

	Floyd(c, nodes, dist, path);

	//print shortest distances
	for (int i = 0; i < nodes; ++i)
		for (int j = 0; j < nodes; ++j)
		{
			cout << i + 1 << "->" << j + 1 << " : " << dist[i][j] << endl;
		}

	//print all paths
	SearchPath(dist, path, nodes);

	int aa;
	cin >> aa;
}