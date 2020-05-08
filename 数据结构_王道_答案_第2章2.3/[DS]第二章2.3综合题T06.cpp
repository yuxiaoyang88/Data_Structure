#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Sort(LNode<ElemType>& linkList);
template<class ElemType>
void LinkList_Move(LNode<ElemType>& linkList, LNode<ElemType>& lnode);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkList.create(data, length);
    //打印
    linkList.print();
    //使元素递增有序
    LinkList_Sort(linkList);
    //打印
    linkList.print();
    return 1;
}

//逆置单链表，遍历的过程中改变指针指向
template<class ElemType>
void LinkList_Sort(LNode<ElemType>& linkList) {
    //分成两步，先把第5个元素放到合适的位置
    LNode<ElemType>* point     = linkList.next->next;
    LNode<ElemType>* nextPoint = NULL;
    while (point) {
        nextPoint = point->next;
        LinkList_Move(linkList, *point);
        point = nextPoint;
    }
}
template<class ElemType>
void LinkList_Move(LNode<ElemType>& linkList, LNode<ElemType>& lnode) {
    LNode<ElemType>* point    = linkList.next;
    LNode<ElemType>* prePoint = &linkList;
    while (point && point->data < lnode.data) {
        prePoint = point;
        point    = point->next;
    }
    prePoint->next = &lnode;
    if (point && point != &lnode) {
        lnode.next = point;
    }
    // point为什么为NULL？
    //{2}->{2,3}时2后面是有3的，不为空
    // point == &lnode而不是空是因为不是从2开始插入的
    //{2,3}之后，我们就用语句限定了3后面是NULL
    //从此以后，插入的数和最后一个数相等，point就是NULL
    //如果你不写lnode.next = NULL，原先的元素会带有指针，会无限循环下去
    if (!point || point == &lnode) {
        lnode.next = NULL;
    }
}