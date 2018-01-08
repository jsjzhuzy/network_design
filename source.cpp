#include "class.h"
template<class T, class E>
bool Graphmtx<T, E>::insertVertex(const T& vertex)//插入顶点
{
	if (numVertices == maxVertices)//顶点表满，无法插入
	{
		return false;
	}
	VerticesList[numVertices++] = vertex;
	return true;
};
template<class T, class E>
bool Graphmtx<T, E>::removeVertex(int v)//删除顶点和所有与它相关联的边
{
	cout<<"Li";
	if (v < 0 || v >= numVertices)
	{
		return false;                  //顶点不在图中
	}
	if (numVertices == 1)                //只剩一个顶点不删除
	{
		return false;
	}
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];//删除操作
	for (i = 0; i < numVertices; i++)
	{
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)
		{
			numEdges--;
		}
	}
	for (i = 0; i < numVertices; i++)
	{
		Edge[i][v] = Edge[i][numVertices - 1];
	}
	numVertices--;
	for (j = 0; j < numVertices; j++)
	{
		Edge[v][j] = Edge[numVertices][j];
	}
	return true;
};
template<class T, class E>
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)//插入边（v1,v2），权值为cost
{
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight)
	{
		Edge[v1][v2] = cost;
		Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
	{
		return false;
	}
};
template<class T, class E>
bool Graphmtx<T, E>::removeEdge(int v1, int v2)//删除边(v1,v2)
{
	if(v1>-1&&v1<numVertices&&v2>-1&&v2<numVertices&&Edge[v1][v2]>0&&Edge[v1][v2]<maxWeight)
	{
		Edge[v1][v2] = maxWeight;
		Edge[v2][v1] = maxWeight;
		numEdges--;
		return true;
	}
	else
	{
		return false;
	}
};
template<class T,class E>
Graphmtx<T, E>::Graphmtx()//构造函数
{
	int sz = DefaultVertices;
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];
	Edge = (E**)new E*[maxVertices];
	for (i = 0; i < maxVertices; i++)
	{
		Edge[i] = new E[maxVertices];
	}
	for (i = 0; i < maxVertices; i++)
	{
		for (j = 0; j < maxVertices; j++)
		{
			Edge[i][j] = (i == j) ? 0 : maxWeight;
		}
	}
};
template<class T, class E>
int Graphmtx<T, E>::getFirstNeighbor(int v)
{
	if (v != -1)
	{
		for (int col = 0; col < numVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxWeight)
			{
				return col;
			}
		}
	}
	return -1;
};
template<class T, class E>
int Graphmtx<T, E>::getNextNeighbor(int v, int w)//找到顶点v的下一个邻接顶点w的下一个邻接顶点
{
	if (v != -1 && w != -1)
	{
		for (int col = w + 1; col < numVertices; col++)
		{
			if (Edge[v][col] > 0 && Edge[v][col] < maxVertices)
			{
				return col;
			}
		}
	}
	return -1;
};

//template<class T, class E>
/*istream& operator>>(istream& in, Graphmtx<T, E>&G)
{
	int i, j, k, n, m;
	T e1, e2;
	E weight;
	in >> n >> m;         ·    //输入顶点数和边数
		for (i = 0; i < n; i++)   //建立顶点表数据
		{
			in >> e1;
			G.insertVertex(e1);
		}
	i = 0; ·
		while (i < m)
		{
			in >> e1 >> e2 >> weight;  //输入端点信息
			j = G.getVertexPos(e1);
			k = G.getVertexPos(e2);    //查顶点号
			if (j == -1 || k == -1)
			{
				std::cout << "边两端输入的信息有误，重新输入！" << std::endl;
			}
			else
			{
				G.insertEdge(j, k, weight);
				i++;
			}
		}
	return in;
};*/