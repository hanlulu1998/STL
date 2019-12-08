//
// Created by hanlulu on 2019/12/5.
//

#ifndef DB_LISTSTACK_HPP
#define DB_LISTSTACK_HPP
#include <iostream>
template <class T>
class LinkedStack;
template <class T>
class ChainNode{
public:
    friend LinkedStack<T>;
private:
    ChainNode(const T& v,ChainNode<T> *n= nullptr){
        data=v;
        link=n;
    }
    T data;
    ChainNode<T> *link;
};
template <class T>
class LinkedStack{
public:
    LinkedStack():top(nullptr){

    }
    ~LinkedStack(){
        MakeEmpty();
    }
    bool IsEmpty() const ;
    T& Top() const ;
    void Push(const T& e);
    void Pop();
    void MakeEmpty();
private:
    ChainNode<T> *top;

};

template<class T>
bool LinkedStack<T>::IsEmpty() const {
    return top== nullptr;
}

template<class T>
T &LinkedStack<T>::Top() const {
    if(this->IsEmpty())
        throw "Stack is empty";
        return top->data;
}

template<class T>
void LinkedStack<T>::Push(const T &e) {

    top=new ChainNode<T> (e,top);
}

template<class T>
void LinkedStack<T>::Pop() {
 if(this->IsEmpty())
        throw "Stack is empty";
 ChainNode<T> *tmp=top;
 top=top->link;
 delete tmp;
}

template<class T>
void LinkedStack<T>::MakeEmpty() {
    if(!this->IsEmpty()){
        this->Pop();
    }
}

#endif //DB_LISTSTACK_HPP
