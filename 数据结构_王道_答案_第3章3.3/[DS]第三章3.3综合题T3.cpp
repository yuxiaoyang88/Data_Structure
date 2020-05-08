#include <iostream>
using namespace std;

typedef struct {
    double data[20];
    int    top;
} DoubleSqStack;

// x是参数，n是栈的高度
double DoubleSqStack_Exercise(double x, int n);
//初始化
void DoubleSqStack_Init(DoubleSqStack& stack);
//进栈
bool DoubleSqStack_Push(DoubleSqStack& stack, double x);
//打印栈
void DoubleSqStack_Show(DoubleSqStack& stack);

void main3303() {
    double result = DoubleSqStack_Exercise(1.5, 20);
    cout << "最后的结果是：" << result << endl;
}

// x是参数，n是栈的高度
double DoubleSqStack_Exercise(double x, int n) {
    double fx0 = 1;
    double fx1 = 2 * x;
    //栈，先填入18个0，用来表示没有求得的元素
    //最后两个就是fx2和fx1
    DoubleSqStack* stack = (DoubleSqStack*)malloc(sizeof(DoubleSqStack));
    DoubleSqStack_Init(*stack);
    for (int i = 0; i < 18; i++) {
        DoubleSqStack_Push(*stack, 0);
    }
    DoubleSqStack_Push(*stack, fx1);
    DoubleSqStack_Push(*stack, fx0);
    // DoubleSqStack_Show(*stack);
    stack->top = 17;
    while (stack->top >= 0) {
        stack->data[stack->top] = 2 * x * fx1 - 2 * (19 - stack->top - 1) * fx0;
        cout << "2 * " << x << " * (" << fx1 << ") - 2 * "
             << 19 - stack->top - 1 << " * (" << fx0
             << ") = " << stack->data[stack->top] << endl;
        fx0 = fx1;
        fx1 = stack->data[stack->top];
        stack->top--;
    }
    return fx1;
}
//初始化
void DoubleSqStack_Init(DoubleSqStack& stack) {
    stack.top = -1;
}
//进栈
bool DoubleSqStack_Push(DoubleSqStack& stack, double x) {
    if (stack.top >= 19) {
        //栈满，不能进栈
        return false;
    } else {
        stack.top++;
        stack.data[stack.top] = x;
        return true;
    }
}
//打印栈
void DoubleSqStack_Show(DoubleSqStack& stack) {
    for (int i = stack.top; i >= 0; i--) {
        cout << "栈中第" << i << "层元素为--" << stack.data[i] << endl;
    }
}