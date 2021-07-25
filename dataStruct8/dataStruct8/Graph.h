#pragma once
using namespace std;

template<class NameType,class DistType>class Graph;
template<class NameType,class DistType>struct Edge {
	friend class Graph<NameType, DistType>;
	int dest;
	DistType cost;
	Edge<DistType>* link;
	Edge() {}
	Edge(int D, DistType C):
		dest(D), cost(C, link(NULL)) {}
	int operator != (Edge<DistType>& E)
		const {
		return dest != E.dest;
	}
};

template<class NameType,class DistType>
struct Vertex {
	friend class Graph<NameType, DistType>;
	NameType data;
	Edge<DistType>* adj;
};

template<class NameType,class DistType>
class Graph {
private:
	Vertex<NameType, DistType>* NodeTable;
	int NumVertices;
	int MaxVertices;
	int NumEdges;
	int GetVertexPos(NameType& vertex);
public:
	Graph(int sz);
	~Graph();
	int GraphEmpty()const {return NumVertices == 0;}
	int GraphFull()const{return NumVertices == MaxVertices;}
	NameType GetValue(int i) {return i >= 0 && i < NumVertices ? NodeTable[i].data : Null;}
	int NumberOfVertives() {return NumVertices;}
	int NumberOfEdges() {return NumEdges; }
	void InsertVertex(NameType& vertex);
	void RemoveVertex(int v);
	void InsertEdge(int v1, int v2, DistType weight);
	void RemoveEdge(int v1, int v2);
	DistType GetWeight(int v1, int v2);
	int GetFirstNeighbor(int v);
	int GetNextNeighbor(int v1, int v2);
};

template<class NameType, class DistType>
int Graph<NameType, DistType>::GetVertexPos(NameType& vertex) {
	for (int i = 0;i < NumVertices;i++) {
		if (NodeTable[i].data == vertex) {
			return i;
		}
	}
	return -1;
}

template<class NameType, class DistType>
int Graph<NameType, DistType>::GetFirstNeighbor(int v) {
	if (v!= -1) {
		Edge<DistType>* p = NodeTable[v].adj;
		if (p != NULL) {
			return p->dest;
		}
	}
	return -1;
}

template<class NameType, class DistType>
int Graph<NameType, DistType>::GetNextNeighbor(int v1, int v2) {
	if (v1 != -1) {
		Edge<DistType>* p = NodeTable[v1].adj;
		while (p != NULL) {
			if (p->dest == v2 && p->link != NULL) {
				return p->link->dest;
			}
			else
			{
				p = p->link;
			}
		}
	}
	return -1;
}