#include <iostream>
#include "线性表.hpp"
using namespace std;

void SqList_Reverse(SqList<int>& list);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 9;
    int         data[length] = {5, 9, 1, 8, 2, 3, 2, 7, 6};
    list.create(data, length);
    //打印
    list.print();
    //将所有元素逆置
    SqList_Reverse(list);
    //打印
    list.print();
    return 1;
}

void SqList_Reverse(SqList<int>& list) {
    int temp;
    for (int i = 0; i < list.length / 2; i++) {
        temp                           = list.data[i];
        list.data[i]                   = list.data[list.length - 1 - i];
        list.data[list.length - 1 - i] = temp;
    }
}