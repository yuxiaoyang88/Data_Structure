#include <iostream>
#include "顺序栈.h";
using namespace std;

//入队
bool EnQueue(SqStack& stackA, SqStack& stackB, int x);
//出队
bool DeQueue(SqStack& stackA, SqStack& stackB, int& x);

int main(int argc, char** argv) {
    SqStack* sqstackA = (SqStack*)malloc(sizeof(SqStack));
    SqStack* sqstackB = (SqStack*)malloc(sizeof(SqStack));
    SqStack_Init(*sqstackA);
    SqStack_Init(*sqstackB);
    for (int i = 0; i < 30; i++) {
        EnQueue(*sqstackA, *sqstackB, i);
    }
    // SqStack_Show(*sqstackA);
    // SqStack_Show(*sqstackA);
    // cout << endl;
    // SqStack_Show(*sqstackB);
    // cout << endl;
    int x = NULL;
    for (int i = 0; i < 30; i++) {
        DeQueue(*sqstackA, *sqstackB, x);
        cout << "拿出的元素为:" << x << endl;
    }
    return 1;
}
//入队
bool EnQueue(SqStack& stackA, SqStack& stackB, int x) {
    //如果A栈不满，直接放进去就好
    if (!SqStack_Overflow(stackA)) {
        SqStack_Push(stackA, x);
        return true;
    }
    //如果A栈满了，但B栈非空（B栈不是满，但还有元素），不做任何处理
    if (SqStack_Overflow(stackA) && !SqStack_Empty(stackB)) {
        return false;
    }
    //如果A栈满了，B栈为空，把A栈所有元素拿到B栈中，再从B栈拿出一个元素
    if (SqStack_Overflow(stackA) && SqStack_Empty(stackB)) {
        int element = NULL;
        while (!SqStack_Empty(stackA)) {
            SqStack_Pop(stackA, element);
            SqStack_Push(stackB, element);
        }
    }
    SqStack_Push(stackA, x);
    return true;
}
//出队
bool DeQueue(SqStack& stackA, SqStack& stackB, int& x) {
    //如果B栈有元素，直接拿出来
    if (!SqStack_Empty(stackB)) {
        SqStack_Pop(stackB, x);
        return true;
    }
    //如果A栈和B栈没有元素，无返回
    if (SqStack_Empty(stackA) && SqStack_Empty(stackB)) {
        return false;
    }
    //如果A栈有元素，B栈为空，把A栈所有元素放在B栈里，再从B栈拿出一个元素
    if (!SqStack_Empty(stackA) && SqStack_Empty(stackB)) {
        int element = NULL;
        while (!SqStack_Empty(stackA)) {
            SqStack_Pop(stackA, element);
            SqStack_Push(stackB, element);
        }
        SqStack_Pop(stackB, element);
        return true;
    }
}