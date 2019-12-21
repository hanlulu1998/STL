//
// Created by hanlulu on 2019/12/21.
//

#ifndef DB_REDBLACKTREE_HPP
#define DB_REDBLACKTREE_HPP

#include <iostream>

template<class T>
class RedBlackTree;

template<class T>
class RedBlackNode {
public:
    friend class RedBlackTree<T>;

private:
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

    enum {
        RED, BLACK
    };
private:
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
    Cur=Par=Gra=header;
    nullNode->data=x;
    while(){




    }

}

#endif //DB_REDBLACKTREE_HPP
