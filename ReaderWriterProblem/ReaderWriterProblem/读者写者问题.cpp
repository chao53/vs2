
#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int totalTime;
	cout << "����������ʱ��(����200��1000)" << endl;
	cin >> totalTime;


	//������10������3��д��
	int duzheTimer[10] = { 0,0,0,0,0,0,0,0,0,0 }; //���ߵ�ʱ���Ϊ50������һ�
	int duzhe[10] = { 0,0,0,0,0,0,0,0,0,0 }; // 0Ϊ���� 1Ϊ�ȴ� 2Ϊ�ڶ�ȡ
	int xiezheTimer[3] = { 0,0,0 }; //д�ߵĻ����ֵΪ150������һ�
	int xiezhe[3] = { 0,0,0 };// 0Ϊ���� 1Ϊ�ȴ� 2Ϊ��д��

	int timer = 0;
	while (timer < totalTime) {
		timer++;
		srand(time(0));
		for (int i = 0;i < 10;i++) {
			if (duzhe[i] == 0) {
				duzheTimer[i] += rand() % 5 + 1;//�������ģ����ߵķ����ٶ�
			}
			if (duzhe[i] == 2) {
				duzheTimer[i] += rand() % 7 + 1;//�������ģ����ߵ��Ķ��ٶ�
			}
			if (duzheTimer[i] >= 50) {
				duzheTimer[i] = 0;
				if (duzhe[i] == 0) {
					duzhe[i] = 1;
					cout << i << "�Ŷ��������ȡ" << "\t";
				}
				else if (duzhe[i] == 2) {
					duzhe[i] = 0;
					cout << i << "�Ŷ��߶�ȡ���" << "\t";
				}
			}
		}
		for (int i = 0;i < 3;i++) {
			if (xiezhe[i] == 0) {
				xiezheTimer[i] += rand() % 5 + 1;//�������ģ��д�ߵķ����ٶ�
			}
			if (xiezhe[i] == 2) {
				xiezheTimer[i] += rand() % 30 + 1;//�������ģ��д�ߵ�д���ٶ�
			}
			if (xiezheTimer[i] >= 150) {
				xiezheTimer[i] = 0;
				if (xiezhe[i] == 0) {
					xiezhe[i] = 1;
					cout << i << "��д������д��" << "\t";
				}
				else if (xiezhe[i] == 2) {
					xiezhe[i] = 0;
					cout << i << "��д��д�����" << "\t";
				}
			}
		}
		//solution();

		int state = 0;//0Ϊû����д;
		for (int i = 0;i < 2;i++) {
			if (xiezhe[i] == 2) {
				state = 1;
				break;
			}
		}
		if (state == 0) {
			for (int i = 0;i < 2;i++) {
				if (xiezhe[i] == 1) {
					xiezhe[i] = 2;
					state = 1;
					cout << i << "��д�߿�ʼд��" << "\t";
					break;
				}
			}
		}
		for (int i = 0;i < 7;i++) {
			if (state == 1) {
				if (duzhe[i] == 2) {
					duzhe[i] = 1;
					duzheTimer[i] = 0;//����Ķ�����
					cout << i << "�Ŷ��߱�����ֹ��ȡ" << "\t";
				}
			}
			else {
				if (duzhe[i] == 1) {
					duzhe[i] = 2;
					cout << i << "�Ŷ��߿�ʼ��ȡ" << "\t";
				}
			}
		}
	}

}