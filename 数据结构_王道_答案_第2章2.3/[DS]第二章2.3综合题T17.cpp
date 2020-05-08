#include <iostream>
#include "双链表.hpp"
using namespace std;

template<class ElemType>
bool DLinkList_Symmetry(DNode<ElemType>& dLinkList);

int main(int argc, char** argv) {
    //初始化
    DNode<int> dLinkList;
    const int  length       = 11;
    int        data[length] = {2, 3, 5, 9, 6, 8, 6, 9, 5, 3, 2};
    dLinkList.create(data, length);
    //打印
    dLinkList.print();
    //双链表是否对称
    bool result = DLinkList_Symmetry(dLinkList);
    cout << "双链表是否对称" << (result == true ? "true" : "false") << endl;
    return 1;
}

//双链表是否对称
template<class ElemType>
bool DLinkList_Symmetry(DNode<ElemType>& dLinkList) {
    DNode<ElemType>* prior = dLinkList.prior;
    DNode<ElemType>* next  = dLinkList.next;
    while (next != prior && next->next != prior) {
        if (prior->data == next->data) {
            cout << "prior:" << prior->data << endl;
            cout << "next:" << next->data << endl;
            prior = prior->prior;
            next  = next->next;
        } else {
            return false;
        }
    }
    return true;
}