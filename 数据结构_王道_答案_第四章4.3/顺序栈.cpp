#include <iostream>
#include "顺序栈.h";
using namespace std;

//初始化
void SqStack_Init(SqStack& sqstack) {
    sqstack.top = -1;
}
//判栈空
bool SqStack_Empty(SqStack& sqstack) {
    if (sqstack.top == -1) {
        return true;
    } else {
        return false;
    }
}
//判栈满
bool SqStack_Overflow(SqStack& sqstack) {
    if (sqstack.top >= 19) {
        //栈满
        return true;
    } else {
        return false;
    }
}
//进栈
bool SqStack_Push(SqStack& sqstack, int x) {
    if (sqstack.top >= 19) {
        //栈满，不能进栈
        return false;
    } else {
        sqstack.top++;
        sqstack.data[sqstack.top] = x;
        return true;
    }
}
//出栈
bool SqStack_Pop(SqStack& sqstack, int& x) {
    if (sqstack.top == -1) {
        //栈空，不能出栈
        return false;
    } else {
        x = sqstack.data[sqstack.top];
        sqstack.top--;
        return true;
    }
}
//读取栈顶元素
bool SqStack_GetTop(SqStack& sqstack, int& x) {
    if (sqstack.top == -1) {
        //空栈，无可取元素
        return false;
    } else {
        x = sqstack.data[sqstack.top];
        return true;
    }
}
//打印栈
void SqStack_Show(SqStack& sqstack) {
    for (int i = sqstack.top; i >= 0; i--) {
        cout << "栈中第" << i << "层元素为--" << sqstack.data[i] << endl;
    }
}