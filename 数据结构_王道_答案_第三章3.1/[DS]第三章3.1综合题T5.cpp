#include <iostream>
using namespace std;

//共享存储区的顺序栈本身就是个数组
// A从0向19方向存，B从19向0方向存
struct DoubleStack {
    int data[20];
    int topA;
    int topB;
};

// str是用来确定是存A还是B
bool DoubleStack_Push(DoubleStack& stack, int x, string str);
int  DoubleStack_Pop(DoubleStack& stack, string str);

int main(int argc, char** argv) {
    DoubleStack* stack = (DoubleStack*)malloc(sizeof(DoubleStack));
    stack->topA        = -1;
    stack->topB        = 20;
    for (int i = 0; i < 15; i++) {
        DoubleStack_Push(*stack, i, "A");
    }
    for (int i = 0; i < 10; i++) {
        DoubleStack_Push(*stack, i, "B");
    }
    cout << "拿出栈A的元素为：" << DoubleStack_Pop(*stack, "A") << endl;
    cout << "拿出栈A的元素为：" << DoubleStack_Pop(*stack, "A") << endl;
    cout << "拿出栈A的元素为：" << DoubleStack_Pop(*stack, "A") << endl;
    cout << "拿出栈B的元素为：" << DoubleStack_Pop(*stack, "B") << endl;
    cout << "拿出栈B的元素为：" << DoubleStack_Pop(*stack, "B") << endl;
    cout << "拿出栈B的元素为：" << DoubleStack_Pop(*stack, "B") << endl;
    return 1;
}

// str是用来确定是存A还是B
bool DoubleStack_Push(DoubleStack& stack, int x, string str) {
    //如果栈满就不能再向里面放元素了
    // A的栈顶后面就是B的栈顶
    if (stack.topA + 1 >= stack.topB) {
        return false;
    }
    if (str == "A") {
        stack.topA++;
        stack.data[stack.topA] = x;
    }
    if (str == "B") {
        stack.topB++;
        stack.data[stack.topB] = x;
    }
    return true;
}

int DoubleStack_Pop(DoubleStack& stack, string str) {
    //可以写成一个if，感觉更难理解一些
    // str == "A" && stack.topA == -1 || str == "B" && stack.topB == 20
    if (str == "A" && stack.topA == -1) {
        return NULL;
    }
    if (str == "B" && stack.topB == 20) {
        return NULL;
    }
    if (str == "A") {
        int x = stack.data[stack.topA];
        stack.topA--;
        return x;
    }
    if (str == "B") {
        int x = stack.data[stack.topB];
        stack.topB++;
        return x;
    }
    // warning: non-void function does not return a value in all control paths
    // [-Wreturn-type]
    return NULL;
}
