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
    //入队
    for (int i = 0; i < 10; i++) {
        EnQueue(stackA, stackB, i);
    }
    //打印
    stackA.print();
    stackB.print();
    int x;
    //出队
    for (int i = 0; i < 10; i++) {
        DeQueue(stackA, stackB, x);
        cout << "拿出的元素为:" << x << endl;
    }
    //打印
    stackA.print();
    stackB.print();
    return 1;
}
//入队
template<class ElemType>
bool EnQueue(SqStack<ElemType>& stackA, SqStack<ElemType>& stackB, int x) {
    // 先前我使用的判定条件为 
    // 如果A栈满了，但B栈满了，不做任何处理
    // if (stackA.isFull() && stackB.isFull()) {}
    // 我想到了一种情况，能够导致bug
    // 答案中我默认使用stackA和stackB的容量为5
    // 队列压入9个元素，拿出2个元素，再压入1个元素
    // 此时stackB非空未满，stackA满了，不会触发两个if条件
    // 再次压入一个元素，stackA满了，肯定压不进去
    // 会stackA.push(x);并return true;
    // 这样是不对的，因而我把它改变成了下面这样
    // 虽然会缩短队列容量，但不会引发错误
    // stackA中元素必须一次性全部压入stackB
    // 才能保证队列的性质
    if (stackA.isFull() && !stackB.isEmpty()) {
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
    x = stackB.getTop();
    stackB.pop();
    // warning: non-void function does not return a value in all control paths
    // [-Wreturn-type]
    return true;
}