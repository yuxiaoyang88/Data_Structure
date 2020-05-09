#include <iostream>
using namespace std;

//共享存储区的顺序栈本身就是个数组
// A从0向19方向存，B从19向0方向存
template<class ElemType>
struct SqStack {
    ElemType data[20];
    int      topA;
    int      topB;

public:
    // str是用来确定是存A还是B
    bool push(ElemType& x, string str);
    bool pop(ElemType& x, string str);
};

int main(int argc, char** argv) {
    SqStack<int> stack;
    stack.topA = -1;
    stack.topB = 20;
    for (int i = 0; i < 15; i++) {
        stack.push(i, "A");
    }
    for (int i = 0; i < 10; i++) {
        stack.push(i, "B");
    }
    int x;
    stack.pop(x, "A");
    cout << "拿出栈A的元素为：" << x << endl;
    stack.pop(x, "A");
    cout << "拿出栈A的元素为：" << x << endl;
    stack.pop(x, "A");
    cout << "拿出栈A的元素为：" << x << endl;
    stack.pop(x, "B");
    cout << "拿出栈B的元素为：" << x << endl;
    stack.pop(x, "B");
    cout << "拿出栈B的元素为：" << x << endl;
    stack.pop(x, "B");
    cout << "拿出栈B的元素为：" << x << endl;
    return 1;
}

// str是用来确定是存A还是B
template<class ElemType>
bool SqStack<ElemType>::push(ElemType& x, string str) {
    //如果栈满就不能再向里面放元素了
    // A的栈顶后面就是B的栈顶
    if (this->topA + 1 >= this->topB) {
        return false;
    }
    if (str == "A") {
        this->topA++;
        this->data[this->topA] = x;
    }
    if (str == "B") {
        this->topB++;
        this->data[this->topB] = x;
    }
    return true;
}

template<class ElemType>
bool SqStack<ElemType>::pop(ElemType& x, string str) {
    //可以写成一个if，感觉更难理解一些
    // str == "A" && stack.topA == -1 || str == "B" && stack.topB == 20
    if (str == "A" && this->topA == -1) {
        return false;
    }
    if (str == "B" && this->topB == 20) {
        return false;
    }
    if (str == "A") {
        x = this->data[this->topA];
        this->topA--;
        return true;
    }
    if (str == "B") {
        x = this->data[this->topB];
        this->topB++;
        return true;
    }
    // warning: non-void function does not return a value in all control paths
    // [-Wreturn-type]
    return false;
}
