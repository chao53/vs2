//作者：陈炜潮
#include <iostream>
#include "orderList.h"

using namespace std;

void q1();
void q2();
void q3();
void q4();
void q5();

int main() {
	while (1) {
		int qnum = 0;
		cout << "\n请输入题号\n";
		cin >> qnum;
		switch (qnum)
		{
		case 1:
			q1();
			break;
		case 2:
			q2();
			break;
		case 3:
			q3();
			break;
		case 4:
			q4();
			break;
		case 5:
			q5();
			break;
		default:
			cout << "没有这题\n";
			break;
		}
	}

}

void q1() {
	orderList* o1 = nullptr;
	o1 = new orderList;
	o1->initialList(o1);

	int num;
	int i = 0;

	cout << "请输入数组\n";

	while (cin >> num) {

		o1->listAdd(o1, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}
	int a = 0;

	cout << "请输入数字\n";
	cin >> a;
	cout << o1->q1(*o1, a);
}

void q2() 
{
	orderList* o1 = nullptr;
	o1 = new orderList;
	o1->initialList(o1);

	int num;
	int i = 0;

	cout << "请输入数组\n";

	while (cin >> num) {

		o1->listAdd(o1, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}
	o1->q2(o1);
	o1->listPrint(*o1);
}

void q3()
{
	orderList* o3 = nullptr;
	o3 = new orderList;
	o3->initialList(o3);

	orderList* o4 = nullptr;
	o4 = new orderList;
	o4->initialList(o4);

	orderList* o5 = nullptr;
	o5 = new orderList;
	o5->initialList(o5);

	int num;
	int i = 0;
	int i2 = 0;

	cout << "请输入第一个数组\n";
	while (cin >> num) {
		o3->listAdd(o3, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}

	cout << "请输入第二个数组\n";
	while (cin >> num) {
		o4->listAdd(o4, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}

	o3->q3(*o3, *o4, o5);
	o5->listPrint(*o5);
}

void q4()
{
	orderList* o6 = nullptr;
	o6 = new orderList;
	o6->initialList(o6);

	orderList* o7 = nullptr;
	o7 = new orderList;
	o7->initialList(o7);

	orderList* o8 = nullptr;
	o8 = new orderList;
	o8->initialList(o8);

	orderList* o9 = nullptr;
	o9 = new orderList;
	o9->initialList(o9);

	int num;
	int i = 0;
	int i2 = 0;

	cout << "请输入第一个数组\n";
	while (cin >> num) {
		o6->listAdd(o6, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}

	cout << "请输入第二个数组\n";
	while (cin >> num) {
		o7->listAdd(o7, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}

	o6->q4(*o6, *o7, o8, o9);

	cout << "Union :";
	o8->listPrint(*o8);
	cout << "\nIntersection :";
	o9->listPrint(*o9);
}

void q5()
{
	orderList* o1 = nullptr;
	o1 = new orderList;
	o1->initialList(o1);

	int num;
	int i = 0;

	cout << "请输入数组\n";

	while (cin >> num) {

		o1->listAdd(o1, num);
		if (cin.get() == '\n')   //遇到回车，终止
			break;
	}
	o1->q5(o1);
	o1->listPrint(*o1);
}