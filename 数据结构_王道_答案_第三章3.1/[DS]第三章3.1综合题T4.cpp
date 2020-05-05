#include <iostream>
using namespace std;

#include "带有头指针的单链表.hpp";
#include "顺序栈.h";

bool LinkList_DC(LinkList& linklist, int length);
//原题目中是判断字符中心对称
//我不仅要修改带有头指针的单链表，还要修改顺序栈
//所以最后还是使用了int类型
void main3104() {
    //创建单链表
    LinkList linkList = (LinkList)malloc(sizeof(LinkList));
    //赋初值
    // int data[10] = { 1,2,2,3,5,5,3,2,2,1 };
    int data[11] = {1, 2, 2, 3, 5, 6, 5, 3, 2, 2, 1};
    // int data[11] = { 1,2,2,3,4,6,5,3,2,2,1 };
    int length = sizeof(data) / sizeof(data[0]);
    createLinkList(linkList, data, length);
    //打印
    LNodeShow(linkList);
    cout << endl;
    //前面是有个length，那是赋初值
    //真正题目赋初值不包括在后面运算环节
    //再来一遍走个形式
    int  linkList_length = LinkList_Length(linkList);
    bool result          = LinkList_DC(linkList, linkList_length);
    cout << "LinkList是否对称：" << result << endl;
}

bool LinkList_DC(LinkList& linklist, int length) {
    LNode*   point   = linklist->next;
    SqStack* sqstack = (SqStack*)malloc(sizeof(SqStack));
    if (sqstack) {
        SqStack_Init(*sqstack);
    }
    for (int i = 0; i < length / 2; i++) {
        SqStack_Push(*sqstack, point->data);
        point = point->next;
    }
    if (length % 2 == 1) {
        point = point->next;
    }
    int SqStack_Top = NULL;
    while (point != NULL) {
        SqStack_Pop(*sqstack, SqStack_Top);
        cout << "线性表元素为：" << point->data << endl;
        cout << "出栈元素为：" << SqStack_Top << endl;
        if (SqStack_Top != point->data) {
            return false;
        }
        point = point->next;
    }
    return (SqStack_Empty(*sqstack) == true ? true : false);
}
