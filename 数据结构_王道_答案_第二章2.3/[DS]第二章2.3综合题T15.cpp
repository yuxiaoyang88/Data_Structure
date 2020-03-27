#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Create_To_A(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB);

//这道题是和14题完全一样的做法
int main(int argc, char** argv) {
    //初始化linkListA和linkListB
    //初始化
    LNode<int> linkListA;
    const int  lengthA        = 5;
    int        dataA[lengthA] = {1, 3, 4, 6, 9};
    linkListA.create(dataA, lengthA);
    LNode<int> linkListB;
    const int  lengthB        = 5;
    int        dataB[lengthB] = {2, 3, 4, 5, 6};
    linkListB.create(dataB, lengthB);
    //打印
    linkListA.print();
    linkListB.print();
    //两个元素递增序列的单链表，找到共同元素重新插入回A链表
    LinkList_Create_To_A(linkListA, linkListB);
    //打印
    linkListA.print();
    return 1;
}

//两个元素递增序列的单链表，找到共同元素重新插入回A链表
template<class ElemType>
void LinkList_Create_To_A(
        LNode<ElemType>& linkListA,
        LNode<ElemType>& linkListB) {
    LNode<ElemType>* pointA = linkListA.next;
    LNode<ElemType>* pointB = linkListB.next;
    LNode<ElemType>* pointC = &linkListA;
    LNode<ElemType>* pointDelete;
    while (pointA && pointB) {
        //警告 C6001 使用未初始化的内存“* pointA”。
        //警告 C6001 使用未初始化的内存“* pointB”。
        //下面画了警告线不知道应该怎么改
        // Visual Studio下警告 C6001
        if (pointA->data < pointB->data) {
            //没用到的结点边看完就删了
            //感觉有点多次一举
            //看王道习题讲解看到别人能实现
            //自己也试了一下
            //如果觉得代码过于复杂
            //把pointDelete相关行删除即可
            pointDelete = pointA;
            pointA      = pointA->next;
            free(pointDelete);
        } else if (pointA->data > pointB->data) {
            pointDelete = pointB;
            pointB      = pointB->next;
            free(pointDelete);
        } else {
            pointC->next = pointA;
            pointC       = pointA;
            pointA       = pointA->next;
            pointDelete  = pointB;
            pointB       = pointB->next;
            free(pointDelete);
            //这一步是为了防范下面情况
            //下标为：0 1 2 3
            //内容为：3 4 6 9
            //多出了9
            pointC->next = NULL;
        }
    }
    // free掉元素之后
    //指向该元素的指针变为野指针
    //需要置为空
    linkListB.next = NULL;
}