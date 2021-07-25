////作者:陈炜潮
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
//	//7个读者2个写者
//	int ReaderTimer[7] = { 0,0,0,0,0,0,0 }; //读者的活动进程值为50进入下一活动
//	int Reader[7] = { 0,0,0,0,0,0,0}; // 0为发呆 1为等待 2为在读书
//	int WriterTimer[2] = {0,0}; //写者的活动进程值为150进入下一活动
//	int Writer[2] = {0,0};// 0为发呆 1为等待 2为在写书
//
//public:
//	Book() {};
//	~Book() {};
//
//	void start() {
//		int timer = 0;
//		while (timer < 500) {//观察时长
//			timer++;
//			srand(time(0));
//			for (int i = 0;i < 7;i++) {
//				if (Reader[i] == 0) {
//					ReaderTimer[i] += rand() % 5 + 1;//用随机数模拟读者的发呆速度
//				}
//				if (Reader[i] == 2) {
//					ReaderTimer[i] += rand() % 7 + 1;//用随机数模拟读者的阅读速度
//				}
//				if (ReaderTimer[i] >= 50) {
//					ReaderTimer[i] = 0;
//					if (Reader[i] == 0) {
//						Reader[i] = 1;
//						cout << i << "号读者想看书啦" << endl;
//					}
//					else if (Reader[i] == 2) {
//						Reader[i] = 0;
//						cout << i << "号读者看完啦" << endl;
//					}
//				}
//			}
//			for (int i = 0;i < 2;i++) {
//				if (Writer[i] == 0) {
//					WriterTimer[i] += rand() % 5 + 1;//用随机数模拟写者的发呆速度
//				}
//				if (Writer[i] == 2) {
//					WriterTimer[i] += rand() % 30 + 1;//用随机数模拟写者的写作速度
//				}
//				if (WriterTimer[i] >= 150) {
//					WriterTimer[i] = 0;
//					if (Writer[i] == 0) {
//						Writer[i] = 1;
//						cout << i << "号写者想写东西啦" << endl;
//					}
//					else if (Writer[i] == 2) {
//						Writer[i] = 0;
//						cout << i << "号写者写完啦" << endl;
//					}
//				}
//			}
//			solution();
//		}
//	}
//
//	void solution() {
//		int state = 0;//0为没人在写;
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
//					cout << i<<"号写者开始写啦"<<endl;
//					break;
//				}
//			}
//		}
//		for (int i = 0;i < 7;i++) {
//			if (state == 1) {
//				if (Reader[i] == 2) {
//					Reader[i] = 1;
//					ReaderTimer[i] = 0;//清空阅读进程
//					cout << i << "号读者被迫停止阅读啦" << endl;
//				}
//			}
//			else {
//				if (Reader[i] == 1) {
//					Reader[i] = 2;
//					cout << i << "号读者开始阅读啦" << endl;
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