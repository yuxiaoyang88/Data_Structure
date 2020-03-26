#include <iostream>
#include "线性表.hpp"
using namespace std;

void SqList_Del_X_Y(SqList<int>& list, int x, int y);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length = 9;
    //这道题题目要求有序顺序表
    int data[length] = {1, 1, 3, 3, 3, 4, 6, 7, 9};
    list.create(data, length);
    //打印
    list.print();
    //删除所有值在[3,6]的元素
    SqList_Del_X_Y(list, 3, 6);
    //打印
    list.print();
    return 1;
}

void SqList_Del_X_Y(SqList<int>& list, int x, int y) {
    int pos = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] > y || list.data[i] < x) {
            list.data[pos] = list.data[i];
            pos++;
        }
    }
    list.length = pos;
}