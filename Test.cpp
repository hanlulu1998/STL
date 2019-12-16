//
// Created by HanLulu on 2019/10/16.
//
#include <iostream>
#include "OrderStack.hpp"
#include "Algorithm.hpp"
#include "Queue.hpp"
#include "OrderList.hpp"
#include "CircleList.hpp"
#include "DoubleList.hpp"
#include "LinkedStack.hpp"
#include "LinkedQueue.hpp"
#include "BinaryTree.hpp"
#include "SearchTree.hpp"
#include <string>

using namespace std;

void test1() {
//    ≤‚ ‘
    OrderStack<int> test(10);
    test.Push(10);
    test.Push(20);
    test.Push(30);
    cout << "???????" << test.Top() << ";size:" << test.Size() << ";cap:" << test.Cap() << endl;
    test.Message();
    test.Pop();
    cout << "???????" << test.Top() << ";size:" << test.Size() << ";cap:" << test.Cap() << endl;
    test.Message();
    test.recap(20);
    test.Push(40);
    test.Push(50);
    test.Push(60);
    cout << "???????" << test.Top() << ";size:" << test.Size() << ";cap:" << test.Cap() << endl;
    test.Message();
    test.Pop();
    cout << "???????" << test.Top() << ";size:" << test.Size() << ";cap:" << test.Cap() << endl;
    test.Message();
//    ?????
//OrderStack<string> test1(20);

}

void test2() {
    int a[] = {9, 7, 6, 8, 11, 23, 7, 33};
    for (int i = 0; i < 8; ++i) {
        cout << a[i] << ",";
    }
    cout << endl;
    BubbleSort<int>(a, 8);

    for (int i = 0; i < 8; ++i) {
        cout << a[i] << ",";
    }
    cout << endl;
    SelectSort<int>(a, 8);

    for (int i = 0; i < 8; ++i) {
        cout << a[i] << ",";
    }
    cout << endl;

    InsertSort<int>(a, 8);

    for (int i = 0; i < 8; ++i) {
        cout << a[i] << ",";
    }
    cout << endl;
    int s[] = {9, 7, 6, 8, 11, 23, 7, 33, 99};

    QuickSort<int>(s, 0, 7);

    for (int i = 0; i <= 8; ++i) {
        cout << s[i] << ",";
    }
    cout << endl;
    int q[] = {0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
    MergeSort(q, 10);
    for (int j = 1; j < 11; ++j) {
        cout << q[j] << ",";
    }
    cout << endl;
}

void test3() {
    Queue<char> q(4);
    q.Push('A');
    q.Push('B');
    q.Push('C');
    cout << q.Size() << endl;
    cout << q.Cap() << endl;
    q.Message();
    q.recap(8);
    q.Push('D');
    q.Push('E');
    q.Push('F');
    cout << q.Size() << endl;
    cout << q.Cap() << endl;
    q.Message();
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    q.Pop();
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    cout << q.Size() << endl;
    cout << q.Cap() << endl;
    q.Message();
}

void test4() {
    OrderList<int> numList;
    numList.Insert(5);
    numList.Insert(6);
    numList.Insert(7);
    numList.Insert(8);
    numList.Show();
    numList.Invert();
    numList.Show();
    numList.Delete(5);
    numList.Delete(10);
    numList.Show();
    numList.Invert();
    numList.Show();
    OrderList<char> chaList;
    chaList.Insert('A');
    chaList.Insert('B');
    chaList.Insert('C');
    chaList.Insert('D');
    chaList.Show();
    chaList.Delete('D');
    chaList.Show();
    chaList.Invert();
    chaList.Show();
    chaList.Invert();
    OrderList<char> chaList2;
    chaList2.Insert('D');
    chaList2.Insert('E');
    chaList2.Insert('F');
    chaList2.Concatenate(chaList);
    chaList2.Show();
}

void test5() {
    CircleList<char> chaList;
    chaList.Insert('A');
    chaList.Insert('B');
    chaList.Insert('C');
    chaList.Insert('D');
    chaList.Insert('E');
    chaList.Show();
    chaList.Delete('A');
    chaList.Show();
}

void test6() {
    DoubleList<int> DL;
    DoubleListNode<int> node1(10), node2(20), node3(30), node4(40), node5(50);
    DL.Insert(&node1, DL.first);
    DL.Insert(&node2, &node1);
    DL.Insert(&node3, &node2);
    DL.Insert(&node4, &node3);
    DL.Insert(&node5, &node4);
    DL.Show();
    DL.Delete(&node3);
    DL.Show();
}

void test7() {
    LinkedStack<int> ls;
    ls.Push(10);
    ls.Push(20);
    ls.Push(30);
    ls.Push(40);
    ls.Push(50);
    cout << ls.Top() << endl;
    ls.Pop();
    cout << ls.Top() << endl;
}

void test8() {
    LinkedQueue<int> lq;
    lq.Push(10);
    lq.Push(20);
    lq.Push(30);
    lq.Push(40);
    cout << lq.getFront() << endl;
    cout << lq.Pop() << endl;
    cout << lq.getFront() << endl;

}

void test9() {
    int data[] = {11, 13, 14, 17, 88, 99, 5, 237, 10, 123};
    for (int i = 0; i < 10; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << MaxDigit(data, 10) << endl;
    RadixSort(data, 10);
    for (int i = 0; i < 10; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void test10() {
    BinaryTree<char> tree;
    TreeNode<char> n1, n2, n3, n4, n5, n6, n7, n8, n9;
    n1.data = '+';
    n2.data = '-';
    n3.data = '*';
    n4.data = '/';
    n5.data = 'A';
    n6.data = 'B';
    n7.data = 'C';
    n8.data = 'D';
    n9.data = 'E';
    tree.root = &n1;
    n1.rChild = &n9;
    n1.lChild = &n2;
    n2.rChild = &n8;
    n2.lChild = &n3;
    n3.rChild = &n7;
    n3.lChild = &n4;
    n4.rChild = &n6;
    n4.lChild = &n5;
    tree.InOrder(tree.root);
    cout << endl;
    tree.PreOrder(tree.root);
    cout << endl;
    tree.PostOrder(tree.root);
    cout << endl;
    tree.LevelOrder(tree.root);
    cout << endl;
}

void test11() {
    SearchTree<int> m;
    Element<int> a(5), b(3), c(11), d(3), e(15), f(2), g(8), h(22), i(20), j(9), k, l;
    cout << m.Insert(a) << endl;
    cout << m.Insert(b) << endl;
    cout << m.Insert(c) << endl;
    cout << m.Insert(d) << endl;
    cout << m.Insert(e) << endl;
    cout << m.Insert(f) << endl;
    cout << m.Insert(g) << endl;
    cout << m.Insert(h) << endl;
    m.display();
    m.LevelOrder(m.root);
    SearchNode<int> *p;
    p = m.Search(f);
    cout << p->data.key << endl;
    p= m.Delete(c);
    cout << p->data.key << endl;
    p=m.Delete(f);
    cout << p->data.key << endl;
    p=m.Delete(h);
    cout << p->data.key << endl;
    m.display();
}
int main() {
    test11();
    return 0;
}