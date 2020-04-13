#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Print_Recursion(LNode<ElemType>& lnode);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {4, 3, 5, 9, 1, 8, 2, 3, 2, 7, 2};
    linkList.create(data, length);
    //打印
    linkList.print();
    //逆序显示链表
    LinkList_Print_Recursion(*(linkList.next));
    return 1;
}

//逆序显示链表
template<class ElemType>
void LinkList_Print_Recursion(LNode<ElemType>& lnode) {
    if (lnode.next) {
        LinkList_Print_Recursion(*(lnode.next));
    }
    cout << lnode.data << " ";
}