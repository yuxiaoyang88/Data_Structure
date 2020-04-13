#include <iostream>
#include "带有头指针的单链表.hpp"
using namespace std;

template<class ElemType>
int LinkList_Find_K(LNode<ElemType>& linkList, int k);

int main(int argc, char** argv) {
    //初始化
    LNode<int> linkList;
    const int  length       = 11;
    int        data[length] = {7, 10, 10, 21, 30, 42, 42, 42, 51, 51, 70};
    linkList.create(data, length);
    //打印
    linkList.print();
    //查找倒数第k个元素
    int result = LinkList_Find_K(linkList, 7);
    cout << "运算" << ((result == 1) ? "成功" : "失败") << endl;
    return 1;
}

//查找倒数第k个元素
template<class ElemType>
int LinkList_Find_K(LNode<ElemType>& linkList, int k) {
    LNode<ElemType>* targetPoint = &linkList;
    LNode<ElemType>* point       = linkList.next;
    //找到第k个指针
    int count = 0;
    while (count < k - 1 && point) {
        point = point->next;
        count++;
    }
    //如果找到第k个指针为空，则失败，返回0
    //有可能不到k即为空，同样失败，返回0
    if (point == NULL) {
        return 0;
    }
    while (point) {
        point       = point->next;
        targetPoint = targetPoint->next;
    }
    cout << "倒数第" << k << "个元素为：" << targetPoint->data << endl;
    return 1;
}