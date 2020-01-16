//
// Created by hanlu on 2020/1/16.
//

#ifndef DB_GRAPHICS_HPP
#define DB_GRAPHICS_HPP

#include <stack>
#include <queue>

const int Max_Vertex = 20;

template<class T>
class Vertex {
public:
    Vertex(T lab) {
        Labl = lab;
        Visited = false;
    }

//private:
    T Labl;
    bool Visited;
};

template<class T>
class MatGraph {
public:
    MatGraph();

    ~MatGraph();

    void AddVertex(T lab);

    void AddEdge(int start, int end);

    void PrintMat();

    void ShowVertex(int v);

    int GetUnvisited(int v);

    void DFS();

    void BFS();

private:
    Vertex<T> *VertexList[Max_Vertex];
    int nVertex;
    int Matrix[Max_Vertex][Max_Vertex];

};

template<class T>
MatGraph<T>::MatGraph() {
    nVertex = 0;
    for (int i = 0; i < Max_Vertex; i++) {
        for (int j = 0; j < Max_Vertex; j++) {
            Matrix[i][j] = 0;
        }
    }
}

template<class T>
void MatGraph<T>::AddVertex(T lab) {
    VertexList[nVertex++] = new Vertex<T>(lab);

}

template<class T>
void MatGraph<T>::AddEdge(int start, int end) {
    Matrix[start][end] = 1;
    Matrix[end][start] = 1;
}

template<class T>
void MatGraph<T>::PrintMat() {
    for (int i = 0; i < nVertex; ++i) {
        for (int j = 0; j < nVertex; ++j) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

}

template<class T>
MatGraph<T>::~MatGraph() {
    for (int i = 0; i < nVertex; ++i) {
        delete VertexList[i];
    }

}

template<class T>
void MatGraph<T>::ShowVertex(int v) {
    cout << VertexList[v]->Labl << " ";
}

template<class T>
int MatGraph<T>::GetUnvisited(int v) {
    for (int i = 0; i < nVertex; ++i) {
        if ((Matrix[v][i] == 1) && (VertexList[i]->Visited == false))
            return i;
    }
    return -1;
}

template<class T>
void MatGraph<T>::DFS() {
    stack<int> gs;
    VertexList[0]->Visited = true;
    ShowVertex(0);
    gs.push(0);
    int v;
    while (gs.size() > 0) {
        v = GetUnvisited(gs.top());
        if (v == -1)
            gs.pop();
        else {
            VertexList[v]->Visited = true;
            ShowVertex(v);
            gs.push(v);
        }
    }
    cout << endl;
    for (int i = 0; i < nVertex; ++i) {
        VertexList[i]->Visited = false;
    }
}

template<class T>
void MatGraph<T>::BFS() {
    queue<int> gq;
    VertexList[0]->Visited = true;
    ShowVertex(0);
    gq.push(0);
    int v1, v2;
    while (gq.size() > 0) {
        v1 = gq.front();
        gq.pop();
        v2 = GetUnvisited(v1);
        while (v2 != -1) {
            VertexList[v2]->Visited = true;
            ShowVertex(v2);
            gq.push(v2);
            v2 = GetUnvisited(v1);
        }
    }
    cout << endl;
    for (int i = 0; i < nVertex; ++i) {
        VertexList[i]->Visited = false;
    }
}

#endif //DB_GRAPHICS_HPP
