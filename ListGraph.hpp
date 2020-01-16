//
// Created by hanlu on 2020/1/16.
//

#ifndef DB_LISTGRAPH_HPP
#define DB_LISTGRAPH_HPP

#include <list>

//可以定制自己的函数T类型
template<class T>
class ListGraph {
public:
    ListGraph(const int vertex) : n(vertex) {
        VertexList = new T *[n];
        HeadNode = new list<int>[n];
        nVertex = 0;
    }

    ~ListGraph() {
        delete[] VertexList;
        delete[] HeadNode;
    }

    void AddVertex(T *v);

    void AddEdge(int start, int end);

    void PrintVertex();

    void PrintList();

private:
    T **VertexList;
    list<int> *HeadNode;
    int n;
    int nVertex;

};

template<class T>
void ListGraph<T>::AddVertex(T *v) {
    VertexList[nVertex++] = v;
}

template<class T>
void ListGraph<T>::AddEdge(int start, int end) {
    HeadNode[start].push_back(end);
}

template<class T>
void ListGraph<T>::PrintVertex() {
    for (int i = 0; i < nVertex; ++i) {
        cout << *VertexList[i] << " ";
    }
    cout << endl;
}

template<class T>
void ListGraph<T>::PrintList() {
    for (int i = 0; i < nVertex; ++i) {
        cout << i << "->";
        for (list<int>::iterator iter = HeadNode[i].begin(); iter != HeadNode[i].end(); ++iter) {
            cout << *iter << "->";
        }
        cout << "end" << endl;
    }
}

#endif //DB_LISTGRAPH_HPP
