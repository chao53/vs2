
#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int totalTime;
	cout << "请输入运行时长(建议200到1000)" << endl;
	cin >> totalTime;


	//假设有10个读者3个写者
	int duzheTimer[10] = { 0,0,0,0,0,0,0,0,0,0 }; //读者的时间表为50进入下一活动
	int duzhe[10] = { 0,0,0,0,0,0,0,0,0,0 }; // 0为空闲 1为等待 2为在读取
	int xiezheTimer[3] = { 0,0,0 }; //写者的活动进程值为150进入下一活动
	int xiezhe[3] = { 0,0,0 };// 0为发呆 1为等待 2为在写书

	int timer = 0;
	while (timer < totalTime) {
		timer++;
		srand(time(0));
		for (int i = 0;i < 10;i++) {
			if (duzhe[i] == 0) {
				duzheTimer[i] += rand() % 5 + 1;//用随机数模拟读者的发呆速度
			}
			if (duzhe[i] == 2) {
				duzheTimer[i] += rand() % 7 + 1;//用随机数模拟读者的阅读速度
			}
			if (duzheTimer[i] >= 50) {
				duzheTimer[i] = 0;
				if (duzhe[i] == 0) {
					duzhe[i] = 1;
					cout << i << "号读者请求读取" << "\t";
				}
				else if (duzhe[i] == 2) {
					duzhe[i] = 0;
					cout << i << "号读者读取完毕" << "\t";
				}
			}
		}
		for (int i = 0;i < 3;i++) {
			if (xiezhe[i] == 0) {
				xiezheTimer[i] += rand() % 5 + 1;//用随机数模拟写者的发呆速度
			}
			if (xiezhe[i] == 2) {
				xiezheTimer[i] += rand() % 30 + 1;//用随机数模拟写者的写作速度
			}
			if (xiezheTimer[i] >= 150) {
				xiezheTimer[i] = 0;
				if (xiezhe[i] == 0) {
					xiezhe[i] = 1;
					cout << i << "号写者请求写入" << "\t";
				}
				else if (xiezhe[i] == 2) {
					xiezhe[i] = 0;
					cout << i << "号写者写入完毕" << "\t";
				}
			}
		}
		//solution();

		int state = 0;//0为没人在写;
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
					cout << i << "号写者开始写入" << "\t";
					break;
				}
			}
		}
		for (int i = 0;i < 7;i++) {
			if (state == 1) {
				if (duzhe[i] == 2) {
					duzhe[i] = 1;
					duzheTimer[i] = 0;//清空阅读进程
					cout << i << "号读者被迫中止读取" << "\t";
				}
			}
			else {
				if (duzhe[i] == 1) {
					duzhe[i] = 2;
					cout << i << "号读者开始读取" << "\t";
				}
			}
		}
	}

}