////����:��쿳�
//#include<iostream>
//#include <windows.h>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//class Book
//{
//private:
//	//7������2��д��
//	int ReaderTimer[7] = { 0,0,0,0,0,0,0 }; //���ߵĻ����ֵΪ50������һ�
//	int Reader[7] = { 0,0,0,0,0,0,0}; // 0Ϊ���� 1Ϊ�ȴ� 2Ϊ�ڶ���
//	int WriterTimer[2] = {0,0}; //д�ߵĻ����ֵΪ150������һ�
//	int Writer[2] = {0,0};// 0Ϊ���� 1Ϊ�ȴ� 2Ϊ��д��
//
//public:
//	Book() {};
//	~Book() {};
//
//	void start() {
//		int timer = 0;
//		while (timer < 500) {//�۲�ʱ��
//			timer++;
//			srand(time(0));
//			for (int i = 0;i < 7;i++) {
//				if (Reader[i] == 0) {
//					ReaderTimer[i] += rand() % 5 + 1;//�������ģ����ߵķ����ٶ�
//				}
//				if (Reader[i] == 2) {
//					ReaderTimer[i] += rand() % 7 + 1;//�������ģ����ߵ��Ķ��ٶ�
//				}
//				if (ReaderTimer[i] >= 50) {
//					ReaderTimer[i] = 0;
//					if (Reader[i] == 0) {
//						Reader[i] = 1;
//						cout << i << "�Ŷ����뿴����" << endl;
//					}
//					else if (Reader[i] == 2) {
//						Reader[i] = 0;
//						cout << i << "�Ŷ��߿�����" << endl;
//					}
//				}
//			}
//			for (int i = 0;i < 2;i++) {
//				if (Writer[i] == 0) {
//					WriterTimer[i] += rand() % 5 + 1;//�������ģ��д�ߵķ����ٶ�
//				}
//				if (Writer[i] == 2) {
//					WriterTimer[i] += rand() % 30 + 1;//�������ģ��д�ߵ�д���ٶ�
//				}
//				if (WriterTimer[i] >= 150) {
//					WriterTimer[i] = 0;
//					if (Writer[i] == 0) {
//						Writer[i] = 1;
//						cout << i << "��д����д������" << endl;
//					}
//					else if (Writer[i] == 2) {
//						Writer[i] = 0;
//						cout << i << "��д��д����" << endl;
//					}
//				}
//			}
//			solution();
//		}
//	}
//
//	void solution() {
//		int state = 0;//0Ϊû����д;
//		for (int i = 0;i < 2;i++) {
//			if (Writer[i] == 2) {
//				state = 1;
//				break;
//			}
//		}
//		if (state == 0) {
//			for (int i = 0;i < 2;i++) {
//				if (Writer[i] == 1) {
//					Writer[i] = 2;
//					state = 1;
//					cout << i<<"��д�߿�ʼд��"<<endl;
//					break;
//				}
//			}
//		}
//		for (int i = 0;i < 7;i++) {
//			if (state == 1) {
//				if (Reader[i] == 2) {
//					Reader[i] = 1;
//					ReaderTimer[i] = 0;//����Ķ�����
//					cout << i << "�Ŷ��߱���ֹͣ�Ķ���" << endl;
//				}
//			}
//			else {
//				if (Reader[i] == 1) {
//					Reader[i] = 2;
//					cout << i << "�Ŷ��߿�ʼ�Ķ���" << endl;
//				}
//			}
//		}
//	}
//};
//
//int main() {
//	Book T;
//	T.start();
//}