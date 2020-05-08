#include <iostream>
#include "顺序栈.hpp"
using namespace std;

// x是参数，n是栈的高度
double DoubleSqStack_Exercise(double x, int n);

int main(int argc, char** argv) {
    double result = DoubleSqStack_Exercise(1.5, 20);
    cout << "最后的结果是：" << result << endl;
    return 1;
}

// x是参数，n是栈的高度
double DoubleSqStack_Exercise(double x, int n) {
    double fx0 = 1;
    double fx1 = 2 * x;
    //栈，先填入18个0，用来表示没有求得的元素
    //最后两个就是fx2和fx1
    SqStack<double> stack;
    double          xx = 0.0;
    for (int i = 0; i < 18; i++) {
        stack.push(xx);
    }
    stack.push(fx1);
    stack.push(fx0);
    // stack.print();
    stack.size = 19;
    while (stack.size > 0) {
        stack.data[stack.size] = 2 * x * fx1 - 2 * (19 - stack.size - 1) * fx0;
        cout << "2 * " << x << " * (" << fx1 << ") - 2 * "
             << 19 - stack.size - 1 << " * (" << fx0
             << ") = " << stack.data[stack.size] << endl;
        fx0 = fx1;
        fx1 = stack.data[stack.size];
        stack.size--;
    }
    return fx1;
}
