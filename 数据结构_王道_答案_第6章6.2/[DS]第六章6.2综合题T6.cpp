#include <iostream>
using namespace std;

int BinSearchRec(int list[], int key, int low, int high);

int main(int argc, char** argv) {
    //题目中要求初始调用
    // low =1,high=8
    // data[0]=0;
    //其余分别为相应元素
    int data[9] = {0, 1, 3, 4, 5, 7, 11, 21, 30};
    BinSearchRec(data, 1, 1, 8);
    return 1;
}

int BinSearchRec(int array[], int key, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    cout << "low:" << low << endl;
    cout << "high:" << high << endl;
    cout << "mid:" << mid << endl;
    cout << "---------------------" << endl;
    if (key > array[mid]) {
        BinSearchRec(array, key, mid + 1, high);
    } else if (key < array[mid]) {
        BinSearchRec(array, key, low, mid - 1);
    } else {
        cout << "已找到元素，下标为：" << mid << endl;
        return mid;
    }
    // warning: non-void function does not return a value in all control paths
    // [-Wreturn-type]
    // warning: implicit conversion of NULL constant to 'int' 
    // [-Wnull-conversion]
    return -1;
}