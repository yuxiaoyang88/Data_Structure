#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Delete_Min(LNode<ElemType>& linkList);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {1, 3, 5, 0, 1, 8, 2, 3, 2, 7, 9};
    // int data[length] = { 0,3,5,9,1,8,2,3,2,7,2 };
    // int data[length] = { 1,3,5,9,1,8,2,3,2,7,0 };
    linkList.create(data, length);
    //打印
    linkList.print();
    //删除值最小结点
    LinkList_Delete_Min(linkList);
    //打印
    linkList.print();
    return 1;
}

//删除值最小结点
template<class ElemType>
void LinkList_Delete_Min(LNode<ElemType>& linkList) {
    LNode<ElemType>* pointPre = &linkList;
    LNode<ElemType>* point    = linkList.next;
    //指针不赋空值后面将无法使用
    //一开始写的是LNode<ElemType>* minPre = NULL;
    //遇到下面情况就会空指针，所以直接把头结点赋上就可以解决
    //{ 0,3,5,9,1,8,2,3,2,7,2 }
    LNode<ElemType>* minPointPre = &linkList;
    LNode<ElemType>* minPoint    = linkList.next;
    while (point) {
        if (point->data < minPoint->data) {
            minPoint    = point;
            minPointPre = pointPre;
        }
        pointPre = point;
        point    = point->next;
    }
    minPointPre->next = minPoint->next;
    free(minPoint);
}