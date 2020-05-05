#include <iostream>
using namespace std;
bool Stack_Judge(char str[], int length);

int main(int argc, char** argv) {
    char str1[]      = "IOIIOIOO";
    char str2[]      = "IOOIOIOO";
    char str3[]      = "IIIOIOIO";
    char str4[]      = "IIIOOIOO";
    int  length_str1 = sizeof(str1) / sizeof(str1[0]);
    int  length_str2 = sizeof(str2) / sizeof(str2[0]);
    int  length_str3 = sizeof(str3) / sizeof(str3[0]);
    int  length_str4 = sizeof(str4) / sizeof(str4[0]);
    bool result1     = Stack_Judge(str1, length_str1);
    cout << result1 << endl;
    bool result2 = Stack_Judge(str2, length_str2);
    cout << result2 << endl;
    bool result3 = Stack_Judge(str3, length_str3);
    cout << result3 << endl;
    bool result4 = Stack_Judge(str4, length_str4);
    cout << result4 << endl;
    return 1;
}

bool Stack_Judge(char str[], int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == 'I') {
            count++;
        }
        if (str[i] == 'O') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    if (count == 0) {
        return true;
    } else {
        return false;
    }
}
