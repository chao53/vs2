//���ߣ���쿳�

#pragma once
#define MAXLEN 100       //�����MAXLEN��Ԫ��
class orderList           //����˳�����
{
public:
    orderList();                                  //���캯��
    void initialList(orderList* L);               //���Ա�ĳ�ʼ��
    int listLength(orderList L);                  //�����Ա�ĳ���
    int getElement(orderList L, int i);           //�����ȡԪ��
    int listLocate(orderList L, int x);           //����Ԫ��
    int listAdd(orderList* L, int x);             //���Ԫ��
    int listInsert(orderList* L, int x, int i);   //����Ԫ��
    int listDelete(orderList* L, int i);        //ɾ��Ԫ��
    void listPrint(orderList L);
    int data[MAXLEN];                           //����洢����Ԫ�ص�����
    int listLen;                                //���鳤��
    ~orderList();

    int q1(orderList L, int a);
    void q2(orderList* L);
    void q3(orderList L1, orderList L2, orderList* L3);
    void q4(orderList L1, orderList L2, orderList* L3, orderList* L4);
    void q5(orderList* L);
};
