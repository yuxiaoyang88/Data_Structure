#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void Del_X(LNode<ElemType>& linkList, int x);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 2};
    linkList.create(data, length);
    //打印
    linkList.print();
    //非递归删除值为x的元素
    Del_X(linkList, 2);
    //打印
    linkList.print();
    return 1;
}

//非递归删除值为x的元素
template<class ElemType>
void Del_X(LNode<ElemType>& linkList, int x) {
    LNode<ElemType>* point    = linkList.next;
    LNode<ElemType>* prePoint = &linkList;
    LNode<ElemType>* removePoint;
    while (point != NULL) {
        if (point->data == x) {
            removePoint    = point;
            prePoint->next = point->next;
            point          = point->next;
            free(removePoint);
        } else {
            prePoint = point;
            point    = point->next;
        }
    }
}