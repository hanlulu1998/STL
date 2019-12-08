//
// Created by hanlulu on 2019/12/5.
//

#ifndef DB_LINKEDQUEUE_HPP
#define DB_LINKEDQUEUE_HPP
#include <iostream>
template<class T>
class LinkedQueue {
public:
    LinkedQueue() {
        Front = Back = nullptr;

    }

    ~LinkedQueue() {
        MakeEmpty();
    }

    void MakeEmpty();

    bool IsEmpty() const;

    const T &getFront() const;

    void Push(const T &x);

    T Pop();

private:
    struct Node {
        T data;
        Node *link;

        Node(const T &k, Node *n = nullptr) : data(k), link(n) {
        }
    };

    Node *Front;
    Node *Back;
};

template<class T>
void LinkedQueue<T>::MakeEmpty() {
    if (!IsEmpty())
        Pop();
}

template<class T>
bool LinkedQueue<T>::IsEmpty() const {
    return Front == nullptr;
}

template<class T>
void LinkedQueue<T>::Push(const T &x) {
    if (this->IsEmpty())
        Back = Front = new Node(x);
    else
        Back = Back->link = new Node(x);
}

template<class T>
const T &LinkedQueue<T>::getFront() const {
    if (IsEmpty())
        throw "Queue is empty";
    return Front->data;
}

template<class T>
T LinkedQueue<T>::Pop() {
    T temp = getFront();
    Node *old = Front;
    Front = Front->link;
    delete old;
    return temp;
}


#endif //DB_LINKEDQUEUE_HPP
