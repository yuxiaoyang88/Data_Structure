#include <iostream>
#include "循环队列.hpp"
using namespace std;

//这是上船方法
template<class ElemType>
void CircularQueue_Go_Aboard(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck);
//上船方法调用了两个小方法
//一个是上客车，一个是上货车
template<class ElemType>
void CircularQueue_Go_Aboard_Coach(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck);
template<class ElemType>
void CircularQueue_Go_Aboard_Truck(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck);

int main(int argc, char** argv) {
    //初始化队列
    //-------------------------------------------------------------------------
    //客车队列
    CircularQueue<int> queue_coach;
    for (int i = 1; i <= 17; i++) {
        queue_coach.offer(i);
    }
    /*cout << "队的front为" << queue_coach->front << endl;
    cout << "队的rear为" << queue_coach->rear << endl;
    cout << "队的tag为" << queue_coach->tag << endl;*/
    //货车队列
    CircularQueue<int> queue_truck;
    for (int i = 1; i <= 8; i++) {
        queue_truck.offer(i);
    }
    /*cout << "队的front为" << queue_truck->front << endl;
    cout << "队的rear为" << queue_truck->rear << endl;
    cout << "队的tag为" << queue_truck->tag << endl;*/
    //-------------------------------------------------------------------------
    /*CircularQueue_Show(*queue_coach);
    CircularQueue_Show(*queue_truck);*/
    while (!queue_coach.isEmpty() || !queue_truck.isEmpty()) {
        CircularQueue_Go_Aboard(queue_coach, queue_truck);
    }
    return 1;
}

template<class ElemType>
void CircularQueue_Go_Aboard(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck) {
    //上四辆客车，上一辆货车，循环两遍
    for (int i = 0; i < 2; i++) {
        CircularQueue_Go_Aboard_Coach(queue_coach, queue_truck);
        CircularQueue_Go_Aboard_Coach(queue_coach, queue_truck);
        CircularQueue_Go_Aboard_Coach(queue_coach, queue_truck);
        CircularQueue_Go_Aboard_Coach(queue_coach, queue_truck);
        CircularQueue_Go_Aboard_Truck(queue_coach, queue_truck);
    }
    cout << "这艘轮船已经装载好，启航" << endl;
    cout << "-------------------------------" << endl;
}

template<class ElemType>
void CircularQueue_Go_Aboard_Coach(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck) {
    //让客车出队
    int  i;
    bool result;
    queue_coach.peek(i);
    result = queue_coach.pull();
    // cout <<"asd"<< (i == NULL) << endl;
    if (result) {
        cout << "第" << i << "辆客车已上船" << endl;
    } else {
        //让货车替代出队
        queue_truck.peek(i);
        result = queue_truck.pull();
        // cout << "asdsssssss" << i << endl;
        if (result) {
            cout << "第" << i << "辆货车替代客车已上船" << endl;
        } else {
            cout << "没有车可以上船coach" << endl;
        }
    }
}

template<class ElemType>
void CircularQueue_Go_Aboard_Truck(
        CircularQueue<ElemType>& queue_coach,
        CircularQueue<ElemType>& queue_truck) {
    //让货车出队
    int  i;
    bool result;
    queue_truck.peek(i);
    result = queue_truck.pull();
    if (result) {
        cout << "第" << i << "辆货车已上船" << endl;
    } else {
        //让客车替代出队
        queue_coach.peek(i);
        queue_coach.pull();
        if (result) {
            cout << "第" << i << "辆客车替代货车已上船" << endl;
        } else {
            cout << "没有车可以上船truck" << endl;
        }
    }
}