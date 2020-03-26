#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Delete_The_Absolute_Same(LNode<ElemType>& linkList, int n);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 51, 70};
    linkList.create(data, length);
    //打印
    linkList.print();
    //删除绝对值重复的结点
    LinkList_Delete_The_Absolute_Same(linkList, 70);
    //打印
    linkList.print();
    return 1;
}

//删除绝对值重复的结点
template<class ElemType>
void LinkList_Delete_The_Absolute_Same(LNode<ElemType>& linkList, int n) {
    LNode<ElemType>* point    = &linkList;
    LNode<ElemType>* delPoint = NULL;
    ElemType*        array    = (ElemType*)malloc(sizeof(ElemType) * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        //这个特殊用法需要题目中的条件
        // data的绝对值<=n
        //先有条件，后有用法。没有这个条件，用法完全不成立。
        //一看到条件，就应该想到这种用法
        *(array + i) = 0;
    }
    int value = NULL;
    while (point->next != NULL) {
        // value太长导致不好看
        value =
                (point->next->data > 0 ? point->next->data
                                       : -point->next->data);
        if (*(array + value) == 0) {
            *(array + value) = 1;
            point            = point->next;
        } else {
            delPoint    = point->next;
            point->next = delPoint->next;
            free(delPoint);
        }
    }
}
