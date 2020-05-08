#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
int SqList_Binary_Search(SqList<ElemType>& list, int x);
template<class ElemType>
void SqList_Search_Exchange_Insert(SqList<ElemType>& list, int x);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 10;
    int         data[length] = {4, 9, 12, 24, 38, 45, 69, 97, 120, 134};
    list.create(data, length);
    //打印
    list.print();
    //查询37
    //若在表中，将第一个与他后面一个元素交换
    //若没在表中，插入
    SqList_Search_Exchange_Insert(list, 37);
    //打印
    list.print();
    return 1;
}

template<class ElemType>
int SqList_Binary_Search(SqList<ElemType>& list, int x) {
    int low  = 0;
    int high = list.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x == list.data[mid]) {
            return mid;
        } else if (x > list.data[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

template<class ElemType>
void SqList_Search_Exchange_Insert(SqList<ElemType>& list, int x) {
    int position = SqList_Binary_Search(list, x);
    if (position != -1 && position != list.length - 1) {
        int tmp                 = list.data[position];
        list.data[position]     = list.data[position + 1];
        list.data[position + 1] = tmp;
    }
    //如果不存在这个数，就按序插入到数组里
    if (position == -1) {
        int i;
        for (i = list.length - 1; x < list.data[i]; i--) {
            list.data[i + 1] = list.data[i];
        }
        list.data[i + 1] = x;
        list.length      = list.length + 1;
    }
}