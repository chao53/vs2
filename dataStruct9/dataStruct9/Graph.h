#pragma once
#include<stack>
#include<iostream>

using namespace std;

struct Arc
{
	int weight = NULL;
	int v1 = NULL;
	int v2 = NULL;
	Arc* nextArc = NULL;
};

template<class T>class Graph;
template<class T>struct Node
{
	friend class Graph<T>;
	T body = NULL;
	Arc* firstArc = NULL;
};
template<class T>class Graph {
private:
	Node<T>* NodeTable;
	int maxNode;
	int top;
	stack<int> gap;
public:
	Graph(int maxNode);
	~Graph();
	T GetBody(int v);
	int insertNode(T newBody);
	int removeNode(int v);
	int addDoubleEdge(int v1, int v2, int weight);
	int addArc(int v1, int v2, int weight);
	int removeDoubleEdge(int v1, int v2);
	int removeArc(int v1, int v2);
	void showAll();
	Graph<T> Kruskal();
};

template<class T>
Graph<T>::Graph(int maxNode) {
	NodeTable = new Node<T>[maxNode];
	this->maxNode = maxNode;
	top = -1;
}

template<class T>
Graph<T>::~Graph() {
}

template<class T>
T Graph<T>::GetBody(int v) {
	if (v > top || v < 0 || NodeTable[v] == NULL) {
		return NULL;
	}
	else
	{
		return NodeTable[v].body;
	}
}

template<class T>
int Graph<T>::insertNode(T newBody) {
	Node<T> newNode = *new Node<T>;
	newNode.body = newBody;
	if (gap.empty()) {
		if (top < maxNode - 1) {
			top++;
			NodeTable[top] = newNode;
		}
		else
		{
			return -1;
		}
		
	}
	else {
		NodeTable[gap.top()] = newNode;
		gap.pop();
	}
	return 1;
}

template<class T>
int Graph<T>::removeNode(int v) {
	if (v <= top && v >= 0 && NodeTable[v].body != NULL) {
		//delete arc
		if (NodeTable[v].firstArc != NULL) {
			if (NodeTable[v].firstArc->nextArc != NULL) {
				Arc* p = NodeTable[v].firstArc;
				while (p != NULL) {
					Arc* q = p;
					p = p->nextArc;
					removeDoubleEdge(v, q->v2);
				}
			}
			else {
				removeDoubleEdge(v, NodeTable[v].firstArc->v2);
			}
		}
		NodeTable[v].body = NULL;
		gap.push(v);
		return 1;
	}
	return -1;
}

template<class T>
int Graph<T>::addDoubleEdge(int v1, int v2, int weight) {
	return addArc(v1, v2, weight)* addArc(v2, v1, weight);
}

template<class T>
int Graph<T>::addArc(int v1, int v2, int weight) {
	if (v1 <= top && v1 >= 0 && NodeTable[v1].body != NULL && v2 <= top && v2 >= 0 && NodeTable[v2].body != NULL) {
		Arc *newArc = new Arc;
		newArc->v1 = v1;
		newArc->v2 = v2;
		newArc->weight = weight;
		if (NodeTable[v1].firstArc == NULL) {
			NodeTable[v1].firstArc = newArc;
			return 1;
		}
		else
		{
			Arc* p = NodeTable[v1].firstArc;
			int m = 0;
			if (p->v2 == v2) {
				m = 1;
			}
			while (p->nextArc != NULL) {
				p = p->nextArc;
				if (p->v2 == v2) {
					m = 1;
					break;
				}
			}
			if (m == 0) {
				p->nextArc = newArc;
				return 1;
			}
		}
	}
	return -1;
}

template<class T>
int Graph<T>::removeDoubleEdge(int v1, int v2) {
	return removeArc(v1, v2)* removeArc(v2, v1);
}

template<class T>
int Graph<T>::removeArc(int v1, int v2) {
	if (v1 <= top && v1 >= 0 && NodeTable[v1].body != NULL && v2 <= top && v2 >= 0 && NodeTable[v2].body != NULL) {
		if (NodeTable[v1].firstArc->v2 == v2) {
			Arc* q = NodeTable[v1].firstArc;
			NodeTable[v1].firstArc = NodeTable[v1].firstArc->nextArc;
			delete q;
		}
		else {
			Arc* p = NodeTable[v1].firstArc;
			while (p->nextArc != NULL) {
				if (p->nextArc->v2 == v2) {
					Arc* q = p->nextArc;
					p->nextArc = p->nextArc->nextArc;
					delete q;
					break;
				}
				p = p->nextArc;
			}
		}
		return 1;
	}
	return -1;
}

template<class T>
void Graph<T>::showAll() {
	for (int v = 0; v <= top;v++) {
		if (NodeTable[v].body != NULL) {
			cout << NodeTable[v].body << " : ";
			if (NodeTable[v].firstArc != NULL) {
				if (NodeTable[v].firstArc->nextArc != NULL) {
					Arc* p = NodeTable[v].firstArc;
					while (p != NULL) {
						cout << NodeTable[p->v2].body<<"("<< p->weight<<")"<<" ";
						p = p->nextArc;
					}
				}
				else {
					cout << NodeTable[NodeTable[v].firstArc->v2].body << "(" << NodeTable[v].firstArc->weight << ")";
				}
			}
			cout << endl;
		}
	}
}

template<class T>
Graph<T> Graph<T>::Kruskal() { //时间复制度O(eloge + n^2)
	int* F = new int[top + 1];
	Graph<T> K(top + 1);
	Arc* headArc = new Arc;
	for (int i = 0; i < top + 1;i++) {
		F[i] = i;
		K.insertNode(NodeTable[i].body);
		if (NodeTable[i].firstArc != NULL) {
			Arc* newArc = new Arc;
			newArc->v1 = NodeTable[i].firstArc->v1;
			newArc->v2 = NodeTable[i].firstArc->v2;
			newArc->weight = NodeTable[i].firstArc->weight;

			Arc* ap = headArc;
			while (ap->nextArc != NULL)
			{
				if (ap->nextArc->weight >= newArc->weight) {
					break;
				}
				ap = ap->nextArc;
			}
			Arc* aq = ap->nextArc;
			ap->nextArc = newArc;
			newArc->nextArc = aq;
		}
	}
	
	Arc* ap = headArc;
	while (ap->nextArc != NULL)
	{
		ap = ap->nextArc;
		int j1 = ap->v1;
		int j2 = ap->v2;
		while (F[j1] != j1) {
			j1 = F[j1];
		}
		while (F[j2] != j2)
		{
			j2 = F[j2];
		}
		if (j1 != j2) {
			K.addDoubleEdge(ap->v1, ap->v2, ap->weight);
			F[ap->v2] = ap->v1;
		}
	}

	for (int i = 0;i < gap.size();i++) {
		K.gap.push(gap.top());
	}

	return K;
}