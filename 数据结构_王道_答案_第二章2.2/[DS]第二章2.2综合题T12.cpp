#include <iostream>
#include "线性表.hpp"
using namespace std;

int SqList_Get_Main_Element(SqList<int>& list);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 8;
    int         data[length] = {0, 5, 5, 5, 5, 7, 0, 5};
    list.create(data, length);
    //打印
    list.print();
    //获得两个序列合起来结果的主元素
    //但是实际操作中不需要将两个序列合起来
    int result = SqList_Get_Main_Element(list);
    cout << endl;
    cout << "主元素为：" << result << endl;
    return 1;
}

//这个也没有用到最省空间的算法，但是用这个算法答题快，只扣一分。

int SqList_Get_Main_Element(SqList<int>& list) {
    int* a = (int*)malloc(sizeof(int) * list.length);
    for (int i = 0; i < list.length; i++) {
        a[i] = 0;
    }
    int max = 0;
    // warning: implicit conversion of NULL constant to 'int'
    // [-Wnull-conversion]
    int num;
    for (int i = 0; i < list.length; i++) {
        *(a + list.data[i]) = *(a + list.data[i]) + 1;
        if (*(a + list.data[i]) > max) {
            max = *(a + list.data[i]);
            num = list.data[i];
            cout << "num:" << num << endl;
            cout << "max:" << max << endl;
        }
    }
    if (a[*(a + num)] > list.length / 2) {
        return num;
    } else {
        return -1;
    }
}
