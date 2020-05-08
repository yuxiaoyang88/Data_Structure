#include <iostream>
#include "顺序栈.h"
#include "二叉排序树.h"
using namespace std;
bool BST_PrintRoots(BiTree& root, int x);

SqStack sqstack;

void main4312() {
    //初始化
    BiTree tree   = NULL;
    int    a[]    = {40, 72, 38, 35, 67, 51, 90, 8, 55, 21};
    int    length = sizeof(a) / sizeof(a[0]);
    BST_Insert(tree, a, length);
    //遍历
    BST_PreOrderFormat(tree);
    BST_InOrderFormat(tree);
    BST_PostOrderFormat(tree);
    //因为BST_PrintRoots使用栈保存元素
    //因为方法本身是递归的，所以初始化栈的方法要放在外面
    //所以先初始化一下栈
    //最后再打印一下栈
    SqStack_Init(sqstack);
    BST_PrintRoots(tree, 51);
    SqStack_Show(sqstack);
}

bool BST_PrintRoots(BiTree& root, int x) {
    if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }
    if (BST_PrintRoots(root->left_child, x) ||
        BST_PrintRoots(root->right_child, x)) {
        //这样打印出来是逆序的
        //因为递归到最小结点才会打印
        //所以压入栈，搞成顺序的
        // cout << root->data << endl;
        SqStack_Push(sqstack, root->data);
        return true;
    }
    return false;
}