#pragma once
#include<iostream>
#include<list>
#include<fstream>
using namespace std;
const int DefaultVertices = 30;
template<class T, class E>
class Graphmtx //:public Graph<T, E>//邻接矩阵
{
public:
	const E maxWeight = 999;
	int NumberOfEdges()const { return numEdges; }
	friend istream& operator >>(istream& in, Graphmtx<T, E>& G);//输入
	friend ostream& operator <<(ostream& out, Graphmtx<T, E>& G)//输出
	{
		int i, j, n, m; T e1, e2; E w;
		n = G.NumberOfVertices();
		m = G.NumberOfEdges();
		//out << " " << endl;
		out << "\n" << "顶点数目：" << n << "," << "边的数目：" << m << endl;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				w = G.getWeight(i, j);
				if (w > 0 && w < G.maxWeight)
				{
					e1 = G.getValue(i);
					e2 = G.getValue(j);
					out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
				}
			}
		}
		return out;
	}
	int NumberOfVertices()const { return numVertices; }
	Graphmtx();
	~Graphmtx() {
		delete[]VerticesList; delete[]Edge;
	}
	T getValue(int i) {
		return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	}
	E getWeight(int v1, int v2) {
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2, E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
	int getVertexPos(T vertex)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (VerticesList[i] == vertex)
			{
				return i;
			}
		}
		return -1;
	}
private:
	T* VerticesList;
	E** Edge;
	int maxVertices;
	int numEdges;
	int numVertices;
};

