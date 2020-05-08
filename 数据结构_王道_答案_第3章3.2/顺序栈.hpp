#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include "打印.hpp"
#endif
using namespace std;

template<class ElemType>
struct SqStack {
    int      size     = 0;  //当前栈中的元素个数
    int      capacity = 5;  //栈的容量，初始化时capacity比size大5
    ElemType data[5];

public:
    //初始化
    void create(ElemType data[], int length);
    //设置栈的容量
    bool setCapacity(int capacity);
    //进栈
    bool push(ElemType& x);
    //出栈
    bool pop();
    //判栈空
    bool isEmpty() const;
    //判栈满
    bool isFull() const;
    //读取栈顶元素
    //如果写为ElemType getTop() const;
    //则会存在return NULL;的情况
    //如果我们ElemType为int类型数据
    // int是不允许返回NULL的，只能返回数字
    //因此写成了这种拧巴的形式，可以避免NULL的错误
    bool getTop(ElemType& x) const;
    //打印
    void print() const;
};

//初始化
template<class ElemType>
void SqStack<ElemType>::create(ElemType data[], int length) {
    //内存拷贝
    memcpy(this->data, data, sizeof(ElemType) * length + 5);
    this->size     = length;
    this->capacity = length + 5;
}

//设置栈的容量
template<class ElemType>
bool SqStack<ElemType>::setCapacity(int capacity) {
    memcpy(this->data, this->data, sizeof(ElemType) * capacity);
    this->capacity = capacity;
    if (this->size > capacity) {
        this->size = capacity;
    }
}

//进栈
template<class ElemType>
bool SqStack<ElemType>::push(ElemType& x) {
    if (this->size >= this->capacity) {
        //栈满，不能进栈
        return false;
    } else {
        this->data[this->size] = x;
        this->size++;
        return true;
    }
}

//出栈
template<class ElemType>
bool SqStack<ElemType>::pop() {
    if (this->size == 0) {
        //栈空，不能出栈，返回一个空对象
        return false;
    } else {
        this->size--;
        return true;
    }
}

//判栈空
template<class ElemType>
bool SqStack<ElemType>::isEmpty() const {
    if (this->size == 0) {
        return true;
    } else {
        return false;
    }
}

//判栈满
template<class ElemType>
bool SqStack<ElemType>::isFull() const {
    if (this->size >= this->capacity) {
        //栈满
        return true;
    } else {
        return false;
    }
}

//读取栈顶元素
template<class ElemType>
bool SqStack<ElemType>::getTop(ElemType& x) const {
    if (this->size == 0) {
        //空栈，无可取元素
        return false;
    } else {
        x = this->data[this->size - 1];
        return true;
    }
}

//打印
template<class ElemType>
void SqStack<ElemType>::print() const {
    int length = this->size;
    if (length == 0) {
        cout << "顺序栈没有任何元素" << endl << endl;
        return;
    }
    vector<PrintData<ElemType>> v;
    for (int i = 0; i < length; i++) {
        PrintData<ElemType> printData{i, this->data[i]};
        v.push_back(printData);
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
        cout << (*it).data << " ";
        if ((*it).minus > 0) {
            for (int j = 0; j < (*it).minus; j++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;
}