#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Delete_The_Same(LNode<ElemType>& linkList);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 51, 70};
    linkList.create(data, length);
    //打印
    linkList.print();
    //删除重复元素
    LinkList_Delete_The_Same(linkList);
    //打印
    linkList.print();
    return 1;
}

//删除重复元素
template<class ElemType>
void LinkList_Delete_The_Same(LNode<ElemType>& linkList) {
    LNode<ElemType>* point    = linkList.next;
    LNode<ElemType>* delPoint = &linkList;
    //警告 C6001：使用未初始化的内存 <point->next>
    while (point->next) {
        if (point->data == point->next->data) {
            delPoint = point->next;
            //先赋值再free
            point->next = point->next->next;
            free(delPoint);
        } else {
            point = point->next;
        }
    }
}
