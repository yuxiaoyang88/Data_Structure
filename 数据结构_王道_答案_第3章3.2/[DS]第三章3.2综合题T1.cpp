#include <iostream>
#include "循环队列.hpp"
using namespace std;
// tag=1为队满
// front是进入队列的第一个元素，也是出队的第一个元素
// rear是进入队列的最后一个元素，也是出队的最后一个元素

int main(int argc, char** argv) {
    //初始化
    CircularQueue<int> queue;
    for (int i = 0; i < 5; i++) {
        queue.offer(i);
    }
    //打印
    cout << "队的front为" << queue.front << endl;
    cout << "队的rear为" << queue.rear << endl;
    cout << "队的tag为" << queue.tag << endl;
    //出队观察front和rear的结果
    for (int i = 0; i < 5; i++) {
        int x;
        queue.peek(x);
        queue.pull();
        cout << "出队的元素为" << x << endl;
        queue.print();
    }
    //打印
    cout << "队的front为" << queue.front << endl;
    cout << "队的rear为" << queue.rear << endl;
    cout << "队的tag为" << queue.tag << endl;
    return 1;
}
