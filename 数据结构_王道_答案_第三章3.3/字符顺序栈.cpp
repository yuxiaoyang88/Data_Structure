#include <iostream>
#include "字符顺序栈.h";
using namespace std;

//初始化
void CharSqStack_Init(CharSqStack& stack) {
    stack.top = -1;
}
//判栈空
bool CharSqStack_Empty(CharSqStack& stack) {
    if (stack.top == -1) {
        return true;
    } else {
        return false;
    }
}
//判栈满
bool CharSqStack_Overflow(CharSqStack& stack) {
    if (stack.top >= 19) {
        //栈满
        return true;
    } else {
        return false;
    }
}
//进栈
bool CharSqStack_Push(CharSqStack& stack, char x) {
    if (stack.top >= 19) {
        //栈满，不能进栈
        return false;
    } else {
        stack.top++;
        stack.data[stack.top] = x;
        return true;
    }
}
//出栈
bool CharSqStack_Pop(CharSqStack& stack, char& x) {
    if (stack.top == -1) {
        //栈空，不能出栈
        return false;
    } else {
        x = stack.data[stack.top];
        stack.top--;
        return true;
    }
}
//读取栈顶元素
bool CharSqStack_GetTop(CharSqStack& stack, char& x) {
    if (stack.top == -1) {
        //空栈，无可取元素
        return false;
    } else {
        x = stack.data[stack.top];
        return true;
    }
}
//打印栈
void CharSqStack_Show(CharSqStack& stack) {
    for (int i = stack.top; i >= 0; i--) {
        cout << "栈中第" << i << "层元素为--" << stack.data[i] << endl;
    }
}