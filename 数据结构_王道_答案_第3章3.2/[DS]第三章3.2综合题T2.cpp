#include <iostream>
#include "顺序栈.hpp"
#include "循环队列.hpp"
using namespace std;

template<class ElemType>
void CircularQueue_Reverse(
        SqStack<ElemType>&       stack,
        CircularQueue<ElemType>& queue);

int main(int argc, char** argv) {
    //初始化
    //栈为空，帮助队列元素逆置
    SqStack<int>       stack;
    CircularQueue<int> queue;
    for (int i = 1; i <= 17; i++) {
        queue.offer(i);
    }
    //打印
    queue.print();
    CircularQueue_Reverse(stack, queue);
    //因为用的循环指针，front指针并不一定在0的位置
    //所以看到位置，不要太惊慌
    //那说明循环队列循环起来了鸭
    queue.print();
    return 1;
}
template<class ElemType>
void CircularQueue_Reverse(
        SqStack<ElemType>&       stack,
        CircularQueue<ElemType>& queue) {
    ElemType x;
    while (!queue.isEmpty()) {
        queue.peek(x);
        queue.pull();
        stack.push(x);
    }
    while (!stack.isEmpty()) {
        stack.getTop(x);
        stack.pop();
        queue.offer(x);
    }
}