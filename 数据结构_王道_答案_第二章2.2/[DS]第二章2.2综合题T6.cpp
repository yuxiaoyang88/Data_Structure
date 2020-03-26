#include <iostream>
#include "线性表.hpp"
using namespace std;

bool SqList_Del_Same(SqList<int>& list);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 9;
    int         data[length] = {1, 2, 2, 2, 4, 5, 6, 7, 7};
    list.create(data, length);
    //打印
    list.print();
    //删除重复元素
    SqList_Del_Same(list);
    //打印
    list.print();
    return 1;
}

bool SqList_Del_Same(SqList<int>& list) {
    if (list.length == 0) {
        return false;
    }
    int i = 0;
    for (int j = 0; j < list.length; j++) {
        if (list.data[j] != list.data[i]) {
            i            = i + 1;
            list.data[i] = list.data[j];
        }
    }
    list.length = i + 1;
    return true;
}