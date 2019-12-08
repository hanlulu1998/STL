//
// Created by adminPC on 2019/10/19.
//

#ifndef DB_CIRCLELIST_HPP
#define DB_CIRCLELIST_HPP

#include <iostream>

template<class T>
class CircleList;

template<class T>
class CircleListNode {
    friend class CircleList<T>;
private:
    T data;
    CircleListNode<T> *link;

    CircleListNode(T v) {
        data = v;
        link = 0;
    }
};

template<class T>
class CircleList {
public:
    CircleList() {
        first = new CircleListNode<T>(0);
        first->link=first;
    };

    void Insert(T);

    void Show();//test

    void Delete(T);

private:
    CircleListNode<T> *first;

};

template<class T>
void CircleList<T>::Show() {
    for (CircleListNode<T> *cur = first->link; cur != first; cur = cur->link) {
        std::cout << cur->data;
        if(cur->link!=first)
            std::cout<<"->";
    }
    std::cout << endl;
}

template<class T>
void CircleList<T>::Insert(T k) {
    CircleListNode<T> *newnode = new CircleListNode<T>(k);
    newnode->link = first->link;
    first->link = newnode;
}

template<class T>
void CircleList<T>::Delete(T k) {
    CircleListNode<T> *pre = first;//previous node
    CircleListNode<T> *cur;//current node
    for (cur = first->link; (cur != first) && cur->data != k; pre = cur, cur = cur->link); //find matched node's value
    if (cur != first) {
        pre->link = cur->link;
        delete cur;
    }
}

#endif //DB_CIRCLELIST_HPP
