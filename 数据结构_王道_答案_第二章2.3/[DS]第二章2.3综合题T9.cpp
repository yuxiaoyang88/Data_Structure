#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Delete_And_Print(LNode<ElemType>& linkList);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkList.create(data, length);
    //打印
    linkList.print();
    LinkList_Delete_And_Print(linkList);
    return 1;
}

//循环删除单链表元素，每次删除单链表最小元素
template<class ElemType>
void LinkList_Delete_And_Print(LNode<ElemType>& linkList) {
    LNode<ElemType>* point          = NULL;
    LNode<ElemType>* deletePrePoint = NULL;
    LNode<ElemType>* deletePoint    = NULL;
    while (linkList.next != NULL) {
        int min        = linkList.next->data;
        point          = &linkList;
        deletePrePoint = &linkList;
        deletePoint    = linkList.next;
        while (point->next != NULL) {
            if (point->next->data < min) {
                min            = point->next->data;
                deletePrePoint = point;
                deletePoint    = point->next;
            }
            point = point->next;
        }
        cout << "删除最小的元素" << min << endl;

        // cout << "deletePrePoint" << deletePrePoint->data << endl;
        // cout << "deletePoint" << deletePoint->data << endl;
        // cout << "deletePoint->next" << deletePoint->next->data << endl;
        if (deletePoint->next != NULL) {
            deletePrePoint->next = deletePoint->next;
        } else {
            deletePrePoint->next = NULL;
        }
        free(deletePoint);
        linkList.print();
        deletePrePoint = NULL;
        deletePoint    = NULL;
        point          = &linkList;
    }
    //在这里调用会报错，跟作为传入参数有点关系，具体不清楚
    // free(linkList);
}
