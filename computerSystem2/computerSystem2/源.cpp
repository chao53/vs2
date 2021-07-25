//����:��쿳�
#pragma once
#include<iostream>

using namespace std;

class PageReplace
{
private:
	int orderList[100] =
	{ 0, 9, 8, 4, 4, 3, 6, 5, 1, 5,
	  0, 2, 1, 1, 1, 1, 8, 8, 5, 3,
	  9, 8, 9, 9, 6, 1, 8, 4, 6, 4,
	  3, 7, 1, 3, 2, 9, 8, 6, 2, 9,
	  2, 7, 2, 7, 8, 4, 2, 3, 0, 1,
	  9, 4, 7, 1, 5, 9, 1, 7, 3, 4,
	  3, 7, 1, 0, 3, 5, 9, 9, 4, 9,
	  6, 1, 7, 5, 9, 4, 9, 7, 3, 6,
	  7, 7, 4, 5, 3, 5, 3, 1, 5, 6,
	  1, 1, 9, 6, 6, 4, 0, 9, 4, 3 };//����ҳ��ķ���˳��
	int frameNum = 0;
	int* frame;
public:
	PageReplace();
	~PageReplace();

	void setFrameNum(int n) {
		frameNum = n;
	}
	
	int OPT() {
		int count = 0;
		frame = new int[frameNum];
		for (int i = 0;i < frameNum;i++) {
			frame[i] = -1;
		}
		for (int i1 = 0;i1 < 100;i1++) {
			int mark = 0;
			for (int i2 = 0;i2 < frameNum;i2++) {
				if (frame[i2] == orderList[i1]) {
					mark = 1;
				}
			}
			if (mark == 0) {
				count++;
				int tag = 0;
				int record = 0;
				int score = 0;
				for (int i2 = 0;i2 < frameNum - 1;i2++) {//����ҳ���е�ҳ��
					for (int i3 = i1 + 1;i3 < 100;i3++) {//��������ķ���˳��
						score++;
						if (frame[i2] == orderList[i3]) {
							break;
						}
					}
					if (score > record) {
						tag = i2;
						record = score;
					}
					score = 0;
				}
				for (int i2 = tag;i2 < frameNum - 1;i2++) {
					frame[i2] = frame[i2 + 1];
				}
				frame[frameNum - 1] = orderList[i1];
			}
		}
		return count;
	}

	int LRU() {
		int count = 0;
		frame = new int[frameNum];
		for (int i = 0;i < frameNum;i++) {
			frame[i] = -1;
		}
		for (int i1 = 0;i1 < 100;i1++) {
			int mark = 0;
			int i2 = 0;
			for (i2 = 0;i2 < frameNum;i2++) {
				if (frame[i2] == orderList[i1]) {
					mark = 1;
				}
			}
			if (mark == 1) {//���·��ʵ�ҳ�����ڶ���
				for (int i3 = i2;i3 < frameNum - 1;i3++) {
					frame[i3] = frame[i3 + 1];
				}
				frame[frameNum - 1] = orderList[i1];
			}
			else if (mark == 0) {//���¼����ҳ�����ڶ���
				count++;
				for (int i2 = 0;i2 < frameNum - 1;i2++) {
					frame[i2] = frame[i2 + 1];
				}
				frame[frameNum - 1] = orderList[i1];
			}
		}
		return count;
	}

	int FIFO() {
		int count = 0;
		frame = new int[frameNum];
		for (int i = 0;i < frameNum;i++) {
			frame[i] = -1;
		}
		for (int i1 = 0;i1 < 100;i1++) {
			int mark = 0;
			for (int i2 = 0;i2 < frameNum;i2++) {
				if (frame[i2] == orderList[i1]) {
					mark = 1;
				}
			}
			if (mark == 0) {//��ĩ�˵�ҳ����̭
				count++;
				for (int i2 = 0;i2 < frameNum - 1;i2++) {
					frame[i2] = frame[i2 + 1];
				}
				frame[frameNum - 1] = orderList[i1];
			}
		}
		return count;
	}
};
 
PageReplace::PageReplace()
{
}

PageReplace::~PageReplace()
{
}

int main() {
	PageReplace P1;

	for (int i = 1;i <= 10;i++) {
		cout << "ҳ����Ϊ"<<i<<"ʱ***************************************************************************" << endl;
		P1.setFrameNum(i);
		cout << "FIFO��ȱҳ��Ϊ" << P1.FIFO() << "\t" << "FIFO���û�����Ϊ" << P1.FIFO()-i << endl;
		cout << "LRU��ȱҳ��Ϊ" << P1.LRU() << "\t\t" << "LRU���û�����Ϊ" << P1.LRU()-i << endl;
		cout << "OPT��ȱҳ��Ϊ" << P1.OPT() << "\t\t" << "OPT���û�����Ϊ" << P1.OPT()-i << endl;
		cout << "\n" << endl;
	}
	
}