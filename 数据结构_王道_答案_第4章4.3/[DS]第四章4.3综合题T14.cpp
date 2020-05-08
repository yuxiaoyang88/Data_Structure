#include <iostream>
#include <queue>
#include <map>
#include "二叉排序树.h"
using namespace std;
void BST_xxx(BiTree& tree);

struct LevelNode {
    BitNode* bitnode;
    int      level;
};

int main4314() {
    //初始化
    BiTree tree   = NULL;
    int    a[]    = {40, 72, 38, 35, 67, 51, 90, 8, 55, 21};
    int    length = sizeof(a) / sizeof(a[0]);
    BST_Insert(tree, a, length);
    //遍历
    BST_PreOrderFormat(tree);
    BST_InOrderFormat(tree);
    BST_PostOrderFormat(tree);
    //使用
    queue<LevelNode*> queue;
    BST_xxx(tree);
    return 1;
}

void BST_xxx(BiTree& tree) {
    //队列用来层次遍历并记录高度
    LevelNode* node = (LevelNode*)malloc(sizeof(LevelNode));
    node->bitnode   = tree;
    node->level     = 1;
    queue<LevelNode*> queue;
    queue.push(node);
    // Map用来计算哪一层元素最多
    map<int, int> map;
    while (!queue.empty()) {
        // stl就是这么规定的，一句话硬生生写成两句话
        // 返回队首元素的值，但不删除该元素
        node = queue.front();
        //删除队列首元素但不返回其值
        queue.pop();
        //插入map
        if (map[node->level] == NULL) {
            map[node->level] = 1;
        } else {
            map[node->level] = map[node->level] + 1;
        }
        cout << "第" << node->level << "层的" << node->bitnode->data << endl;
        if (node->bitnode->left_child != NULL) {
            LevelNode* newnode = (LevelNode*)malloc(sizeof(LevelNode));
            newnode->bitnode   = node->bitnode->left_child;
            newnode->level     = node->level + 1;
            queue.push(newnode);
        }
        if (node->bitnode->right_child != NULL) {
            LevelNode* newnode = (LevelNode*)malloc(sizeof(LevelNode));
            newnode->bitnode   = node->bitnode->right_child;
            newnode->level     = node->level + 1;
            queue.push(newnode);
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