#include <iostream>
#include "顺序栈.hpp"
#include "二叉排序树.hpp"
using namespace std;

template<class ElemType>
bool BST_PrintRoots(BitNode<ElemType>* node, int x, SqStack<ElemType>& stack);

int main(int argc, char** argv) {
    //初始化
    BitNode<int> tree;
    const int    length       = 10;
    int          data[length] = {40, 72, 38, 35, 67, 51, 90, 8, 55, 21};
    tree.create(data, length);
    //遍历
    tree.printPre();
    tree.printIn();
    tree.printPost();
    //因为BST_PrintRoots使用栈保存元素
    //因为方法本身是递归的，所以初始化栈的方法要放在外面
    //所以先初始化一下栈
    //最后再打印一下栈
    SqStack<int> stack;
    BST_PrintRoots(&tree, 51, stack);
    stack.print();
    return 1;
}

template<class ElemType>
bool BST_PrintRoots(BitNode<ElemType>* node, int x, SqStack<ElemType>& stack) {
    if (!node) {
        return false;
    }
    if (node->data == x) {
        return true;
    }
    if (BST_PrintRoots(node->left_child, x, stack) ||
        BST_PrintRoots(node->right_child, x, stack)) {
        //这样打印出来是逆序的
        //因为递归到最小结点才会打印
        //所以压入栈，搞成顺序的
        // cout << root->data << endl;
        stack.push(node->data);
        return true;
    }
    return false;
}