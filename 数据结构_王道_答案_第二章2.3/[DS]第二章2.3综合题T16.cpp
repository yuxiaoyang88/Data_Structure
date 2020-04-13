#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
bool LinkList_Find_The_Same(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);

int main(int argc, char** argv) {
    //初始化linkListA和linkListB
    //初始化
    LNode<int> linkListA;
    const int  lengthA        = 7;
    int        dataA[lengthA] = {1, 3, 1, 3, 4, 6, 9};
    linkListA.create(dataA, lengthA);
    LNode<int> linkListB;
    const int  lengthB        = 4;
    int        dataB[lengthB] = {1, 3, 4, 6};
    linkListB.create(dataB, lengthB);
    //打印
    linkListA.print();
    linkListB.print();
    //看A中是否包含B
    bool result = LinkList_Find_The_Same(linkListA, linkListB);
    cout << "A是否包含B：" << (result == true ? "true" : "false") << endl;
    return 1;
}

//看A中是否包含B
template<class ElemType>
bool LinkList_Find_The_Same(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    LNode<ElemType>* point  = &linkListA;
    LNode<ElemType>* pointA = &linkListA;
    LNode<ElemType>* pointB = linkListB.next;
    while (point->next) {
        pointA = point->next;
        while (pointA->data == pointB->data) {
            cout << "pointA--" << pointA->data << endl;
            if (pointB->next == NULL) {
                return true;
            }
            if (pointA->next == NULL) {
                return false;
            }
            pointA = pointA->next;
            pointB = pointB->next;
        }
        point  = point->next;
        pointB = linkListB.next;
    }
    return false;
}