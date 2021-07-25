//作者:陈炜潮
#include<iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Table
{
private:
	int philosopherTimer[5] = { 0,0,0,0,0 }; //哲学家的思考(吃面)进程，当值为50时结束思考(吃面)，开始等待吃面(思考)
	int philosopher[5] = { 0,0,0,0,0 }; // 0为在思考 1为再等待 2为在吃面
	int fork[5] = { -1,-1,-1,-1,-1 }; //	-1为空闲 1为被哲学家1号拿着

public:
	Table() {};
	~Table() {};

	void start() {
		int timer = 0;
		while (timer < 500) {//观察时长
			timer++;
			srand(time(0));
			for (int i = 0;i < 5;i++) {
				if (philosopher[i] == 0) {
					philosopherTimer[i] += rand() % 5 + 1;//用随机数模拟哲学家的思考速度
				}
				if (philosopher[i] == 2) {
					philosopherTimer[i] += rand() % 7 + 1;//用随机数模拟哲学家的吃饭速度
				}
				if (philosopherTimer[i] >= 50) {
					philosopherTimer[i] = 0;
					if (philosopher[i] == 0) {
						philosopher[i] = 1;
						cout << i << "号哲学家思考完饿啦" << endl;
					}
					else if (philosopher[i] == 2) {
						philosopher[i] = 0;
						if (i == 0) {//释放叉子
							fork[4] = -1;
							fork[0] = -1;
						}
						else {
							fork[i - 1] = -1;
							fork[i] = -1;
						}
						cout << i << "号哲学家吃饱啦" << endl;
					}
				}
			}
			solution();
		}
	}

	void solution() {
		for (int i = 0;i < 5;i++) {
			if (philosopher[i] == 1) {//偶数号哲学家先拿左边的叉子，奇数号先拿右边。
				if (i == 0) {
					if (fork[4] == -1 || fork[4] == 0) {// 先拿左边
						fork[4] = 0;
						if (fork[0] == -1) {
							fork[0] = 0;
							philosopher[i] = 2;
							cout << i << "号哲学家开吃啦" << endl;
						}
					}
				}
				else if (i % 2 == 1) {
					if (fork[i] == -1 || fork[i] == i) {// 先拿右边
						fork[i] = i;
						if (fork[i - 1] == -1) {
							fork[i - 1] = i;
							philosopher[i] = 2;
							cout << i << "号哲学家开吃啦" << endl;
						}
					}
				}
				else if (i % 2 == 0) {
					if (fork[i - 1] == -1 || fork[i - 1] == i) {// 先拿左边
						fork[i - 1] = i;
						if (fork[i] == -1) {
							fork[i] = i;
							philosopher[i] = 2;
							cout << i << "号哲学家开吃啦" << endl;
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