#include <iostream>
#include "不带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
void LinkList_Del_X_Recursion(LNode<ElemType>& node, int x);

int main(int argc, char** argv) {
    //初始化
    LNode<int> node;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 1, 8, 2, 3, 2, 7, 2};
    node.create(data, length);
    //打印
    node.print();
    //递归删除值为2的元素
    LinkList_Del_X_Recursion(node, 2);
    //打印
    node.print();
    return 1;
}

//递归删除data为x的结点
template<class ElemType>
void LinkList_Del_X_Recursion(LNode<ElemType>& node, int x) {
    //定义一个指针，专门用来删除
    LNode<ElemType>* point = NULL;
    //这层if不能和上一层合并，如果上面为true
    //即lnode本身为空，lnode.next会报空指针
    if (node.next == NULL) {
        return;
    }
    //这个if是防止第一个元素满足的情况
    if (node.data == x) {
        node = *node.next;
    }
    if (node.next->data == x) {
        point = node.next;
        if (node.next->next) {
            node.next = node.next->next;
        } else {
            node.next = NULL;
        }
        free(point);
    }
    if (node.next) {
        LinkList_Del_X_Recursion(*node.next, 2);
    }
}