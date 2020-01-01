//
// Created by hanlulu on 2019/12/21.
//

#ifndef DB_REDBLACKTREE_HPP
#define DB_REDBLACKTREE_HPP

#include <iostream>
#include "Exceptions.hpp"

template<class T>
class RedBlackTree;

template<class T>
class RedBlackNode {
public:
    friend class RedBlackTree<T>;

//private:
    T data;
    RedBlackNode *left;
    RedBlackNode *right;
    int color;

    RedBlackNode(const T &data = T(),
                 RedBlackNode *left = nullptr,
                 RedBlackNode *right = nullptr,
                 int color = RedBlackTree<T>::BLACK)
            : data(data), left(left), right(right), color(color) {}
};

template<class T>
class RedBlackTree {
public:
    typedef RedBlackNode<T> Node;

    RedBlackTree(const T &negInf);

    ~RedBlackTree();

    void Insert(const T &x);

    void RightRotate(Node *&k2) const;

    void LeftRotate(Node *&k1) const;

    void DoubleRightRotate(Node *&k3) const;

    void DoubleLeftRotate(Node *&k1) const;

    void HandleReorient(const T &x);

    RedBlackNode<T> *Rotate(const T &x, Node *&par) const;

    enum {
        RED, BLACK
    };
//private:
    Node *header;
    Node *nullNode;
    Node *Cur;
    Node *Par;
    Node *Gra;
    Node *Gre;

};

template<class T>
RedBlackTree<T>::RedBlackTree(const T &negInf) {
    nullNode = new Node();
    nullNode->left = nullNode->right = nullNode;
    header = new Node(negInf);
    header->right = header->left = nullNode;

}

template<class T>
RedBlackTree<T>::~RedBlackTree() {
    delete nullNode;
    delete header;
}

template<class T>
void RedBlackTree<T>::Insert(const T &x) {
    Cur = Par = Gra = header;
    nullNode->data = x;
    while (Cur->data != x) {
        Gre = Gra;
        Gra = Par;
        Par = Cur;
        Cur = ((x < Cur->data) ? Cur->left : Cur->right);
        if (Cur->left->color == RED && Cur->right->color == RED)
            HandleReorient(x);
    }
    if (Cur != nullNode)
        throw DuplicateItemException();
    Cur = new Node(x, nullNode, nullNode);
    if (x < Par->data)
        Par->left = Cur;
    else Par->right = Cur;
    //auto banlance
    HandleReorient(x);

}

template<class T>
void RedBlackTree<T>::RightRotate(RedBlackTree::Node *&k2) const {
    Node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2 = k1;
}

template<class T>
void RedBlackTree<T>::LeftRotate(RedBlackTree::Node *&k1) const {
    Node *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

template<class T>
void RedBlackTree<T>::DoubleRightRotate(RedBlackTree::Node *&k3) const {
    LeftRotate(k3->left);
    RightRotate(k3);

}

template<class T>
void RedBlackTree<T>::DoubleLeftRotate(RedBlackTree::Node *&k1) const {
    RightRotate(k1->right);
    LeftRotate(k1);
}

template<class T>
void RedBlackTree<T>::HandleReorient(const T &x) {
    //Rotate && color change
    Cur->color = RED;
    Cur->left->data = BLACK;
    Cur->right->data = BLACK;
    if (Par->color == RED) {
        Gra->color = RED;
        if ((x < Gra->data) != (x < Par->data)) {
            Par = Rotate(x, Gra);
        }
        Cur = Rotate(x, Gre);
        Cur->color = BLACK;
    }
    header->right->color = BLACK;
}

template<class T>
RedBlackNode<T> *RedBlackTree<T>::Rotate(const T &x, RedBlackTree::Node *&par) const {
    if (x < par->data) {
        (x < par->left->data) ? RightRotate(par->left) : LeftRotate(par->left);
        return par->left;
    } else {
        (x < par->right->data) ? RightRotate(par->left) : LeftRotate(par->left);
        return par->right;
    }
}

#endif //DB_REDBLACKTREE_HPP
