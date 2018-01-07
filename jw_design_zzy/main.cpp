#include "class.h"
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
int main()
{
	cout << "bbbb" << endl;
	Graphmtx<char, int> one;
	cout << "aaa" << endl;
	one.insertVertex('a');
	one.insertVertex('b');
	one.insertVertex('c');
	one.insertEdge(0, 1, 4);
	one.insertEdge(1, 2, 6);
	one.insertVertex('d');
	one.insertEdge(1, 3, 8);
	DFS<char, int>(one, 'c');
	cout << one << endl;
	getchar();
	return 0;
}