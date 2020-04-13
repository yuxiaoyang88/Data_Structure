#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template<class ElemType>
struct LNode {
    ElemType data;
    LNode*   next;

public:
    //初始化
    void create(ElemType data[], int length);
    //打印
    void print() const;
};

template<class ElemType>
void LNode<ElemType>::create(ElemType data[], int length) {
    LNode<ElemType>* point = this;
    this->data             = data[0];
    this->next             = NULL;
    for (int i = 1; i < length; i++) {
        LNode<ElemType>* nextLNode =
                (LNode<ElemType>*)malloc(sizeof(LNode<ElemType>));
        nextLNode->data = data[i];
        nextLNode->next = NULL;
        point->next     = nextLNode;
        //警告 C28182：正在取消对 null 指针的引用。
        if (point) {
            point = point->next;
        }
    }
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
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
    // indexLength - dataLength
    int minus;

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

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
//打印
template<class ElemType>
void LNode<ElemType>::print() const {
    const LNode<ElemType>* point = this;
    if (!point) {
        cout << "单链表没有任何元素" << endl;
        return;
    }
    vector<PrintData<ElemType>> v;
    int                         i = 0;
    while (point) {
        PrintData<ElemType> printData{i, point->data};
        v.push_back(printData);
        i++;
        point = point->next;
    }
    cout << "下标为：";
    //下面这一句我也不知道为啥要改成这个样子
    // missing 'typename' prior to dependent type name
    typename vector<PrintData<ElemType>>::const_iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << to_string((*it).index) << " ";
        if (((*it).minus) < 0) {
            for (int j = 0; j < abs((*it).minus); j++) {
                cout << " ";
            }
        }
    }
    cout << endl;
    cout << "内容为：";
    for (it = v.begin(); it != v.end(); it++) {
        cout << to_string((*it).data) << " ";
        if ((*it).minus > 0) {
            for (int j = 0; j < (*it).minus; j++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;
}