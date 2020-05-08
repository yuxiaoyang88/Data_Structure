#include <iostream>
#include "顺序栈.hpp"
#include "循环队列.hpp"
using namespace std;

void CircularQueue_Reverse(SqStack& stack, CircularQueue& queue_coach);

int main(int argc, char** argv) {
    //初始栈，栈为空，帮助队列元素逆置
    SqStack* stack = (SqStack*)malloc(sizeof(SqStack));
    SqStack_Init(*stack);
    //初始化队列
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front         = 0;
    queue->rear          = 0;
    queue->tag           = 0;
    for (int i = 1; i <= 17; i++) {
        CircularQueue_Push(*queue, i);
    }
    //调用函数
    CircularQueue_Show(*queue);
    cout << endl;
    CircularQueue_Reverse(*stack, *queue);
    //因为用的循环指针，front指针并不一定在0的位置
    //所以看到位置，不要太惊慌
    //那说明循环队列循环起来了鸭
    CircularQueue_Show(*queue);
    return 1;
}

void CircularQueue_Reverse(SqStack& stack, CircularQueue& queue) {
    int x = NULL;
    while (!CircularQueue_Empty(queue)) {
        x = CircularQueue_Pop(queue);
        SqStack_Push(stack, x);
    }
    while (!SqStack_Empty(stack)) {
        SqStack_Pop(stack, x);
        CircularQueue_Push(queue, x);
    }
}