#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
LNode<ElemType>* LinkList_Create_Common(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);

int main(int argc, char** argv) {
    //初始化linkListA和linkListB
    //初始化
    LNode<int> linkListA;
    const int  lengthA        = 7;
    int        dataA[lengthA] = {2, 10, 18, 30, 40, 41, 42};
    linkListA.create(dataA, lengthA);
    LNode<int> linkListB;
    const int  lengthB        = 8;
    int        dataB[lengthB] = {2, 10, 15, 18, 20, 30, 40, 42};
    linkListB.create(dataB, lengthB);
    //打印
    linkListA.print();
    linkListB.print();
    //两个递增排序的单链表，公共元素产生新的单链表
    LNode<int>* linkListC = LinkList_Create_Common(linkListA, linkListB);
    (*linkListC).print();
    return 1;
}

//两个递增排序的单链表，公共元素产生新的单链表
template<class ElemType>
LNode<ElemType>* LinkList_Create_Common(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    LNode<ElemType>* linkListC =
            (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
    if (linkListC) {
        linkListC->next = NULL;
    }
    LNode<ElemType>* pointA = &linkListA;
    LNode<ElemType>* pointB = &linkListB;
    LNode<ElemType>* pointC = linkListC;
    while (pointA->next && pointB->next) {
        // cout << pointA->next->data << "---" << pointB->next->data << endl;
        if (pointA->next->data < pointB->next->data) {
            pointA = pointA->next;
        } else if (pointA->next->data > pointB->next->data) {
            pointB = pointB->next;
        } else {
            LNode<ElemType>* lnode =
                    (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
            if (lnode) {
                lnode->data = pointA->next->data;
                lnode->next = NULL;
            }
            // cout << "PointC---" << lnode->data << endl;
            if (pointC) {
                pointC->next = lnode;
                pointC       = pointC->next;
            }
            pointA = pointA->next;
            pointB = pointB->next;
        }
    }
    return linkListC;
}