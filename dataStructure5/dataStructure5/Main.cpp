//���ߣ���쿳�
#include<iostream>
#include"Linklist.h"
using namespace std;

void q1() {
	LinkList l1;
	l1.Creat();
	cout << "����������\n";
	int num;
	while (cin >> num) {
		l1.Add(num);
		if (cin.get() == '\n')   //�����س�����ֹ
			break;
	}
	int a; 
	cout << "����������\n";
	cin >> a;
	cout << l1.q1(a);
}

void q2() {
	LinkList l2;
	l2.Creat();
	cout << "����������\n";
	int num;
	while (cin >> num) {
		l2.Add(num);
		if (cin.get() == '\n')   //�����س�����ֹ
			break;
	}
	l2.q2();
	l2.Print();
}

void q3() {
	LinkList l3;
	l3.Creat();
	cout << "�������һ������\n";
	int num;
	while (cin >> num) {
		l3.Add(num);
		if (cin.get() == '\n')   //�����س�����ֹ
			break;
	}

	LinkList l4;
	l4.Creat();
	cout << "������ڶ�������\n";
	while (cin >> num) {
		l4.Add(num);
		if (cin.get() == '\n')   //�����س�����ֹ
			break;
	}

	LinkList l5;
	l5.Creat();

	l3.q3(l3, l4, l5);

	l5.Print();
}

void q4() {
	LinkList l4;
	l4.Creat();
	cout << "����������\n";
	int num;
	while (cin >> num) {
		l4.Add(num);
		if (cin.get() == '\n')   //�����س�����ֹ
			break;
	}
	l4.q4();
	l4.Print();
}

int main() {
	while (1) {
		int qnum = 0;
		cout << "\n���������\n";
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
		default:
			cout << "û������\n";
			break;
		}
	}
}