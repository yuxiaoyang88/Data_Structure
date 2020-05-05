#include <iostream>
#include "循环队列.h";
using namespace std;

//初始化队
bool CircularQueue_Init(CircularQueue& queue) {
    queue.front = 0;
    queue.rear  = 0;
    queue.tag   = 0;
    return true;
}
//入队
bool CircularQueue_Push(CircularQueue& queue, int x) {
    //如果队满就不能入队了
    if (queue.front == queue.rear && queue.tag == 1) {
        return false;
    }
    queue.data[queue.rear] = x;
    queue.rear             = (queue.rear + 1) % 20;
    if (queue.front == queue.rear) {
        queue.tag = 1;
    }
    return true;
}
//出队
int CircularQueue_Pop(CircularQueue& queue) {
    //如果队空就不能出队了
    if (queue.front == queue.rear && queue.tag == 0) {
        return NULL;
    }
    int x       = queue.data[queue.front];
    queue.front = (queue.front + 1) % 20;
    if (queue.tag == 1) {
        queue.tag = 0;
    }
    return x;
}
//队空
bool CircularQueue_Empty(CircularQueue& queue) {
    if (queue.front == queue.rear && queue.tag == 0) {
        return true;
    } else {
        return false;
    }
}
//遍历
void CircularQueue_Show(CircularQueue& queue) {
    int i = queue.front;
    if (queue.front == queue.rear && queue.tag == 0) {
        cout << "队列中暂时没有元素" << endl;
    }
    while (i != queue.rear) {
        cout << "队列中第" << i << "个元素是" << queue.data[i] << endl;
        i = (i + 1) % 20;
    }
}
