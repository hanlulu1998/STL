//
// Created by hanlulu on 2019/12/5.
//

#ifndef DB_BIDIRECTIONALLIST_HPP
#define DB_BIDIRECTIONALLIST_HPP

#include <iostream>

template<class T>
class DoubleList;

template<class T>
class DoubleListNode {
public:
    friend class DoubleList<T>;

    DoubleListNode(T v) {
        data = v;
        llink = rlink = nullptr;
    }

private:
    T data;
    DoubleListNode<T> *llink, *rlink;
};

template<class T>
class DoubleList {
public:
    DoubleList() {
        first = new DoubleListNode<T>(0);
        first->llink = first;
        first->rlink = first;
    }

    void Insert(DoubleListNode<T> *newnode, DoubleListNode<T> *oldnode);

    void Delete(DoubleListNode<T> *d);

    void Show();//test
    DoubleListNode<T> *first;
};

template<class T>
void DoubleList<T>::Insert(DoubleListNode<T> *newnode, DoubleListNode<T> *oldnode) {
    newnode->llink = oldnode;
    newnode->rlink = oldnode->rlink;
    oldnode->rlink->llink = newnode;
    oldnode->rlink = newnode;
}

template<class T>
void DoubleList<T>::Delete(DoubleListNode<T> *d) {
    if (d == first)
        cerr << "Deletion of head node not premitted" << endl;
    else {
        d->llink->rlink = d->rlink;
        d->rlink->llink = d->llink;
        //delete d;           //delete matched new ,if not new ,can not delete
    }

}

template<class T>
void DoubleList<T>::Show() {
    for (DoubleListNode<T> *cur = first->rlink; cur != first; cur = cur->rlink) {
        std::cout << cur->data;
        if (cur->rlink != first)
            std::cout << "<->";
    }
    std::cout << endl;

}

#endif //DB_BIDIRECTIONALLIST_HPP
