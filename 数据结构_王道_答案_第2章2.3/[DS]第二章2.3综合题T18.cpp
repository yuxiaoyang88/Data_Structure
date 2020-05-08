#include <iostream>
#include "带有头指针的循环单链表.hpp"
using namespace std;

template<class ElemType>
void CircularLinkList_Merge(
        LNode<ElemType>& CircularLinkListA,
        LNode<ElemType>& CircularLinkListB);

int main(int argc, char** argv) {
    //初始化circularLinkListA和circularLinkListB
    //初始化
    LNode<int> circularLinkListA;
    const int  lengthA        = 11;
    int        dataA[lengthA] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    circularLinkListA.create(dataA, lengthA);
    LNode<int> circularLinkListB;
    const int  lengthB        = 8;
    int        dataB[lengthB] = {100, 3, 5, 9, 98, 2, 7, 11};
    circularLinkListB.create(dataB, lengthB);
    //打印
    circularLinkListA.print();
    circularLinkListB.print();
    //将A和B循环单链表合并到A循环单链表
    CircularLinkList_Merge(circularLinkListA, circularLinkListB);
    //打印
    circularLinkListA.print();
    return 1;
}

//将A和B循环单链表合并到A循环单链表
template<class ElemType>
void CircularLinkList_Merge(
        LNode<ElemType>& CircularLinkListA,
        LNode<ElemType>& CircularLinkListB) {
    LNode<ElemType>* pointA = &CircularLinkListA;
    LNode<ElemType>* pointB = &CircularLinkListB;
    while (pointA->next != &CircularLinkListA) {
        pointA = pointA->next;
    }
    while (pointB->next != &CircularLinkListB) {
        pointB = pointB->next;
    }
    pointA->next = CircularLinkListB.next;
    pointB->next = &CircularLinkListA;
}