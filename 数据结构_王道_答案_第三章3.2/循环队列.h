struct CircularQueue {
    int data[20];
    int front;
    int rear;
    int tag;
};

//初始化队
bool CircularQueue_Init(CircularQueue& queue);
//入队
bool CircularQueue_Push(CircularQueue& queue, int x);
//出队
int CircularQueue_Pop(CircularQueue& queue);
//队空
bool CircularQueue_Empty(CircularQueue& queue);
//遍历
void CircularQueue_Show(CircularQueue& queue);
