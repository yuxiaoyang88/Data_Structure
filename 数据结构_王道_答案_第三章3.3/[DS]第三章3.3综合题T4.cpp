#include <iostream>
#include "循环队列.h"
using namespace std;

//这是上船方法
void CircularQueue_Go_Aboard(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck);
//上船方法调用了两个小方法
//一个是上客车，一个是上货车
void CircularQueue_Go_Aboard_Coach(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck);
void CircularQueue_Go_Aboard_Truck(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck);

void main3304() {
    //初始化队列
    //-------------------------------------------------------------------------
    //客车队列
    CircularQueue* queue_coach = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue_coach->front         = 0;
    queue_coach->rear          = 0;
    queue_coach->tag           = 0;
    for (int i = 1; i <= 17; i++) {
        CircularQueue_Push(*queue_coach, i);
    }
    /*cout << "队的front为" << queue_coach->front << endl;
    cout << "队的rear为" << queue_coach->rear << endl;
    cout << "队的tag为" << queue_coach->tag << endl;*/
    //货车队列
    CircularQueue* queue_truck = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue_truck->front         = 0;
    queue_truck->rear          = 0;
    queue_truck->tag           = 0;
    for (int i = 1; i <= 8; i++) {
        CircularQueue_Push(*queue_truck, i);
    }
    /*cout << "队的front为" << queue_truck->front << endl;
    cout << "队的rear为" << queue_truck->rear << endl;
    cout << "队的tag为" << queue_truck->tag << endl;*/
    //-------------------------------------------------------------------------
    /*CircularQueue_Show(*queue_coach);
    CircularQueue_Show(*queue_truck);*/

    while (!CircularQueue_Empty(*queue_coach) ||
           !CircularQueue_Empty(*queue_truck)) {
        CircularQueue_Go_Aboard(*queue_coach, *queue_truck);
    }
}

void CircularQueue_Go_Aboard(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck) {
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
void CircularQueue_Go_Aboard_Coach(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck) {
    //让客车出队
    int i = CircularQueue_Pop(queue_coach);
    // cout <<"asd"<< (i == NULL) << endl;
    if (i != NULL) {
        cout << "第" << i << "辆客车已上船" << endl;
    } else {
        //让货车替代出队
        i = CircularQueue_Pop(queue_truck);
        // cout << "asdsssssss" << i << endl;
        if (i != NULL) {
            cout << "第" << i << "辆货车替代客车已上船" << endl;
        } else {
            cout << "没有车可以上船coach" << endl;
        }
    }
}
void CircularQueue_Go_Aboard_Truck(
        CircularQueue& queue_coach,
        CircularQueue& queue_truck) {
    //让货车出队
    int i = CircularQueue_Pop(queue_truck);
    if (i != NULL) {
        cout << "第" << i << "辆货车已上船" << endl;
    } else {
        //让客车替代出队
        i = CircularQueue_Pop(queue_coach);
        if (i != NULL) {
            cout << "第" << i << "辆客车替代货车已上船" << endl;
        } else {
            cout << "没有车可以上船truck" << endl;
        }
    }
}