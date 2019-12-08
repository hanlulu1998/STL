//
// Created by hanlulu on 2019/12/6.
//

#ifndef DB_BINARYTREE_HPP
#define DB_BINARYTREE_HPP

#include <queue>
#include <iostream>

template<class T>
struct TreeNode {
    TreeNode() {
        lChild = rChild = nullptr;

    }

    T data;
    TreeNode<T> *lChild;
    TreeNode<T> *rChild;
};

template<class T>
struct BinaryTree {
    void InOrder(TreeNode<T> *curNode);

    void PreOrder(TreeNode<T> *curNode);

    void PostOrder(TreeNode<T> *curNode);

    void LevelOrder(TreeNode<T> *curNode);

    TreeNode<T> *root;
};

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *curNode) {
    if (curNode) {
        InOrder(curNode->lChild);
        std::cout << curNode->data;
        InOrder(curNode->rChild);
    }
}

template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T> *curNode) {
    if (curNode) {
        std::cout << curNode->data;
        PreOrder(curNode->lChild);
        PreOrder(curNode->rChild);
    }
}

template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *curNode) {
    if (curNode) {
        PreOrder(curNode->lChild);
        PreOrder(curNode->rChild);
        std::cout << curNode->data;
    }
}

template<class T>
void BinaryTree<T>::LevelOrder(TreeNode<T> *curNode) {
    std::queue<TreeNode<T> *> q;
    while (curNode) {
        std::cout << curNode->data;
        if (curNode->lChild) q.push(curNode->lChild);
        if (curNode->rChild) q.push(curNode->rChild);
        if (q.empty()) return;
        curNode = q.front();
        q.pop();
    }

}

#endif //DB_BINARYTREE_HPP
