#include "class.h"
template<class T, class E>
void ShortestPath(Graphmtx<T, E>& G, T v, E dist[], int path[])
{
	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	int i, j, k;
	E w, min;
	for (i = 0; i < n; i++)
	{
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
template<class T, class E>
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
	delete[]d;
};