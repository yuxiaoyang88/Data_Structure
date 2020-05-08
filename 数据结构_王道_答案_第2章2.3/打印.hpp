#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//下面所有的代码都是为了友好的输出数组，不要再看了
//调用方式
// PrintData::print(数组, 数组长度);
template<class ElemType>
int getDigitCapacity(ElemType num);

template<class ElemType>
class PrintData {
public:
    int      index;
    ElemType data;
    int      minus;  // indexLength - dataLength

public:
    //构造函数
    PrintData(int index, ElemType data) : index(index), data(data) {
        minus = getDigitCapacity(index) - getDigitCapacity(data);
    }
};

//这个方法不能放在类中
//否则ElemType会随着类的ElemType而变化
//会影响构造函数中getDigitCapacity(index)的类型
template<class ElemType>
int getDigitCapacity(ElemType num) {
    //用cout的格式把ElemType转为string
    stringstream stream;
    string       str;
    stream << num;
    stream >> str;
    return str.length();
}