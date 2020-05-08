#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "打印.hpp"
#endif
using namespace std;

template<class ElemType>
struct SqList {
    ElemType data[20];
    int      length;

public:
    //初始化
    void create(ElemType data[], int length);
    //打印
    void print() const;
};

//初始化
template<class ElemType>
void SqList<ElemType>::create(ElemType data[], int length) {
    //内存拷贝
    memcpy(this->data, data, sizeof(ElemType) * length);
    this->length = length;
}

//打印
template<class ElemType>
void SqList<ElemType>::print() const {
    int length = this->length;
    if (length == 0) {
        cout << "线性表没有任何元素" << endl;
        return;
    }
    vector<PrintData<ElemType>> v;
    for (int i = 0; i < length; i++) {
        PrintData<ElemType> printData{i, this->data[i]};
        v.push_back(printData);
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