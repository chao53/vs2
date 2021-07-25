//作者：陈炜潮

#pragma once
#define MAXLEN 100       //最多存放MAXLEN个元素
class orderList           //定义顺序表类
{
public:
    orderList();                                  //构造函数
    void initialList(orderList* L);               //线性表的初始化
    int listLength(orderList L);                  //求线性表的长度
    int getElement(orderList L, int i);           //按序号取元素
    int listLocate(orderList L, int x);           //查找元素
    int listAdd(orderList* L, int x);             //添加元素
    int listInsert(orderList* L, int x, int i);   //插入元素
    int listDelete(orderList* L, int i);        //删除元素
    void listPrint(orderList L);
    int data[MAXLEN];                           //定义存储表中元素的数组
    int listLen;                                //数组长度
    ~orderList();

    int q1(orderList L, int a);
    void q2(orderList* L);
    void q3(orderList L1, orderList L2, orderList* L3);
    void q4(orderList L1, orderList L2, orderList* L3, orderList* L4);
    void q5(orderList* L);
};
