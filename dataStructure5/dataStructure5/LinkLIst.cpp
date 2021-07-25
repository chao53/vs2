//作者：陈炜潮
#include<iostream>
#include"Linklist.h"
using namespace std;

void LinkList::Creat()//生成函数
{
	this->head = new LinkList(0);//空头结点
	this->next = NULL;
	this->tail = this->head;
}

void LinkList::Add(int x) { //直接从尾节点添加
	LinkList* q = new LinkList(x, NULL);
	this->tail->next = q;
	this->tail = q;
	this->Len++;
}

void LinkList::Insert(int i,int x)//插入函数
{
	LinkList* p = this->head;
	if (i >= 0 && i < this->Len)
	{
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		LinkList* q = new LinkList(x, p->next);
		p->next = q;

		this->Len++;
	}
	else if(i == this->Len){
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		LinkList* q = new LinkList(x, p->next);
		p->next = q;
		this->tail = q;
		this->Len++;
	}
	else {
		cout << "超出范围";
	}
}

void LinkList::Delete(int i)//删除函数
{
	LinkList* p = this->head;

	if (i >= 0 && i < this->Len - 1)
	{
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		LinkList* q = p->next;
		p->next = p->next->next;
		delete q;

		this->Len--;
	}
	else if(i == this->Len -1)
	{
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		LinkList* q = p->next;
		p->next = p->next->next;
		delete q;
		this->tail = p;
		this->Len--;
	}
	else {
		cout << "超出范围";
	}
}

int LinkList::Get(int i) {
	LinkList* p = this->head;
	p = p->next;
	if (i >= 0 && i < this->Len)
	{
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		return p->body;
	}
	else {
		return -1;
	}
}

void LinkList::Print()//输出函数
{
	LinkList* p = this->head;
	p = p->next;
	while (p)
	{
		cout << p->body << ' ';
		p = p->next;
	}
}

void LinkList::Release(LinkList*& head)//释放函数
{
	LinkList* p = this->head;
	while (p) {
		head = head->next;
		delete p;
	}
}

int LinkList::q1(int a)//链式结构第1题
{
	int i = this->Len - a;
	LinkList* p = this->head;
	p = p->next;
	if (i >= 0 && i < this->Len)
	{
		for (int i2 = 0;i2 < i;i2++) {
			p = p->next;
		}
		return p->body;
	}
	else {
		return -1;
	}
}

void LinkList::q2()//链式结构第2题
{
	LinkList* p0 = NULL;
	LinkList* p1 = this->head->next;
	LinkList* p2 = this->head->next->next;
	while (p1 != NULL) {
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL) {
			p2 = p2->next;
		}
		else
		{
			this->head->next = p0;//空头节点指向p0
		}
	}
}

void LinkList::q3(LinkList l1, LinkList l2, LinkList l3) //链式结构第3题
{
	LinkList* p1 = l1.head->next;
	LinkList* p2 = l2.head->next;
	LinkList* p3 = l3.head->next;

	int i1 = 0;
	int i2 = 0;
	for (int i = 0;i < l1.Len + l2.Len;i++) {
		if (i1 == l1.Len) {
			l3.Add(p2->body);
			p2 = p2->next;
			i2++;
		}
		else if (i2 == l2.Len)
		{
			l3.Add(p1->body);
			p1 = p1->next;
			i1++;
		}
		else
		{
			if (p1->body < p2->body) {
				l3.Add(p1->body);
				p1 = p1->next;
				i1++;
			}
			else if (p1->body > p2->body)
			{
				l3.Add(p2->body);
				p2 = p2->next;
				i2++;
			}
			else
			{
				l3.Add(p1->body);
				l3.Add(p2->body);
				p1 = p1->next;
				p2 = p2->next;
				i++;
				i1++;
				i2++;
			}
		}
	}
}

void LinkList::q4()//链式结构第4题
{
	LinkList* p1 = this->head;
	LinkList* p2;
	while (p1->next != NULL) {
		p1 = p1->next;
		for (p2 = p1;p2->next != NULL;) {
			if (p1->body == p2->next->body) {
				LinkList* q = p2->next;
				p2->next = p2->next->next;
				delete q;
				this->Len--;
			}
			else {
				p2 = p2->next;
			}
		}
	}
}

LinkList::LinkList(int body, LinkList* add)//构造函数
{
	this->body = body;
	this->next = add;
	this->tail = this->next;
}

LinkList::~LinkList()//析构函数
{
	next = NULL;
}

LinkList::LinkList()
{
}
