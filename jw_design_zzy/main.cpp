#include "class.h"
template<class T,class E>
void ShortestPath(Graphmtx<T, E>& G, T v,E dist[], int path[])
{
	//E dist[], int path[]
	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	int i, j, k;
	E w, min;
	for (i = 0; i < n; i++)
	{
		//int vs = G.getVertexPos(v);
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v&&dist[i] < G.maxWeight)
		{
			path[i] = v;
		}
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i < n - 1; i++)
	{
		min = G.maxWeight;
		int u = v;
		for (j = 0; j < n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
			S[u] = true;
			for (k = 0; k < n; k++)
			{
				w = G.getWeight(u, k);
				if (S[k] == false && w < G.maxWeight&&dist[u] + w < dist[k])
				{
					dist[k] = dist[u] + w;
					path[k] = u;
				}
			}
		}
	}
};
template<class T,class E>
void printShortestPath(Graphmtx<T, E>& G, int v, E dist[], int path[])
{
	cout << "从路由器" << G.getValue(v) << "到其他各路由器最短路径为：" << endl;
	int i, j, k, n = G.NumberOfVertices();
	int *d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			cout << "路由器" << G.getValue(i) << "的最短路径为：" << G.getValue(v);
			while (k > 0)
			{
				cout << G.getValue(d[--k]) << " ";
				cout << "最短路径长度为：" << dist[i] << endl;
			}
		}
	}
	delete []d;
};
template<class T, class E>
void DFS(Graphmtx<T, E>& G, const T& v)
{
	int i, loc, n = G.NumberOfVertices();
	bool *visited = new bool[n];
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	loc = G.getVertexPos(v);
	DFS(G, loc, visited);
	delete[]visited;
};
template<class T, class E>
void DFS(Graphmtx<T, E>& G, int v, bool visited[])
{
	cout << G.getValue(v) << " ";
	visited[v] = true;
	int w = G.getFirstNeighbor(v);
	while (w != -1)
	{
		if (visited[w] == false)
		{
			DFS(G, w, visited);
		}
		w = G.getNextNeighbor(v, w);
	}
};
template<class T,class E>
void Floyd(Graphmtx<T, E>& G)
{
	E a[4][4];
	int path[4][4];
	int i, j, k, n = G.NumberOfVertices();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = G.getWeight(i, j);
			if (i != j&&a[i][j] < G.maxWeight)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = 0;
			}
		}
	}
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (a[i][k] + a[k][j] < a[i][j])
				{
					a[i][j] = a[i][k] = a[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	int kk = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << "\n";
	}
	//cout << a[i][j] << path[i][j] << endl;
};
int main()
{
	char name;
	int qq, ww, ee;
	Graphmtx<char, int> one;
	ifstream fin("D:\\qwer.txt");
	for (int qqq = 0; qqq < 9; qqq++)
	{
		fin >> name;
		one.insertVertex(name);
	}
	ifstream fin1("D:\\rewq.txt");
	for (int ppp = 0; ppp < 15; ppp++)
	{
		fin1 >> qq;
		fin1 >> ww;
		fin1 >> ee;
		one.insertEdge(qq, ww, ee);
	}
	//cout << "bbbb" << endl;
	//cout << "aaa" << endl;
	//one.insertVertex('a');
	//one.insertVertex('b');
	//one.insertVertex('c');
	//one.insertEdge(0, 1, 4);
	//one.insertEdge(1, 2, 6);
	//one.insertVertex('d');
	//one.insertVertex('e'); 
	//one.insertEdge(3, 4, 13);
	//one.insertEdge(1, 4, 4);
	//one.insertEdge(1, 3, 8);
	DFS<char, int>(one, 'c');
	cout << one << endl;
	int *a, *b;
	a = (int *)new int[one.NumberOfVertices()];
	b = (int *)new int[one.NumberOfVertices()];
	//Floyd<char, int>(one);
	//int dist[6];
	//int path[6];
	ShortestPath<char, int>(one, 0, a, b);
	printShortestPath<char, int>(one, 0, a, b);
	getchar();
	return 0;
}