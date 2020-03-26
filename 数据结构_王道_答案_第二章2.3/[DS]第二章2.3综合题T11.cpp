#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
LNode<ElemType>* LinkList_Break_Down_Plus(LNode<ElemType>& linkListA);
//这道题是第十题的加强版
//第十题使用尾插法，这道题使用头插法
int main(int argc, char** argv) {
    //初始化
    LNode<int> linkListA;
    const int  length       = 11;
    int        data[length] = {0, 3, 5, 9, 1, 8, 2, 3, 2, 7, 2};
    linkListA.create(data, length);
    //打印linkListA
    cout << "linkListA为:" << endl;
    linkListA.print();
    //拆分链表，奇数留下，偶数分出去
    LNode<int>* linkListB = LinkList_Break_Down_Plus(linkListA);
    //打印linkListA
    cout << "linkListA为:" << endl;
    linkListA.print();
    //打印linkListB
    cout << "linkListB为:" << endl;
    (*linkListB).print();
    return 1;
}

//拆分链表，奇数留下，偶数分出去
template<class ElemType>
LNode<ElemType>* LinkList_Break_Down_Plus(LNode<ElemType>& linkListA) {
    LNode<ElemType>* linkListB =
            (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
    //这里如果不声明一下，linkListB->next默认不为NULL
    //构造出来的单链表是错误的
    if (linkListB) {
        linkListB->next = NULL;
    }
    LNode<ElemType>* pointA = &linkListA;
    LNode<ElemType>* pointB = linkListB;
    while (pointA->next != NULL) {
        if ((pointA->next->data) % 2 == 0) {
            //头插法还是非常恶心的
            //上面做不完，下面别开始
            //先做B再做A再做B再做B
            //先把pointA->next取出来，下句就开始修改了
            pointB = pointA->next;
            // pointA的next被取走了，把原有链破坏掉了
            //所以pointA->next的指向失效了
            //应该指向pointA->next->next;
            pointA->next = pointA->next->next;
            //
            //下句不能放在上句前，pointB->next实际上是pointA->next->next
            //上句不赋值，下句不修改
            if (linkListB) {
                pointB->next = linkListB->next;
                //上句不先把linkListB->next赋给pointB->next，下句就不能对其修改
                linkListB->next = pointB;
            }
        } else {
            pointA = pointA->next;
        }
    }
    return linkListB;
}