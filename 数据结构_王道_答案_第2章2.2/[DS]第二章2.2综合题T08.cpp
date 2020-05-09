#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
void SqList_Reverse_Pro(SqList<ElemType>& list, int start, int length);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 11;
    int         data[length] = {5, 9, 1, 8, 2, 3, 2, 7, 6, 4, 16};
    list.create(data, length);
    //打印
    list.print();
    // A的长度为m = 7
    // B的长度为n = 4
    int length_A = 7;
    int length_B = 4;
    // 将所有元素逆置并打印
    SqList_Reverse_Pro(list, 0, length_A + length_B);
    list.print();
    // 将A的所有元素逆置并打印
    SqList_Reverse_Pro(list, 0, length_A);
    list.print();
    // 将B的所有元素逆置并打印
    SqList_Reverse_Pro(list, length_A, length_B);
    list.print();
    return 1;
}

template<class ElemType>
void SqList_Reverse_Pro(SqList<ElemType>& list, int start, int length) {
    int temp;
    //注意start + length / 2
    //注意<号
    for (int i = start; i < start + length / 2; i++) {
        temp = list.data[i];
        // start + length - 1 是最后一个元素的位置
        // i - start 是交换时，i相对于开始元素的偏移
        // 下标为i的元素需要与下标为X元素交换，X为
        // (start + length - 1) - (i - start) = start * 2 + length - i - 1
        list.data[i] = list.data[start * 2 + length - i - 1];
        list.data[start * 2 + length - i - 1] = temp;
    }
}