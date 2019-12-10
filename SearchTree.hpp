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

    Element(T v = 0) {
        key = v;
    }
};

template<class T>
class SearchNode {
public:
    friend class SearchTree<T>;

    void display(int);

//private:
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

    SearchNode<T> *Search(SearchNode<T> *, const Element<T> &);

    SearchNode<T> *IterSearch(const Element<T> &x);

    void Delete(const Element<T> &x);

    void InOrder(SearchNode<T> *curNode);

    void PreOrder(SearchNode<T> *curNode);

    void PostOrder(SearchNode<T> *curNode);

    void LevelOrder(SearchNode<T> *curNode);


    void display();

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
        if (x.key == p->data.key)
            return false;
        if (x.key < p->data.key)
            p = p->lChild;
        else
            p = p->rChild;
    }
    //create node
    p = new SearchNode<T>;
    p->rChild = p->lChild = nullptr;
    p->data.key = x.key;
    if (!root) root = p;
    else if (x.key < q->data.key) q->lChild = p;
    else q->rChild = p;
    return true;
}

template<class T>
void SearchTree<T>::display() {
    if (root)
        root->display(1);
    else
        cout << "This is a null tree" << endl;

}

template<class T>
SearchNode<T> *SearchTree<T>::IterSearch(const Element<T> &x) {
    SearchNode<T> *t = root;
    while (t) {
        if (x.key == t->data.key) return t;
        if (x.key < t->data.key) t - t->lChild;
        else t = t->rChild;
    }
    return nullptr;
}

template<class T>
SearchNode<T> *SearchTree<T>::Search(SearchNode<T> *b, const Element<T> &x) {
    if (!b) return nullptr;
    if (x.key == b->data.key) return b;
    if (x.key < b->data.key) return Search(b->lChild, x);
    else return Search(b->rChild, x);
}

template<class T>
SearchNode<T> *SearchTree<T>::Search(const Element<T> &x) {
    return Search(root, x);
}

template<class T>
void SearchTree<T>::Delete(const Element<T> &x) {


}

template<class T>
void SearchNode<T>::display(int i) {
    std::cout << "Position:" << i << ":data:" << data.key << endl;
    if (lChild) lChild->display(2 * i);
    if (rChild) rChild->display(2 * i + 1);
}


#endif //DB_SEARCHTREE_HPP
