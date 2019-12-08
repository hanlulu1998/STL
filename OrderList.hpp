//
// Created by adminPC on 2019/10/19.
//

#ifndef DB_ORDERLIST_HPP
#define DB_ORDERLIST_HPP
#include <iostream>

template<class T>
class OrderList;

template<class T>
class OrderListNode {
    friend class OrderList<T>;

private:
    T data;
    OrderListNode<T> *link;

    OrderListNode(T v) {
        data = v;
        link = 0;
    }


};

template<class T>
class OrderList {
public:
    OrderList() {
        first = 0;
    };

    void Insert(T);

    void Show();

    void Delete(T);

    void Invert();
    void Concatenate(OrderList<T> b);
private:
    OrderListNode<T> *first;

};

template<class T>
void OrderList<T>::Show() {
    for (OrderListNode<T> *cur = first; cur; cur = cur->link) {
        std::cout << cur->data;
        if (cur->link)
            std::cout << "->";
    }
    std::cout << endl;
}

template<class T>
void OrderList<T>::Insert(T k) {
    OrderListNode<T> *newnode = new OrderListNode<T>(k);
    newnode->link = first;
    first = newnode;
}

template<class T>
void OrderList<T>::Delete(T k) {
    OrderListNode<T> *pre = 0;//previous node
    OrderListNode<T> *cur;//current node
    for (cur = first; cur && cur->data != k; pre = cur, cur = cur->link); //find matched node's value
    if (cur) {
        if (pre)
            pre->link = cur->link;
        else first = first->link;
        delete cur;
    }
}

template<class T>
void OrderList<T>::Invert() {
    OrderListNode<T> *p = first, *q = 0;
    while (p) {
        OrderListNode<T> *r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;

}

template<class T>
void OrderList<T>::Concatenate(OrderList<T> b) {
    if(!first){
        first=b.first;
        return;
    }
    if(b.first){
        OrderListNode<T> *p= nullptr;
        for (p = first; p->link;p=p->link) ; //find the last node of the first chain table
        p->link=b.first;
    }
}

#endif //DB_ORDERLIST_HPP
