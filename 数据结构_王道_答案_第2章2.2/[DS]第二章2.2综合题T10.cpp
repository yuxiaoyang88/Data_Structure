#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
void SqList_Reverse(
        SqList<ElemType>& list,
        int               start_position,
        int               end_position);
template<class ElemType>
void SqList_ALL(SqList<ElemType>& list, int length);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 10;
    int         data[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list.create(data, length);
    //打印
    list.print();
    //看题吧，不好写注释了。。
    SqList_ALL(list, 6);
    //打印
    list.print();
    return 1;
}

template<class ElemType>
void SqList_Reverse(
        SqList<ElemType>& list,
        int               start_position,
        int               end_position) {
    // warning: implicit conversion of NULL constant to 'int'
    // [-Wnull-conversion]
    int temp;
    for (int i = 0; i < (end_position - start_position + 1) / 2; i++) {
        int temp                      = list.data[start_position + i];
        list.data[start_position + i] = list.data[end_position - i];
        list.data[end_position - i]   = temp;
        cout << "list.data[i]:" << list.data[i] << endl;
        cout << "list.data[end_position - i]:" << list.data[end_position - i]
             << endl;
    }
}
//算法思想是
//逆序第一组
//逆序第二组
//逆序全部
//就可以做到交换
//离散数学的知识。。。留下了抠脚的眼泪
template<class ElemType>
void SqList_ALL(SqList<ElemType>& list, int length) {
    // length表示前多少个是一组
    // 0-5即表示前6个是一组
    /*SqList_Reverse(list, 0, 5);
    SqList_Reverse(list, 6, 9);
    SqList_Reverse(list, 0, 9);*/
    SqList_Reverse(list, 0, length - 1);
    SqList_Reverse(list, length, list.length - 1);
    SqList_Reverse(list, 0, list.length - 1);
    cout << endl;
}
