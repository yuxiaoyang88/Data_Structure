#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
bool SqList_Del_S_T(SqList<ElemType>& list, int s, int t);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 9;
    int         data[length] = {5, 9, 1, 8, 2, 3, 2, 7, 6};
    list.create(data, length);
    //打印
    list.print();
    //删除2和6之间的所有元素
    SqList_Del_S_T(list, 2, 6);
    //打印
    list.print();
    return 1;
}

template<class ElemType>
bool SqList_Del_S_T(SqList<ElemType>& list, int s, int t) {
    if (list.length == 0 || s >= t) {
        return false;
    }
    int pos = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] > t || list.data[i] < s) {
            list.data[pos] = list.data[i];
            pos++;
        }
    }
    list.length = pos;
    return true;
}