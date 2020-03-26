#include <iostream>
#include "线性表.hpp"
using namespace std;

int SqList_Get_Mid(SqList<int>& sqlistA, SqList<int>& sqlistB);

int main(int argc, char** argv) {
    //留意以下写法，表示的意思是一样的
    // SqList<int>* sqlistA  = (SqList<int>*)malloc(sizeof(SqList<int>));
    //初始化A
    SqList<int> listA;
    const int   lengthA        = 5;
    int         dataA[lengthA] = {11, 13, 15, 17, 19};
    listA.create(dataA, lengthA);
    //打印A
    listA.print();
    //初始化B
    SqList<int> listB;
    const int   lengthB        = 5;
    int         dataB[lengthB] = {2, 4, 6, 8, 20};
    listB.create(dataB, lengthB);
    //打印B
    listB.print();
    //获得两个序列合起来结果的中位数
    //但是实际操作中不需要将两个序列合起来
    int result = SqList_Get_Mid(listA, listB);
    cout << endl;
    cout << "两序列的中位数为：" << result << endl;
    return 1;
}

//虽然方法省时间，但是算法本身并不能给出准确正确答案。。
//反倒是不省空间的那种先排序再找中位数能得出最正确的答案
//这道题不建议大家看
//把出现了的死循环用int resultA = NULL;和int resultB = NULL;排除掉了
//算法思路本身不会得到正确答案。但我还是沿着算法思路写出来了。
//讲到最后，能正确表述算法，算法本身是错的，所以不建议大家看，浪费时间。
//真的觉得老师有点无中生有，单纯为了这个算法本身而出题，忽视了一些给不出正确答案的可能性。
int SqList_Get_Mid(SqList<int>& sqlistA, SqList<int>& sqlistB) {
    int A_Low   = 0;
    int A_Hight = sqlistA.length;
    int A_Mid   = (A_Hight + A_Low) / 2;
    int B_Low   = 0;
    int B_Hight = sqlistB.length;
    int B_Mid   = (B_Hight + B_Low) / 2;
    // warning: implicit conversion of NULL constant to 'int'
    // [-Wnull-conversion]
    int resultA;
    int resultB;
    while ((A_Low != A_Hight) || (B_Low != B_Hight)) {
        int A_Mid = (A_Hight + A_Low) / 2;
        int B_Mid = (B_Hight + B_Low) / 2;
        cout << sqlistA.data[A_Mid] << "---" << sqlistB.data[B_Mid] << endl;
        if (resultA == A_Mid && resultB == B_Mid) {
            break;
        }
        if (sqlistA.data[A_Mid] < sqlistB.data[B_Mid]) {
            A_Low   = A_Mid;
            B_Hight = B_Mid;
        }
        if (sqlistB.data[B_Mid] < sqlistA.data[A_Mid]) {
            B_Low   = B_Mid;
            A_Hight = A_Mid;
        }
        if (sqlistB.data[B_Mid] == sqlistA.data[A_Mid]) {
            return sqlistA.data[A_Mid];
        }
        resultA = A_Mid;
        resultB = B_Mid;
    }
    return sqlistA.data[resultA] - sqlistB.data[resultB] > 0
            ? sqlistB.data[resultB]
            : sqlistA.data[resultA];
}
