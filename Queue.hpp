//
// Created by HanLulu on 2019/10/19.
//

#ifndef DB_QUEUE_HPP
#define DB_QUEUE_HPP

#include <iostream>
template<class T>
class Queue {
public:
    Queue(int v_cap = 10);

    bool IsEmpty() const {
        return front == rear;
    }
~Queue(){
        delete[]ptr;
        cap=0;
        front=rear=0;
    }
    T &Front() const{
        if(IsEmpty())
            throw "队列为空！";
        else
            return ptr[(front+1)%cap];
    }

    T &Rear() const{
        if(IsEmpty())
            throw "队列为空！";
        else
            return ptr[rear];
    }

    void Push(const T &item);

    void Pop();
    void recap(int rv_cap);

    int Size(){
        if(front<=rear)
            return rear-front+1;
        return cap+rear-front+1;
    }

    int Cap() {
        return cap;
    }
    void Message() {
        cout << "开辟内存：" << sizeof(T) * cap << "字节；" << "已使用内存：" << sizeof(T) * Size() << "字节" << endl;
    }
private:
    T *ptr;
    int front;
    int rear;
    int cap;
protected:
};

template<class T>
Queue<T>::Queue(int v_cap):cap(v_cap) {
    if (cap < 1) {
        throw "队列容量必须大于0！";
    }
    front=rear=0;
    ptr = new T[cap];
}

template<class T>
void Queue<T>::Push(const T &item) {
//    if(rear==cap-1)
//        rear=0;
//    else
//        rear++;
    if ((rear + 1) % cap == front)
        throw "队列溢出！";//可以调用recap，实现动态内存
    rear = (rear + 1) % cap;
    ptr[rear] = item;
}
template<class T>
void Queue<T>::Pop() {
    if(IsEmpty())
        throw "队列为空！";
    front=(front+1)%cap;
    ptr[front].~T();
}
template<class T>
void Queue<T>::recap(int rv_cap) {
    if(rv_cap<1)
        throw "队列容量必须大于0！";
    T* nptr=new T[rv_cap];
    int start=(front+1)%cap;
    if(start<2)//没有回转
        copy(ptr+start,ptr+start+cap-1,nptr);
    else{
        copy(ptr+start,ptr+cap,nptr);
        copy(ptr,ptr+rear+1,nptr);
    }
    front=rv_cap-1;
    rear=cap-2;
    cap=rv_cap;
    delete[]ptr;
    ptr=nptr;
}
#endif //DB_QUEUE_HPP
