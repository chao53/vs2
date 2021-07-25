//×÷Õß£º³Âì¿³±
#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main() {
	BinaryTree Btree1;
	Btree1.creat();
	Btree1.grow("{{{{{},3,{}},5,{{},4,{}}},1,{}},0,{{},2,{}}}");
	cout << Btree1.firstRootOrder() << endl;
	cout << Btree1.middleRootOrder() << endl;
	cout << Btree1.levelRootOrder() << endl;
	cout << Btree1.countLevel() << endl;
	cout << Btree1.countEachLevel() << endl;
}
