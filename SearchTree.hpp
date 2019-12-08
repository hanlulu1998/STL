//
// Created by hanlulu on 2019/12/6.
//

#ifndef DB_SEARCHTREE_HPP
#define DB_SEARCHTREE_HPP

#include <iostream>

template<class T>
class SearchTree;

template<class T>
struct Element {
    T key;

    Element(T v=0) {
        key = v;
    }
};

template<class T>
class SearchNode {
public:
    friend class SearchTree<T>;

    void display(int);

private:
    Element<T> data;
    SearchNode<T> *lChild;
    SearchNode<T> *rChild;
};

template<class T>
class SearchTree {
public:
    SearchTree(SearchNode<T> *v = nullptr) {
        root = v;
    }

    bool Insert(const Element<T> &x);

    SearchNode<T> *Search(const Element<T> &x);

    SearchNode<T> *Search(SearchNode<T> *, const Element<T>);

    SearchNode<T> *IterSearch(const Element<T> &x);

    void display(int);

private:
    SearchNode<T> *root;

};

template<class T>
bool SearchTree<T>::Insert(const Element<T> &x) {
    SearchNode<T> *p = root;
    SearchNode<T> *q = nullptr;//q->the parent of p
    //find the situation
    while (p) {
        q = p; //save p,q->the parent of p
        if (x.key == p->data)
            return false;
        if (x.key < p->data)
            p = p->lChild;
        if (x.key > p->data)
            p = p->rChild;
    }
    //create node
    p = new SearchNode<T>;
    p->rChild = p->lChild = nullptr;
    p->data = x;
    if (!root) root = p;
    else if (x.key < p->data) q->lChild = p;
    else q->rChild = p;
    return true;
}

template<class T>
void SearchNode<T>::display(int i) {
    std::cout << "Position:" << i << ":data:" << data.key << endl;
    if (lChild) lChild->display(2 * i);
    if (rChild) rChild->display(2 * i + 1);
}


#endif //DB_SEARCHTREE_HPP
