#include <iostream>
using namespace std;

int T0(int n);

int main(int argc, char** argv) {
    cout << T0(8) << endl;
    return 1;
}

int T0(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * T0(n / 2) + n;
    }
}