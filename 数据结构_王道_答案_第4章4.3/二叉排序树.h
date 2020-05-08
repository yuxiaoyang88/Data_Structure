typedef struct BitNode {
    int      data;
    BitNode* left_child;
    BitNode* right_child;
} BitNode, *BiTree;

//书中原本insert只是插入一个结点，那不得写一片
bool BST_Insert(BiTree& tree, int a[], int length);
//就是插入一个结点
bool BST_Insert_One_Node(BiTree& node, int x);
//前序遍历整洁版
void BST_PreOrderFormat(BiTree& tree);
//中序遍历整洁版
void BST_InOrderFormat(BiTree& tree);
//后序遍历整洁版
void BST_PostOrderFormat(BiTree& tree);
//层次遍历整洁版
void BST_LevelOrderFormat(BiTree& tree);
//前序遍历
void BST_PreOrder(BiTree& tree);
//中序遍历
void BST_InOrder(BiTree& tree);
//后序遍历
void BST_PostOrder(BiTree& tree);