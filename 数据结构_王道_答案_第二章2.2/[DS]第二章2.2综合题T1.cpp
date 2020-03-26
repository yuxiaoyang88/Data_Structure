#include <iostream>
#include "线性表.hpp"
using namespace std;

bool SqList_Del_Min(SqList<int>& list, int& value);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 8;
    int         data[length] = {5, 9, 1, 8, 3, 2, 7, 6};
    list.create(data, length);
    //打印
    list.print();
    // value用来返回最小值，使用了引用的方式
    //并将最后一个元素赋值到最小值位置上
    int value;
    SqList_Del_Min(list, value);
    cout << "最小值为：" << value << endl << endl;
    //打印
    list.print();
    return 1;
}

bool SqList_Del_Min(SqList<int>& list, int& value) {
    if (list.length == 0) {
        return false;
    }
    int pos = 0;
    value   = list.data[0];
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] < value) {
            value = list.data[i];
            pos   = i;
        }
    }
    //把那个删除掉的元素替换为最后一个元素
    //去掉C6385警告，加上if判断
    if (list.length - 1 >= 0 && list.length - 1 < 20) {
        list.data[pos] = list.data[list.length - 1];
    }
    list.length--;
    return true;
}
