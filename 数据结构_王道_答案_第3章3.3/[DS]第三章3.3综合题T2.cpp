#include <iostream>
#include "顺序栈.hpp"
using namespace std;

//将软座S排到硬座H前面去
void CharSqStack_Check_SH(char str[]);

int main(int argc, char** argv) {
    //假设软座硬座都恰好有20个
    //但是顺序是随机的
    char str[] = "HSSSHSSHSHHHSSSHHSHHSSSHHSHHSSSHHHHSSHSH";
    CharSqStack_Check_SH(str);
    return 1;
}
//如果是硬座先压入栈中
//软座直接上车
//栈也可以用队列替换
//队列更好一些，因为先进先出
void CharSqStack_Check_SH(char str[]) {
    int           i = 0;
    int           j = 0;
    SqStack<char> stack;
    while (str[i] != '\0') {
        if (str[i] == 'S') {
            cout << i << "是软座，请您上车。" << j << endl;
            j++;
        }
        if (str[i] == 'H') {
            stack.push(str[i]);
        }
        i++;
    }
    int  k = 0;
    char x;
    while (!stack.isEmpty()) {
        stack.getTop(x);
        stack.pop();
        cout << x << "是硬座，请您上车。" << k << endl;
        k++;
    }
}