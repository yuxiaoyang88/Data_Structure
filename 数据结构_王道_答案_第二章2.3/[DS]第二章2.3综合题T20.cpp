#include <iostream>
using namespace std;

template<class ElemType>
struct DNode {
    ElemType      data;
    ElemType      freq;
    struct DNode* prior;
    struct DNode* next;

public:
    //初始化
    void create(ElemType data[], ElemType freq[], int length);
    //打印
    void print() const;
};

template<class ElemType>
DNode<ElemType>* DLinkList_Locate(DNode<ElemType>& dLinkList, int x);

int main(int argc, char** argv) {
    //初始化
    DNode<int> dLinkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 6, 8, 7, 4, 10, 12, 11};
    int        freq[length] = {50, 30, 20, 19, 18, 17, 16, 15, 14, 7, 5};
    dLinkList.create(data, freq, length);
    //打印
    dLinkList.print();
    //访问并增加频度，并按频度排序
    //题目中令频度值增加40
    //是为了好测试
    DNode<int>* point = DLinkList_Locate(dLinkList, 9);
    //打印
    dLinkList.print();
    cout << "data:" << point->data << "---"
         << "freq:" << point->freq << endl;
    return 1;
}
//初始化
template<class ElemType>
void DNode<ElemType>::create(ElemType data[], ElemType freq[], int length) {
    DNode<ElemType>* point = this;
    for (int i = 0; i < length; i++) {
        DNode<ElemType>* nextDNode =
                (DNode<ElemType>*)malloc(sizeof(DNode<ElemType>));
        nextDNode->data  = data[i];
        nextDNode->freq  = freq[i];
        nextDNode->prior = point;
        nextDNode->next  = NULL;
        point->next      = nextDNode;
        point            = point->next;
    }
}
//打印
//由于我写的打印本来就长
//在没有独立成hpp文件的情况下
//还是用最简单的print就好
template<class ElemType>
void DNode<ElemType>::print() const {
    DNode<ElemType>* point = this->next;
    while (point != NULL) {
        cout << "data:" << point->data << "---"
             << "freq:" << point->freq << endl;
        point = point->next;
    }
    cout << endl;
}
//访问并增加频度，并按频度排序
template<class ElemType>
DNode<ElemType>* DLinkList_Locate(DNode<ElemType>& dLinkList, int x) {
    DNode<ElemType>* point       = &dLinkList;
    DNode<ElemType>* targetPoint = NULL;
    while (point->next != NULL) {
        if (point->next->data == x) {
            targetPoint              = point->next;
            point->next->next->prior = point;
            point->next              = point->next->next;
            break;
        } else {
            point = point->next;
        }
    }
    // cout << targetPoint->data << "---" << targetPoint->freq << endl;
    targetPoint->freq = targetPoint->freq + 40;
    // cout << targetPoint->data << "---" << targetPoint->freq << endl;
    DNode<ElemType>* nodePoint = targetPoint;
    while (nodePoint->prior != &dLinkList) {
        if (nodePoint->prior->freq < targetPoint->freq) {
            nodePoint = nodePoint->prior;
            // cout << "aaaadata:" << nodePoint->data << "---" << "freq:" <<
            // nodePoint->freq << endl;
        } else {
            // cout << "XXXXdata:" << nodePoint->prior->data << "---" << "freq:"
            // << nodePoint->prior->freq << endl;
            targetPoint->next      = nodePoint;
            targetPoint->prior     = nodePoint->prior;
            nodePoint->prior->next = targetPoint;
            nodePoint->prior       = targetPoint;
            break;
        }
    }
    if (nodePoint->prior == &dLinkList) {
        targetPoint->next      = nodePoint;
        targetPoint->prior     = nodePoint->prior;
        nodePoint->prior->next = targetPoint;
        nodePoint->prior       = targetPoint;
    }
    return targetPoint;
}