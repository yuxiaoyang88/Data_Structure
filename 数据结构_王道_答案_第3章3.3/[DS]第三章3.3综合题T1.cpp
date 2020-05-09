#include <iostream>
#include "顺序栈.hpp"
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
    SqStack<char> stack;
    int           i = 0;
    // warning: implicit conversion of NULL constant to 'char'
    // [-Wnull-conversion]
    // char value = NULL;
    char value;
    while (str[i] != '\0') {
        switch (str[i]) {
        case '(':
            stack.push(str[i]);
            break;
        case '[':
            stack.push(str[i]);
            break;
        case '{':
            stack.push(str[i]);
            break;
        case ')':
            stack.getTop(value);
            stack.pop();
            if (value != '(') {
                return false;
            }
            break;
        case ']':
            stack.getTop(value);
            stack.pop();
            if (value != '[') {
                return false;
            }
            break;
        case '}':
            stack.getTop(value);
            stack.pop();
            if (value != '{') {
                return false;
            }
            break;
        defalt:
            break;
        }
        i++;
    }
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
}
