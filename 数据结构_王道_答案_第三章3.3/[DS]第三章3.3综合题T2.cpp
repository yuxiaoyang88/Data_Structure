#include <iostream>
#include "字符顺序栈.h";
using namespace std;

//将软座S排到硬座H前面去
void CharSqStack_Check_SH(char str[]);

void main3302() {
    //假设软座硬座都恰好有20个
    //但是顺序是随机的
    char str[] = "HSSSHSSHSHHHSSSHHSHHSSSHHSHHSSSHHHHSSHSH";
    CharSqStack_Check_SH(str);
}
//如果是硬座先压入栈中
//软座直接上车
//栈也可以用队列替换
//队列更好一些，因为先进先出
void CharSqStack_Check_SH(char str[]) {
    int          i     = 0;
    int          j     = 0;
    CharSqStack* stack = (CharSqStack*)malloc(sizeof(CharSqStack));
    CharSqStack_Init(*stack);
    while (str[i] != '\0') {
        if (str[i] == 'S') {
            cout << i << "是软座，请您上车。" << j << endl;
            j++;
        }
        if (str[i] == 'H') {
            CharSqStack_Push(*stack, str[i]);
        }
        i++;
    }
    int  k = 0;
    char x = NULL;
    while (!CharSqStack_Empty(*stack)) {
        CharSqStack_Pop(*stack, x);
        cout << x << "是硬座，请您上车。" << k << endl;
        k++;
    }
}