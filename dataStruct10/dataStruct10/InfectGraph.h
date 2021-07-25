#pragma once
#include<iostream>

using namespace std;

class InfectGraph {
private:
	int NodesNum = 0;
	int SourceNum = 0;
	int** Original;
	int** Temp;
	int* NodeTable;//1:infected   0:not infected
	int* sourceTable;
public:
	InfectGraph(int NodesNum);//���캯��,�趨�ڵ���
	void change(int x, int y, int w); //�޸��ڽӾ����ֵ
	void show();//չʾ�ڽӾ���(������)
	void infect(int v);//ģ���Ⱦ
	void block(int v);//�����ڵ�
	void reset();//�����ٽ�����
	void setSourseNum(int n);//���ø�ȾԴ��
	void setSourse(int v);//���ø�ȾԴ
	int solustion();//�������ŷ���
};

InfectGraph::InfectGraph(int NodesNum) {
	this->NodesNum = NodesNum;
	NodeTable = new int[NodesNum];
	Original = new int* [NodesNum];
	Temp = new int* [NodesNum];
	for (int i = 0;i < NodesNum;i++) {
		NodeTable[i] = 0;
		Original[i] = new int[NodesNum];
		Temp[i] = new int[NodesNum];
	}
}

void InfectGraph::change(int y, int x, int w) {
	this->Original[y][x] = w;
	this->Temp[y][x] = w;
}

void InfectGraph::show() {
	for (int i1 = 0;i1 < NodesNum;i1++) {
		for (int i2 = 0;i2 < NodesNum;i2++) {
			cout << this->Original[i1][i2] << " ";
		}
		cout << endl;
	}
}

void InfectGraph::infect(int v) {
	NodeTable[v] = 1;
	for (int i = 0;i < NodesNum;i++) {
		if (Temp[v][i] == 1) {
			if (NodeTable[i] == 0) {
				infect(i);
			}
		}
	}
}

void InfectGraph::block(int v) {
	for (int i = 0;i < NodesNum;i++) {
		Temp[v][i] = 0;
		Temp[i][v] = 0;
	}
}

void InfectGraph::reset() {
	for (int i1 = 0;i1 < NodesNum;i1++) {
		for (int i2 = 0;i2 < NodesNum;i2++) {
			Temp[i1][i2] = Original[i1][i2];
		}
	}
}

void InfectGraph::setSourseNum(int n) {
	sourceTable = new int[n];
	SourceNum = n;
	for (int i = 0;i < n;i++) {
		sourceTable[i] = -1;
	}
}

void InfectGraph::setSourse(int v) {
	for (int i = 0;;i++) {
		if (sourceTable[i] == -1) {
			sourceTable[i] = v;
			break;
		}
	}
}

int InfectGraph::solustion() {
	for (int i = 0;i < SourceNum;i++) {
		infect(sourceTable[i]);
	}
	int originalInfect = 0;
	for (int i = 0; i < NodesNum;i++) {
		if (NodeTable[i] == 1) {
			NodeTable[i] = 0;
			originalInfect++;
		}
	}
	
	int leastInfect = originalInfect;
	int bestBlock = -1;
	for (int i1 = 0;i1 < SourceNum;i1++) {
		int currentInfect = 0;
		block(sourceTable[i1]);
		for (int i2 = 0;i2 < SourceNum;i2++) {
			infect(sourceTable[i2]);
		}
		for (int i2 = 0; i2 < NodesNum;i2++) {
			if (NodeTable[i2] == 1) {
				NodeTable[i2] = 0;
				currentInfect++;
			}
		}
		if (currentInfect < leastInfect) {
			leastInfect = currentInfect;
			bestBlock = i1;
		}
		reset();
	}
	return bestBlock;
}
