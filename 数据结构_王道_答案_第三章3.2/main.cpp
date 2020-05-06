#include <iostream>
#include "顺序栈.hpp"
using namespace std;

int main(int argc, char** argv) {
    SqStack<int> stack;
    const int    length       = 8;
    int          data[length] = {5, 9, 1, 8, 3, 2, 7, 6};
    stack.create(data, length);
    stack.print();
    cout << stack.size << endl;
    cout << stack.capacity << endl;
    return 1;
}