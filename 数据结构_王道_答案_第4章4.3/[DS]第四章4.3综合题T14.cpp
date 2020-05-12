#include <iostream>
#include <map>
#ifndef CircularQueue_H
#define CircularQueue_H
#include "循环队列.hpp"
#endif
#include "二叉排序树.hpp"
using namespace std;

template<class Elemtype>
void BST_xxx(BitNode<Elemtype>& tree);

template<class ElemType>
struct LevelNode {
    BitNode<ElemType>* bitnode;
    int                level;
};

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
    //使用
    BST_xxx(tree);
    return 1;
}

template<class Elemtype>
void BST_xxx(BitNode<Elemtype>& tree) {
    //队列用来层次遍历并记录高度
    LevelNode<Elemtype>* node =
            (LevelNode<Elemtype>*)malloc(sizeof(LevelNode<Elemtype>));
    node->bitnode = &tree;
    node->level   = 1;
    CircularQueue<LevelNode<Elemtype>*> queue;
    queue.offer(node);
    // Map用来计算哪一层元素最多
    // 当初使用map有点省力
    // 可以替换但语义容易更不清晰
    // 意思对了就好
    map<int, int> map;
    while (!queue.isEmpty()) {
        queue.peek(node);
        queue.pull();
        //插入map
        if (map[node->level] == NULL) {
            map[node->level] = 1;
        } else {
            map[node->level] = map[node->level] + 1;
        }
        cout << "第" << node->level << "层的" << node->bitnode->data << endl;
        if (node->bitnode->left_child != NULL) {
            LevelNode<Elemtype>* newnode =
                    (LevelNode<Elemtype>*)malloc(sizeof(LevelNode<Elemtype>));
            newnode->bitnode = node->bitnode->left_child;
            newnode->level   = node->level + 1;
            queue.offer(newnode);
        }
        if (node->bitnode->right_child != NULL) {
            LevelNode<Elemtype>* newnode =
                    (LevelNode<Elemtype>*)malloc(sizeof(LevelNode<Elemtype>));
            newnode->bitnode = node->bitnode->right_child;
            newnode->level   = node->level + 1;
            queue.offer(newnode);
        }
    }
    int level;
    int max = 0;
    for (int i = 1; map[i] != NULL; i++) {
        if (map[i] > max) {
            level = i;
            max   = map[i];
        }
    }
    cout << "第" << level << "层元素最多，有" << max << "个" << endl;
}