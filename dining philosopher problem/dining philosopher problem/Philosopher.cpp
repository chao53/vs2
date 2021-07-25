//����:��쿳�
#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Table
{
private:
	int philosopherTimer[5] = { 0,0,0,0,0 }; //��ѧ�ҵ�˼��(����)���̣���ֵΪ50ʱ����˼��(����)����ʼ�ȴ�����(˼��)
	int philosopher[5] = { 0,0,0,0,0 }; // 0Ϊ��˼�� 1Ϊ�ٵȴ� 2Ϊ�ڳ���
	int fork[5] = { -1,-1,-1,-1,-1 }; //	-1Ϊ���� 1Ϊ����ѧ��1������

public:
	Table() {};
	~Table() {};

	void start() {
		int timer = 0;
		while (timer < 500) {//�۲�ʱ��
			timer++;
			srand(time(0));
			for (int i = 0;i < 5;i++) {
				if (philosopher[i] == 0) {
					philosopherTimer[i] += rand() % 5 + 1;//�������ģ����ѧ�ҵ�˼���ٶ�
				}
				if (philosopher[i] == 2) {
					philosopherTimer[i] += rand() % 7 + 1;//�������ģ����ѧ�ҵĳԷ��ٶ�
				}
				if (philosopherTimer[i] >= 50) {
					philosopherTimer[i] = 0;
					if (philosopher[i] == 0) {
						philosopher[i] = 1;
						cout << i << "����ѧ��˼�������" << endl;
					}
					else if (philosopher[i] == 2) {
						philosopher[i] = 0;
						if (i == 0) {//�ͷŲ���
							fork[4] = -1;
							fork[0] = -1;
						}
						else {
							fork[i - 1] = -1;
							fork[i] = -1;
						}
						cout << i << "����ѧ�ҳԱ���" << endl;
					}
				}
			}
			solution();
		}
	}

	void solution() {
		for (int i = 0;i < 5;i++) {
			if (philosopher[i] == 1) {//ż������ѧ��������ߵĲ��ӣ������������ұߡ�
				if (i == 0) {
					if (fork[4] == -1 || fork[4] == 0) {// �������
						fork[4] = 0;
						if (fork[0] == -1) {
							fork[0] = 0;
							philosopher[i] = 2;
							cout << i << "����ѧ�ҿ�����" << endl;
						}
					}
				}
				else if (i % 2 == 1) {
					if (fork[i] == -1 || fork[i] == i) {// �����ұ�
						fork[i] = i;
						if (fork[i - 1] == -1) {
							fork[i - 1] = i;
							philosopher[i] = 2;
							cout << i << "����ѧ�ҿ�����" << endl;
						}
					}
				}
				else if (i % 2 == 0) {
					if (fork[i - 1] == -1 || fork[i - 1] == i) {// �������
						fork[i - 1] = i;
						if (fork[i] == -1) {
							fork[i] = i;
							philosopher[i] = 2;
							cout << i << "����ѧ�ҿ�����" << endl;
						}
					}
				}

			}
		}
	}
};

int main() {
	Table T;
	T.start();
}