#include <iostream>
#include "线性表.hpp"
using namespace std;

template<class ElemType>
int SqList_Find_Min(SqList<ElemType>& list);

int main(int argc, char** argv) {
    //初始化
    SqList<int> list;
    const int   length       = 4;
    int         data[length] = {4, 4, 4, 4};
    // int         data[length] = {1, 1, 1, 1};
    // int data[length] = {-5, -3, -2, 1};
    // int data[length] = {-5, 3, 4, 3};
    list.create(data, length);
    //打印
    list.print();
    //找出未出现的最小正整数
    int result = SqList_Find_Min(list);
    cout << "未出现的最小正整数为：" << result << endl;
    return 1;
}
//先遍历一遍数组
//求出非负的最大值和最小值
//如果最小值为1，那么未出现的最小正整数为（最大值+1）
//如果最小值>1，那么未出现的最小正整数为1
//这个算法的时间复杂度为O(n)，空间复杂度为O(1)
//这是最优解
template<class ElemType>
int SqList_Find_Min(SqList<ElemType>& list) {
    //求数组最大最小值
    // min要赋int最大值
    //这句话在考场上是一定写不出来的
    //私下可以研究一下
    int min = ((unsigned int)(-1)) >> 1;
    cout << "下面是如何推int最大值的过程" << endl;
    //求0111 1111(原码)
    // 0111 1111(原码) -> 1111 1111(原码) -> 1111 1111(补码) -> -1(真值)
    //逆过来就是求解过程
    //-1(真值) -> 1111 1111(补码) -> 1111 1111(原码) -> 0111 1111(原码)
    cout << hex << -1 << endl;
    cout << hex << (unsigned int)(-1) << endl;
    //(unsigned int)(-1) >> 1最外层加括号是因为cout语句
    cout << hex << ((unsigned int)(-1) >> 1) << endl;
    cout << "上面是如何推int最大值的过程" << endl;
    cout << endl;
    int max = 0;
    int value;
    for (int i = 0; i < list.length; i++) {
        value = list.data[i];
        if (value > max) {
            max = value;
        }
        if (value < min && value > 0) {
            min = value;
        }
    }
    //如果最小值为1，那么未出现的最小正整数为（最大值+1）
    //如果最小值>1，那么未出现的最小正整数为（最小值-1）
    // min的初值就设为1，结果只有min == 1和min > 1两种
    if (min == 1) {
        return max + 1;
    } else {
        return 1;
    }
}
// //下面是王道录像的做法，当时做题急没思路，就直接抄了但我想到了更好的做法
// //这个也没有用到最省空间的算法，但是用这个算法答题快，只扣一分。
// int SqList_Find_Min(SqList<int>& list) {
//     int max = list.data[0];
//     for (int i = 0; i < list.length; i++) {
//         if (list.data[i] > max) {
//             max = list.data[i];
//         }
//     }
//     //上面max是求数组中最大元素，便于下面malloc
//     int* a = (int*)malloc(sizeof(int) * max);
//     for (int i = 0; i < max; i++) {
//         a[i] = 0;
//     }
//     for (int i = 0; i < list.length; i++) {
//         if (list.data[i] > 0) {
//             a[list.data[i] - 1] = 1;
//         }
//     }
//     for (int i = 0; i < list.length; i++) {
//         cout << "第" << i << "个元素为：" << a[i] << endl;
//     }
//     int i = 0;
//     for (i = 0; i < max; i++) {
//         if (a[i] == 0) {
//             i = i + 1;
//             break;
//         }
//     }
//     return i;
// }
