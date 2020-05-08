#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
LNode<ElemType>* LinkList_Merge(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);

//这道题是第十题的加强版
//第十题使用尾插法，这道题使用头插法
int main(int argc, char** argv) {
    //初始化linkListA和linkListB
    //初始化
    LNode<int> linkListA;
    const int  lengthA        = 7;
    int        dataA[lengthA] = {4, 6, 13, 20, 60, 70, 82};
    linkListA.create(dataA, lengthA);
    LNode<int> linkListB;
    const int  lengthB        = 11;
    int        dataB[lengthB] = {0, 3, 5, 9, 11, 13, 17, 20, 28, 30, 32};
    linkListB.create(dataB, lengthB);
    //打印
    linkListA.print();
    linkListB.print();
    //两个递增次序的单链表合并成一个递减次序的单链表
    LNode<int>* linkListMerge = LinkList_Merge(linkListA, linkListB);
    //打印
    (*linkListMerge).print();
    return 1;
}

//两个递增次序的单链表合并成一个递减次序的单链表
template<class ElemType>
LNode<ElemType>* LinkList_Merge(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    LNode<ElemType>* linkListC =
            (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
    //警告 C6011：取消对 NULL 指针“linkListC”的引用。
    if (linkListC) {
        linkListC->next         = NULL;
        LNode<ElemType>* pointA = &linkListA;
        LNode<ElemType>* pointB = &linkListB;
        LNode<ElemType>* pointC = NULL;
        while (linkListC && pointA->next && pointB->next) {
            if (pointA->next->data < pointB->next->data) {
                pointC          = pointA->next;
                pointA->next    = pointA->next->next;
                pointC->next    = linkListC->next;
                linkListC->next = pointC;
            } else {
                pointC          = pointB->next;
                pointB->next    = pointB->next->next;
                pointC->next    = linkListC->next;
                linkListC->next = pointC;
            }
        }
        while (pointA->next) {
            pointC          = pointA->next;
            pointA->next    = pointA->next->next;
            pointC->next    = linkListC->next;
            linkListC->next = pointC;
        }
        while (pointB->next) {
            pointC          = pointB->next;
            pointB->next    = pointB->next->next;
            pointC->next    = linkListC->next;
            linkListC->next = pointC;
        }
    }
    return linkListC;
}