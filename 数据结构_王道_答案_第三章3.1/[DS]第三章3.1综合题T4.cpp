#include <iostream>
#include "带有头指针的单链表.hpp"
#include "顺序栈.hpp"
using namespace std;

template<class ElemType>
bool LinkList_DC(LNode<ElemType>& linklist, int length);
//原题目中是判断字符中心对称
//我不仅要修改带有头指针的单链表，还要修改顺序栈
//所以最后还是使用了int类型
int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length = 11;
    // int data[10] = { 1,2,2,3,5,5,3,2,2,1 };
    int data[length] = {1, 2, 2, 3, 5, 6, 5, 3, 2, 2, 1};
    // int data[11] = { 1,2,2,3,4,6,5,3,2,2,1 };
    linkList.create(data, length);
    //打印
    linkList.print();

    //前面是有个length，那是赋初值
    //真正题目赋初值不包括在后面运算环节
    //再来一遍走个形式
    int  LinkList_Length = linkList.length();
    bool result          = LinkList_DC(linkList, LinkList_Length);
    cout << "LinkList是否对称：" << result << endl;
    return 1;
}

template<class ElemType>
bool LinkList_DC(LNode<ElemType>& linklist, int length) {
    LNode<ElemType>*  point = linklist.next;
    SqStack<ElemType> stack;
    for (int i = 0; i < length / 2; i++) {
        stack.push(point->data);
        point = point->next;
    }
    if (length % 2 == 1) {
        point = point->next;
    }
    ElemType Stack_Top_Element;
    while (point != NULL) {
        stack.getTop(Stack_Top_Element);
        stack.pop();
        cout << "线性表元素为：" << point->data << endl;
        cout << "出栈元素为：" << Stack_Top_Element << endl;
        if (Stack_Top_Element != point->data) {
            return false;
        }
        point = point->next;
    }
    return (stack.isEmpty() == true ? true : false);
}
