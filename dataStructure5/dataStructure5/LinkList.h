//×÷Õß£º³Âì¿³±
#include<iostream>
using namespace std;
class LinkList
{
public:
	LinkList* head;
	LinkList* tail;
	int Len = 0;
	~LinkList();
	LinkList(int body, LinkList* add = NULL);
	LinkList();
	void Creat();
	void Add(int x);
	void Insert(int i,int x);
	void Delete(int i);
	//int Length(LinkList*& head);
	int Get(int i);
	void Print();
	void Release(LinkList*& head);

	int q1(int i);
	void q2();
	void q3(LinkList l1, LinkList l2, LinkList l3);
	void q4();
private:
	int body;
	LinkList* next;
};
