#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
LNode<ElemType>* LinkList_Break_down(LNode<ElemType>& linkListA);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkListA;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 6};
    linkListA.create(data, length);
    //打印linkListA
    cout << "linkListA为:" << endl;
    linkListA.print();
    //拆分链表，奇数留下，偶数分出去
    LNode<int>* linkListB = LinkList_Break_down(linkListA);
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
LNode<ElemType>* LinkList_Break_down(LNode<ElemType>& linkListA) {
    LNode<ElemType>* linkListB =
            (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
    LNode<ElemType>* pointA = &linkListA;
    LNode<ElemType>* pointB = linkListB;
    while (pointA->next) {
        if ((pointA->next->data) % 2 == 0) {
            //下面一句一定要先与第三句
            //第三句直接把pointA->next的赋值就给改了
            if (pointB) {
                pointB->next = pointA->next;
                pointB       = pointB->next;
            }
            //这里当时没有用指针pointB而用linkListB
            //最后导致linkListB为空
            //因为linkListB会被赋值成偶数最后元素的next指针指向的内存，也就是空
            //所以linkListB本身就是要指向一块固定的内存，然后通过指针才能够向后遍历
            pointA->next = pointA->next->next;
        } else {
            pointA = pointA->next;
        }
    }
    return linkListB;
}