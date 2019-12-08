//
// Created by HanLulu on 2019/10/16.
//

#ifndef DB_ORDERSTACK_HPP
#define DB_ORDERSTACK_HPP

#include <iostream>

using namespace std;

template<class T>
class OrderStack {
public:
    OrderStack(int v_cap = 10);

    ~OrderStack();

    bool IsEmpty() const {
        return top == -1;
    }

    T &Top() const {
        if (IsEmpty())
            throw "栈为空";
        return ptr[top];
    }

    void Push(const T &item);

    void Pop() {
        if (IsEmpty())
            throw "栈为空";
        ptr[top--].~T();
    }

    void recap(int rv_cap);

    int Size() {
        return top + 1;
    }

    int Cap() {
        return cap;
    }

    void Message() {
        cout << "开辟内存：" << sizeof(T) * cap << "字节；" << "已使用内存：" << sizeof(T) * (top + 1) << "字节" << endl;
    }

private:
    T *ptr;
    int top;
    int cap;
protected:
};

template<class T>
OrderStack<T>::OrderStack(int v_cap) :cap(v_cap) {
    if (cap < 1) {
        throw "栈容量必须大于0！";
    }
    ptr = new T[cap];
    top = -1;
}

template<class T>
void OrderStack<T>::recap(int rv_cap) {
    if (rv_cap < 1) {
        throw "栈容量必须大于0！";
    }
    T *temp = new T[rv_cap];
    cap = rv_cap;
    std::copy(ptr, ptr + top, temp);
    delete[] ptr;
    ptr = temp;
}

template<class T>
OrderStack<T>::~OrderStack() {
    delete[] ptr;
    cap = 0;
    top = -1;
}

template<class T>
void OrderStack<T>::Push(const T &item) {
    if (top == cap - 1)
        throw "栈溢出！";//可以调用recap，实现动态内存
    else
        ptr[++top] = item;
}

#endif //DB_ORDERSTACK_HPP
