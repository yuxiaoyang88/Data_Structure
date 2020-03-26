#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Create_Common_Node(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);
template<class ElemType>
LNode<ElemType>* LinkList_Find_Common_Node(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);

int main(int argc, char** argv) {
    //创建linkListA和linkListB
    //初始化
    LNode<int> linkListA;
    const int  lengthA        = 11;
    int        dataA[lengthA] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkListA.create(dataA, lengthA);
    LNode<int> linkListB;
    const int  lengthB        = 4;
    int        dataB[lengthB] = {2, 3, 8, 6};
    linkListB.create(dataB, lengthB);
    LinkList_Create_Common_Node(linkListA, linkListB);
    //打印
    linkListA.print();
    linkListB.print();
    //下面才是精华
    LNode<int>* lnode = LinkList_Find_Common_Node(linkListA, linkListB);
    //把两者相同的第一个元素值打印出来
    cout << "两个链表公共结点为：" << lnode->data << endl;
    return 1;
}
//初始化两个链表的公共结点
template<class ElemType>
void LinkList_Create_Common_Node(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    LNode<ElemType>* pointA = &linkListA;
    LNode<ElemType>* pointB = &linkListB;
    while (pointA->next != NULL) {
        pointA = pointA->next;
    }
    while (pointB->next != NULL) {
        pointB = pointB->next;
    }
    int data[4] = {3, 4, 9, 7};
    //第一个共同结点需要两个结点共同连接一下
    for (int i = 0; i < 4; i++) {
        LNode<ElemType>* nextLNode =
                (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
        if (nextLNode) {
            nextLNode->data = data[i];
            nextLNode->next = NULL;
            if (pointA != NULL) {
                pointA->next = nextLNode;
                pointA       = pointA->next;
            }
            if (pointB != NULL) {
                pointB->next = nextLNode;
                pointB       = pointB->next;
            }
        }
    }
}

//找出两个单链表公共部分
template<class ElemType>
LNode<ElemType>* LinkList_Find_Common_Node(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    int              lengthA      = linkListA.length();
    int              lengthB      = linkListB.length();
    LNode<ElemType>* LongLinkList = lengthA > lengthB ? &linkListA : &linkListB;
    LNode<ElemType>* ShortLinkList =
            lengthA < lengthB ? &linkListA : &linkListB;
    int cha = lengthA - lengthB > 0 ? lengthA - lengthB : lengthB - lengthA;
    LNode<ElemType>* pointA = LongLinkList;
    LNode<ElemType>* pointB = ShortLinkList;
    while (cha > 0) {
        pointA = pointA->next;
        cha--;
    }
    while (pointA != NULL && pointB != NULL) {
        if (pointA == pointB) {
            return pointA;
        } else {
            pointA = pointA->next;
            pointB = pointB->next;
        }
    }
    return NULL;
}
