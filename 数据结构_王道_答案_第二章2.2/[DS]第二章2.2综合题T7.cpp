#include <iostream>
#include "线性表.hpp"
using namespace std;

bool SqList_Merge(SqList<int> A, SqList<int> B, SqList<int>& C);

int main(int argc, char** argv) {
    //初始化A
    SqList<int> listA;
    const int   lengthA        = 4;
    int         dataA[lengthA] = {38, 45, 69, 1000};
    listA.create(dataA, lengthA);
    //打印A
    listA.print();
    //初始化B
    SqList<int> listB;
    const int   lengthB        = 3;
    int         dataB[lengthB] = {13, 27, 76};
    listB.create(dataB, lengthB);
    //打印B
    listB.print();
    //初始化C
    SqList<int> listC;
    //合并有序顺序表A和B，结果放在C中
    SqList_Merge(listA, listB, listC);
    //打印C
    listC.print();
    return 1;
}

bool SqList_Merge(SqList<int> A, SqList<int> B, SqList<int>& C) {
    C.length = A.length + B.length;
    int i    = 0;
    int j    = 0;
    int k    = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] < B.data[j]) {
            C.data[k] = A.data[i];
            k         = k + 1;
            i         = i + 1;
        } else {
            C.data[k] = B.data[j];
            k         = k + 1;
            j         = j + 1;
        }
    }
    while (i < A.length) {
        C.data[k] = A.data[i];
        k         = k + 1;
        i         = i + 1;
    }
    while (j < B.length) {
        C.data[k] = A.data[j];
        k         = k + 1;
        j         = j + 1;
    }
    return true;
}