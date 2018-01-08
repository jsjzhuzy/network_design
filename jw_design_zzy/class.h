#pragma once
#include<iostream>
#include<list>
#include<fstream>
//#include "source.cpp"
//#include "source2.cpp"
using namespace std;
const int DefaultVertices = 30;
template<class T, class E>
class Graphmtx //:public Graph<T, E>//�ڽӾ���
{
public:
	const E maxWeight = 999;
	int NumberOfEdges()const { return numEdges; }
	friend istream& operator >>(istream& in, Graphmtx<T, E>& G);//����
	friend ostream& operator <<(ostream& out, Graphmtx<T, E>& G)//���
	{
		int i, j, n, m; T e1, e2; E w;
		n = G.NumberOfVertices();
		m = G.NumberOfEdges();
		//out << " " << endl;
		out << "\n" << "������Ŀ��" << n << "," << "�ߵ���Ŀ��" << m << endl;
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
//template<class T, class E>
/*Graphmtx<T, E>::Graphmtx()//���캯��
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
int Graphmtx<T, E>::getNextNeighbor(int v, int w)//�ҵ�����v����һ���ڽӶ���w����һ���ڽӶ���
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

template<class T, class E>
istream& operator>>(istream& in, Graphmtx<T, E>&G)
{
	int i, j, k, n, m;
	T e1, e2;
	E weight;
	in >> n >> m;         ��    //���붥�����ͱ���
	for (i = 0; i < n; i++)   //�������������
	{
		in >> e1;
		G.insertVertex(e1);
	}
	i = 0;��	
	while (i < m)
	{
		in >> e1 >> e2 >> weight;  //����˵���Ϣ
		j = G.getVertexPos(e1);
		k = G.getVertexPos(e2);    //�鶥���
		if (j == -1 || k == -1)
		{
			std::cout << "�������������Ϣ�����������룡" << std::endl;
		}
		else
		{
			G.insertEdge(j, k, weight);
			i++;
		}
	}
	return in;
};*/
