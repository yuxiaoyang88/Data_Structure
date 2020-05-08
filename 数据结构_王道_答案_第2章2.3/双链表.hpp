#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "打印.hpp"
#endif
using namespace std;

template<class ElemType>
struct DNode {
    ElemType                data;
    struct DNode<ElemType>* prior;
    struct DNode<ElemType>* next;

public:
    //初始化
    void create(ElemType data[], int length);
    //打印
    void print() const;
};

//初始化
template<class ElemType>
void DNode<ElemType>::create(ElemType data[], int length) {
    DNode<ElemType>* point = this;
    for (int i = 0; i < length; i++) {
        DNode<ElemType>* nextDNode =
                (DNode<ElemType>*)malloc(sizeof(DNode<ElemType>));
        nextDNode->data  = data[i];
        nextDNode->prior = point;
        nextDNode->next  = NULL;
        point->next      = nextDNode;
        point            = point->next;
    }
    point->next = this;
    this->prior = point;
}

//打印
template<class ElemType>
void DNode<ElemType>::print() const {
    DNode<ElemType>* point = this->next;
    if (!point) {
        cout << "双链表没有任何元素" << endl << endl;
        return;
    }
    vector<PrintData<ElemType>> v;
    int                         i = 0;
    while (point != this) {
        PrintData<ElemType> printData{i, point->data};
        v.push_back(printData);
        i++;
        point = point->next;
    }
    cout << "下标为：";
    //下面这一句我也不知道为啥要改成这个样子
    // missing 'typename' prior to dependent type name
    typename vector<PrintData<ElemType>>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << to_string((*it).index) << " ";
        if (((*it).minus) < 0) {
            for (int j = 0; j < abs((*it).minus); j++) {
                cout << " ";
            }
        }
    }
    cout << endl;
    cout << "内容为：";
    for (it = v.begin(); it != v.end(); it++) {
        cout << (*it).data << " ";
        if ((*it).minus > 0) {
            for (int j = 0; j < (*it).minus; j++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;
}