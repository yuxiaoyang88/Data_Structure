#include <iostream>
#include "字符顺序栈.h"
using namespace std;

//检查表达式中括号是否配对
bool CharSqStack_Char_Check(char str[]);

int main(int argc, char** argv) {
    char str[]  = "{1+[2-(3+4)*5]/6}";
    bool result = CharSqStack_Char_Check(str);
    cout << "表达式是否配对：" << result << endl;
    return 1;
}

//检查表达式中括号是否配对
bool CharSqStack_Char_Check(char str[]) {
    CharSqStack* stack = (CharSqStack*)malloc(sizeof(CharSqStack));
    CharSqStack_Init(*stack);
    int  i     = 0;
    char value = NULL;
    while (str[i] != '\0') {
        switch (str[i]) {
        case '(':
            CharSqStack_Push(*stack, str[i]);
            break;
        case '[':
            CharSqStack_Push(*stack, str[i]);
            break;
        case '{':
            CharSqStack_Push(*stack, str[i]);
            break;
        case ')':
            CharSqStack_Pop(*stack, value);
            if (value != '(') {
                return false;
            }
            break;
        case ']':
            CharSqStack_Pop(*stack, value);
            if (value != '[') {
                return false;
            }
            break;
        case '}':
            CharSqStack_Pop(*stack, value);
            if (value != '{') {
                return false;
            }
            break;
        defalt:
            break;
        }
        i++;
    }
    if (CharSqStack_Empty(*stack)) {
        return true;
    } else {
        return false;
    }
}
