#include"class.h"
template<class T, class E>
bool Graphmtx<T, E>::insertVertex(const T& vertex)//���붥��
{
	if (numVertices == maxVertices)//����������޷�����
	{
		return false;
	}
	VerticesList[numVertices++] = vertex;
	return true;
};
template<class T, class E>
bool Graphmtx<T, E>::removeVertex(int v)//ɾ���������������������ı�
{
	if (v < 0 || v >= numVertices)
	{
		return false;                  //���㲻��ͼ��
	}
	if (numVertices == 1)                //ֻʣһ�����㲻ɾ��
	{
		return false;
	}
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];//ɾ������
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
bool Graphmtx<T, E>::insertEdge(int v1, int v2, E cost)//����ߣ�v1,v2����ȨֵΪcost
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
bool Graphmtx<T, E>::removeEdge(int v1, int v2)//ɾ����(v1,v2)
{
	if (v1 > -1 && v1<numVertixes&&v2>-1 && v2 < numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight)
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