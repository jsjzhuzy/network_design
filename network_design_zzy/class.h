#pragma once
#include<iostream>
const int DefaultVertices = 30;
template<class T, class E>
class Graph//图的模板基类
{
public:
	const E maxWeight = *;
	Graph(int sz = DefaultVertices);
	~Graph();
	bool GraphEmpty()const {
		if (numEdges == 0)return true; else return false;
	}
	bool GraphFull()const {
		if (numVertices == maxVertices || numEdges == maxVertices*(maxVerticces - 1) / 2)return true; else return false;
	}
	int NumberOfVertices()const { return numVertices; }
	int NUmberOfEdges()const { return numEdges; }
	virtual E getWeight(int v1, int v2);
	virtual int getFirstNeighbor(int v);
	virtual int getNextNeighbor(int v);
	virtual bool insertVertex(const T& vertex);
	virtual bool insertEdge(int v1, int v2, E cost);
	virtual bool removeVertex(int v);
	virtual bool removeEdge(int v1, int v2);
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(T vertex);
};
template<class T, class E>
class Graphmtx :public Graph<T, E>//邻接矩阵
{
	friend istream& operator>> (istream& in，Graphmtx<T, E>& G);//输入
	friend ostream& operator<< (ostream& out, Graphmtx<T, E>& E);//输出
public:
	Graphmtx(int sz = DefaultVertices);
	~Graphmtx() {
		delete[]VerticesList; deldte[]Edge;
	}
	T getValue(int i) {
		return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	}
	E getWeight(int v1, v2) {
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);
	int getNextNeighbor(int v, int w);
	bool insertVertex(const T& vertex);
	bool insertEdge(int v1, int v2, E cost);
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
private:
	T *VerticesList;
	E **Edge;
	int getVertexPos(T vertex)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (int i = 0; i < numVertices; i++)
			{
				return i;
			}
		}
		return -1;
	}
};