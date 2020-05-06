#include <iostream>
#include "顺序栈.hpp"
using namespace std;

//入队
template<class ElemType>
bool EnQueue(SqStack<ElemType>& stackA, SqStack<ElemType>& stackB, int x);
//出队
template<class ElemType>
bool DeQueue(SqStack<ElemType>& stackA, SqStack<ElemType>& stackB, int& x);

int main(int argc, char** argv) {
    //初始化
    SqStack<int> stackA;
    SqStack<int> stackB;
    for (int i = 0; i < 10; i++) {
        EnQueue(stackA, stackB, i);
    }
    stackA.print();
    stackB.print();
    int x;
    for (int i = 0; i < 10; i++) {
        DeQueue(stackA, stackB, x);
        cout << "拿出的元素为:" << x << endl;
    }
    stackA.print();
    stackB.print();
    return 1;
}
//入队
template<class ElemType>
bool EnQueue(SqStack<ElemType>& stackA, SqStack<ElemType>& stackB, int x) {
    //如果A栈满了，但B栈满了，不做任何处理
    if (stackA.isFull() && stackB.isFull()) {
        return false;
    }
    //如果A栈满了，B栈为空，把A栈所有元素拿到B栈中，再从B栈拿出一个元素
    if (stackA.isFull() && stackB.isEmpty()) {
        ElemType element;
        while (!stackA.isEmpty()) {
            element = stackA.getTop();
            stackA.pop();
            stackB.push(element);
        }
    }
    stackA.push(x);
    return true;
}
//出队
template<class ElemType>
bool DeQueue(SqStack<ElemType>& stackA, SqStack<ElemType>& stackB, int& x) {
    //如果A栈和B栈没有元素，无返回
    if (stackA.isEmpty() && stackB.isEmpty()) {
        return false;
    }
    //如果A栈有元素，B栈为空，把A栈所有元素放在B栈里，再从B栈拿出一个元素
    if (!stackA.isEmpty() && stackB.isEmpty()) {
        ElemType element;
        while (!stackA.isEmpty()) {
            element = stackA.getTop();
            stackA.pop();
            stackB.push(element);
        }
    }
    // warning: non-void function does not return a value in all control paths
    // [-Wreturn-type]
    x = stackB.getTop();
    stackB.pop();
    return true;
}