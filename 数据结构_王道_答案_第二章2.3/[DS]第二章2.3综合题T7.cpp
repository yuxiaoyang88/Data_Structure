#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Delete_Between_X_Y(LNode<ElemType>& linkList, int x, int y);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkList.create(data, length);
    //打印
    linkList.print();
    //删除值为x到y之间的元素
    LinkList_Delete_Between_X_Y(linkList, 3, 5);
    //打印
    linkList.print();
    return 1;
}

//删除值为x到y之间的元素
template<class ElemType>
void LinkList_Delete_Between_X_Y(LNode<ElemType>& linkList, int x, int y) {
    LNode<ElemType>* prePoint    = &linkList;
    LNode<ElemType>* point       = linkList.next;
    LNode<ElemType>* deletePoint = NULL;
    while (point != NULL) {
        if (point->data >= x && point->data <= y) {
            prePoint->next = point->next;
            free(point);
            point = prePoint;
        } else {
            prePoint = point;
        }
        point = point->next;
    }
}
