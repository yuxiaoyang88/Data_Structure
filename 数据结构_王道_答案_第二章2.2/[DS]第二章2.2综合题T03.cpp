#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
void SqList_Del_X(SqList<ElemType>& list, int x);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 9;
    int         data[length] = {5, 9, 1, 8, 2, 3, 2, 7, 6};
    list.create(data, length);
    //打印
    list.print();
    //删除所有值为2的元素
    SqList_Del_X(list, 2);
    //打印
    list.print();
    return 1;
}

template<class ElemType>
void SqList_Del_X(SqList<ElemType>& list, int x) {
    int pos = 0;
    for (int i = 1; i < list.length; i++) {
        if (list.data[i] != x) {
            pos++;
            list.data[pos] = list.data[i];
        }
    }
    list.length = pos + 1;
}