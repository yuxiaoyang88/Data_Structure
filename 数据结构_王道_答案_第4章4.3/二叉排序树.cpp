#include <iostream>
#include <queue>
#include "二叉排序树.h"
using namespace std;

//书中原本insert只是插入一个结点，那不得写一片
bool BST_Insert(BiTree& tree, int a[], int length) {
    for (int i = 0; i < length; i++) {
        BST_Insert_One_Node(tree, a[i]);
    }
    return true;
}
//就是插入一个结点
bool BST_Insert_One_Node(BiTree& node, int x) {
    if (node == NULL) {
        //因为使用了引用，而传入的是一个指针
        //这里会改变上一个node指针指向
        //我们并不知道上一个node的指针是左还是右
        //只知道如果你为NULL，我就可以进行改变
        node              = (BitNode*)malloc(sizeof(BitNode));
        node->data        = x;
        node->left_child  = NULL;
        node->right_child = NULL;
    }
    if (x < node->data) {
        BST_Insert_One_Node(node->left_child, x);
    }
    if (x > node->data) {
        BST_Insert_One_Node(node->right_child, x);
    }
    return true;
}
//前序遍历整洁版
void BST_PreOrderFormat(BiTree& tree) {
    cout << "前序遍历为：";
    BST_PreOrder(tree);
    cout << endl;
}
//中序遍历整洁版
void BST_InOrderFormat(BiTree& tree) {
    cout << "中序遍历为：";
    BST_InOrder(tree);
    cout << endl;
}
//后序遍历整洁版
void BST_PostOrderFormat(BiTree& tree) {
    cout << "后序遍历为：";
    BST_PostOrder(tree);
    cout << endl;
}
//层次遍历整洁版
void BST_LevelOrderFormat(BiTree& tree) {
    cout << "层次遍历为：";
    BiTree        node = NULL;
    queue<BiTree> queue;
    queue.push(tree);
    while (!queue.empty()) {
        // stl就是这么规定的，一句话硬生生写成两句话
        // 返回队首元素的值，但不删除该元素
        node = queue.front();
        //删除队列首元素但不返回其值
        queue.pop();
        cout << node->data << " ";
        if (node->left_child != NULL) {
            queue.push(node->left_child);
        }
        if (node->right_child != NULL) {
            queue.push(node->right_child);
        }
    }
}
//前序遍历
void BST_PreOrder(BiTree& tree) {
    if (tree != NULL) {
        cout << tree->data << " ";
        BST_PreOrder(tree->left_child);
        BST_PreOrder(tree->right_child);
    }
}
//中序遍历
void BST_InOrder(BiTree& tree) {
    if (tree != NULL) {
        BST_InOrder(tree->left_child);
        cout << tree->data << " ";
        BST_InOrder(tree->right_child);
    }
}
//后序遍历
void BST_PostOrder(BiTree& tree) {
    if (tree != NULL) {
        BST_PostOrder(tree->left_child);
        BST_PostOrder(tree->right_child);
        cout << tree->data << " ";
    }
}
