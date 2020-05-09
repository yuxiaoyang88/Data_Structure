#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "打印.hpp"
#endif
#include "循环队列.hpp"
using namespace std;

template<class ElemType>
struct BitNode {
    ElemType data = NULL;
    BitNode* left_child;
    BitNode* right_child;

public:
    // 插入一个结点
    bool insert(ElemType& x);
    // 插入一些结点
    bool create(ElemType a[], int length);
    // 前序遍历
    void preOrder();
    // 中序遍历
    void inOrder();
    // 后序遍历
    void postOrder();
};

// 插入一个结点
template<class ElemType>
bool BitNode<ElemType>::insert(ElemType& x) {
    if (!this->data) {
        cout << "asd" << endl;
        //因为使用了引用，而传入的是一个指针
        //这里会改变上一个node指针指向
        //我们并不知道上一个node的指针是左还是右
        //只知道如果你为NULL，我就可以进行改变
        this->data        = x;
        this->left_child  = NULL;
        this->right_child = NULL;
    }
    if (x < this->data) {
        if (this->left_child) {
            (*this->left_child).insert(x);
        } else {
            BitNode<ElemType> node;
            node.data        = x;
            node.left_child  = NULL;
            node.right_child = NULL;
            this->left_child = &node;
        }
    }
    if (x > this->data) {
        if (this->right_child) {
            (*this->right_child).insert(x);
        } else {
            BitNode<ElemType> node;
            node.data         = x;
            node.left_child   = NULL;
            node.right_child  = NULL;
            this->right_child = &node;
        }
    }
    return true;
}

//插入一些结点
template<class ElemType>
bool BitNode<ElemType>::create(ElemType a[], int length) {
    for (int i = 0; i < length; i++) {
        (*this).insert(a[i]);
    }
    return true;
}

// //前序遍历整洁版
// void BST_PreOrderFormat(BiTree& tree) {
//     cout << "前序遍历为：";
//     BST_PreOrder(tree);
//     cout << endl;
// }
// //中序遍历整洁版
// void BST_InOrderFormat(BiTree& tree) {
//     cout << "中序遍历为：";
//     BST_InOrder(tree);
//     cout << endl;
// }
// //后序遍历整洁版
// void BST_PostOrderFormat(BiTree& tree) {
//     cout << "后序遍历为：";
//     BST_PostOrder(tree);
//     cout << endl;
// }
// //层次遍历整洁版
// void BST_LevelOrderFormat(BiTree& tree) {
//     cout << "层次遍历为：";
//     BiTree        node = NULL;
//     queue<BiTree> queue;
//     queue.push(tree);
//     while (!queue.empty()) {
//         // stl就是这么规定的，一句话硬生生写成两句话
//         // 返回队首元素的值，但不删除该元素
//         node = queue.front();
//         //删除队列首元素但不返回其值
//         queue.pop();
//         cout << node->data << " ";
//         if (node->left_child != NULL) {
//             queue.push(node->left_child);
//         }
//         if (node->right_child != NULL) {
//             queue.push(node->right_child);
//         }
//     }
// }
// //前序遍历
// void BST_PreOrder(BiTree& tree) {
//     if (tree != NULL) {
//         cout << tree->data << " ";
//         BST_PreOrder(tree->left_child);
//         BST_PreOrder(tree->right_child);
//     }
// }
// //中序遍历
// void BST_InOrder(BiTree& tree) {
//     if (tree != NULL) {
//         BST_InOrder(tree->left_child);
//         cout << tree->data << " ";
//         BST_InOrder(tree->right_child);
//     }
// }
// //后序遍历
// void BST_PostOrder(BiTree& tree) {
//     if (tree != NULL) {
//         BST_PostOrder(tree->left_child);
//         BST_PostOrder(tree->right_child);
//         cout << tree->data << " ";
//     }
// }
