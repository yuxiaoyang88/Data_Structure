#include <iostream>
#include "循环队列.h"
using namespace std;
// tag=1为队满
// front是进入队列的第一个元素，也是出队的第一个元素
// rear是进入队列的最后一个元素，也是出队的最后一个元素

int main(int argc, char** argv) {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    CircularQueue_Init(*queue);
    for (int i = 0; i < 5; i++) {
        CircularQueue_Push(*queue, i);
    }
    cout << "队的front为" << queue->front << endl;
    cout << "队的rear为" << queue->rear << endl;
    cout << "队的tag为" << queue->tag << endl;
    for (int i = 0; i < 5; i++) {
        int x = CircularQueue_Pop(*queue);
        cout << "出队的元素为" << x << endl;
        CircularQueue_Show(*queue);
    }
    cout << "队的front为" << queue->front << endl;
    cout << "队的rear为" << queue->rear << endl;
    cout << "队的tag为" << queue->tag << endl;
    return 1;
}
