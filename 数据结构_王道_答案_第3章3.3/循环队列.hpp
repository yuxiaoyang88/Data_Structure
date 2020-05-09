#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "打印.hpp"
#endif
using namespace std;

template<class ElemType>
struct CircularQueue {
    ElemType data[20];
    int      front = 0;
    int      rear  = 0;
    int      tag   = 0;

public:
    //获取队列的头但不移除此队列的头
    bool peek(ElemType& x) const;
    //入队
    bool offer(ElemType& x);
    //出队
    bool pull();
    //判队空
    bool isEmpty() const;
    //打印
    void print() const;
};

//获取队列的头但不移除此队列的头
template<class ElemType>
bool CircularQueue<ElemType>::peek(ElemType& x) const {
    if (this->front == this->rear && this->tag == 0) {
        return false;
    }
    x = this->data[this->front];
    return true;
}

//入队
template<class ElemType>
bool CircularQueue<ElemType>::offer(ElemType& x) {
    //如果队满就不能入队了
    if (this->front == this->rear && this->tag == 1) {
        return false;
    }
    this->data[this->rear] = x;
    this->rear             = (this->rear + 1) % 20;
    if (this->front == this->rear) {
        this->tag = 1;
    }
    return true;
}
//出队
template<class ElemType>
bool CircularQueue<ElemType>::pull() {
    //如果队空就不能出队了
    if (this->front == this->rear && this->tag == 0) {
        return false;
    }
    this->front = (this->front + 1) % 20;
    if (this->tag == 1) {
        this->tag = 0;
    }
    return true;
}

//队空
template<class ElemType>
bool CircularQueue<ElemType>::isEmpty() const {
    if (this->front == this->rear && this->tag == 0) {
        return true;
    } else {
        return false;
    }
}

//打印
template<class ElemType>
void CircularQueue<ElemType>::print() const {
    if (this->front == this->rear && this->tag == 0) {
        cout << "队列中没有任何元素" << endl << endl;
        return;
    }
    int                         i = this->front;
    vector<PrintData<ElemType>> v;
    while (i != this->rear) {
        PrintData<ElemType> printData{i, this->data[i]};
        v.push_back(printData);
        i = (i + 1) % 20;
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