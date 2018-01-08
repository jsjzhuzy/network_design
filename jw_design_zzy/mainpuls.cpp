#include "class.h"
#include "source2.cpp"
#include "source.cpp"
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
	DFS<char, int>(one, 'c');
	cout << one << endl;
	int *a, *b;
	a = (int *)new int[one.NumberOfVertices()];
	b = (int *)new int[one.NumberOfVertices()];
	ShortestPath<char, int>(one, 0, a, b);
	printShortestPath<char, int>(one, 0, a, b);
	getchar();
	while (1)
	{
		int i;
		char z;
		int ii;
		int iii;
		int quan;
		cout << "               网络路由已经生成" << endl;
		cout << "               1.删除路由" << endl;
		cout << "               2.添加路由" << endl;
		cout << "               3.删除边" << endl;
		cout << "               4.添加边" << endl;
		cout << "               5.退出" << endl;
		cout << "请输入你的选择：";
		cin >> i;
		if (i < 1 || i>4)
		{
			cout << "没有这个选项" << endl;
			i = 5;
		}
		switch (i)
		{
		case 1:
			cout << "请输入要删除的路由:"; cin >> z;
			one.removeVertex(z);
			break;
		case 2:
			cout << "请输入要添加的路由："; cin >> z;
			one.insertVertex(z);
			break;
		case 3:
			cout << "请输入要删除的边的两个路由器：" << endl;
			cout << "请输入第一个路由："; cin >> ii;
			cout << endl << "请输入第二个路由："; cin >> iii;
			one.removeEdge(ii, iii);
			break;
		case 4:
			cout << "请输入要删除的边的两个路由器：" << endl;
			cout << "请输入第一个路由："; cin >> ii;
			cout << endl << "请输入第二个路由："; cin >> iii;
			cout << endl << "请输入权值："; cin >> quan;
			one.insertEdge(ii, iii, quan);
			break;
		case 5:
			break;
		}
	}
	cout << one << endl;
	getchar();
	return 0;
}