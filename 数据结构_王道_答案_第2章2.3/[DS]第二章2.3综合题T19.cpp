#include <iostream>
#include "带有头指针的循环单链表.hpp"
using namespace std;

template<class ElemType>
void Circular_Delete_And_Print(LNode<ElemType>& circularLinkList);

//和第9题完全一样，单链表改为循环单链表
int main(int argc, char** argv) {
    //初始化
    LNode<int> circularLinkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 6, 8, 2, 3, 2, 7, 6};
    circularLinkList.create(data, length);
    //打印
    circularLinkList.print();
    //循环删除单链表元素，每次删除单链表最小元素
    Circular_Delete_And_Print(circularLinkList);
    return 1;
}
//循环删除单链表元素，每次删除单链表最小元素
template<class ElemType>
void Circular_Delete_And_Print(LNode<ElemType>& circularLinkList) {
    LNode<ElemType>* point          = NULL;
    LNode<ElemType>* deletePrePoint = NULL;
    LNode<ElemType>* deletePoint    = NULL;
    while (circularLinkList.next != &circularLinkList) {
        int min        = circularLinkList.next->data;
        point          = &circularLinkList;
        deletePrePoint = &circularLinkList;
        deletePoint    = circularLinkList.next;
        while (point->next != &circularLinkList) {
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
        if (deletePoint->next != &circularLinkList) {
            deletePrePoint->next = deletePoint->next;
        } else {
            deletePrePoint->next = &circularLinkList;
        }
        free(deletePoint);
        cout << endl;
        circularLinkList.print();
        deletePrePoint = NULL;
        deletePoint    = NULL;
        point          = &circularLinkList;
    }
    //在这里调用会报错，跟作为传入参数有点关系，具体不清楚
    // free(linkList);
}