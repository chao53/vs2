//作者：陈炜潮

#include <iostream>
#include "orderList.h"

using namespace std;

orderList::orderList()
{

}

void orderList::initialList(orderList* L)
{
    L->listLen = 0;   //初始化线性表，即建立空表
}
int orderList::listLength(orderList L)
{
    return L.listLen;
}

int orderList::getElement(orderList L, int i)
{
    if (i<0 || i>L.listLen - 1)
        return -1;
    else
    {
        return L.data[i];
    }
}

int orderList::listLocate(orderList L, int x)
{
    for (int i = 0; i < L.listLen; i++)
        if (L.data[i] == x)
            return i;           //元素x在L中，返回此值
    return -1;                       //x不再L中，返回-1
}

int orderList::listAdd(orderList* L, int x) 
{
    if (L->listLen == MAXLEN) {
        return 0; //表满，返回-1
    }                     
    else
    {
        L->data[listLen] = x;
        L->listLen++;
        return 2;
    }
}

int orderList::listInsert(orderList* L, int x, int i)
{
    if (L->listLen == MAXLEN)
        return 0;                             //表满，返回0
    else if (i<0 || i>L->listLen)
        return 1;                             //序号i超出范围，返回1
    else
    {
        for (int j = L->listLen - 1; j >= i; j--)
            L->data[j + 1] = L->data[j];
        L->data[i] = x;
        L->listLen++;
        return 2;                              //成功插入，返回2
    }
}

int orderList::listDelete(orderList* L, int i)
{
    if (L->listLen <= 0)
        return 0;       //空表,返回0
    else if (i<0 || i>L->listLen - 1)
        return 2;       //删除的的序号不再范围内，返回1
    else
    {
        for (int j = i + 1; j < L->listLen; j++)
            L->data[j - 1] = data[j];
        L->listLen--;
        return 2;      //成功删除，返回2
    }
}

void orderList::listPrint(orderList L)
{
    for (int i = 0; i < L.listLen;i++) {
        cout << L.data[i]<<" ";
    }
}

int orderList::q1(orderList L, int a) //顺序结构第1题
{
    int m = 0;
    for (int i = 0; i < L.listLen; i++)
    {
        if (a <= L.data[i]) {
            m = 1;
            return i;
        }
    }
    if (m == 0) {
        return L.listLen;
    }
}

void orderList::q2(orderList* L) //顺序结构第2题
{
    int k;
    for (int i = 0; i < L->listLen/2;i++) {
        k = L->data[i];
        L->data[i] = L->data[L->listLen - 1 - i];
        L->data[L->listLen - 1 - i] = k;
    }
}

void orderList::q3(orderList L1, orderList L2, orderList* L3)//顺序结构第3题
{
    int i1 = 0;
    int i2 = 0;
    for (int i = 0;i < L1.listLen + L2.listLen;i++) {
        if (i1 == L1.listLen) {
            L3->listAdd(L3, L2.data[i2]);
            i2++;
        }
        else if(i2 == L2.listLen)
        {
            L3->listAdd(L3, L1.data[i1]);
            i1++;
        }
        else
        {
            if (L1.data[i1] < L2.data[i2]) {
                L3->listAdd(L3, L1.data[i1]);
                i1++;
            }
            else if (L1.data[i1] > L2.data[i2])
            {
                L3->listAdd(L3, L2.data[i2]);
                i2++;
            }
            else
            {
                L3->listAdd(L3, L1.data[i1]);
                L3->listAdd(L3, L2.data[i2]);
                i++;
                i1++;
                i2++;
            }
        }
    }
}

void orderList::q4(orderList L1, orderList L2, orderList* L3, orderList* L4)
{
    int i1 = 0;
    int i2 = 0;
    for (int i = 0;i < L1.listLen + L2.listLen;i++) {
        if (i1 == L1.listLen) {
            L3->listAdd(L3, L2.data[i2]);
            i2++;
        }
        else if (i2 == L2.listLen)
        {
            L3->listAdd(L3, L1.data[i1]);
            i1++;
        }
        else
        {
            if (L1.data[i1] < L2.data[i2]) {
                L3->listAdd(L3, L1.data[i1]);
                i1++;
            }
            else if (L1.data[i1] > L2.data[i2])
            {
                L3->listAdd(L3, L2.data[i2]);
                i2++;
            }
            else
            {
                L3->listAdd(L3, L1.data[i1]);
                L4->listAdd(L4, L1.data[i1]);
                i++;
                i1++;
                i2++;
            }
        }
    }
}

void orderList::q5(orderList* L)
{
    int i1 = 0;
    int i2 = 0;
    int k = 0;
    int m = 1;
    while(i2 < L->listLen) {
        if (L->data[i1]*m < 0) {
            for (i2 = i1;i2 < L->listLen;i2++) {
                if (L->data[i2]*m > 0) {
                    k = L->data[i1];
                    L->data[i1] = L->data[i2];
                    L->data[i2] = k;
                    i1++;
                    m *= -1;
                    break;
                }
            }
        }
        else
        {
            i1++;
            m *= -1;
        }
    }
}

orderList::~orderList()
{
}