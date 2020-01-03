//
// Created by hanlulu on 2020/1/3.
//

#ifndef DB_HEAP_HPP
#define DB_HEAP_HPP

template<class T>
class MaxiumHeap {
public:
    MaxiumHeap(int num = 10) {
        if (num < 1)
            throw "MaxSize must above 1";
        MaxSize = num;
        CurSize = 0;
        HeapArray = new T[MaxSize];
    }

    virtual ~MaxiumHeap();

    bool IsEmpty();

    void Push(const T &);

    void Pop();

    const T &Top() const;


private:
    T *HeapArray;
    int MaxSize;
    int CurSize;

    void TrickleUp(int index);

    void TrickleDown(int index);
};

template<class T>
MaxiumHeap<T>::~MaxiumHeap() {
    delete[] HeapArray;
}

template<class T>
void MaxiumHeap<T>::Push(const T &x) {
    if (CurSize == MaxSize)
        throw "MaxiumHeap is full";
    HeapArray[CurSize] = x;
    TrickleUp(CurSize++);

}

template<class T>
bool MaxiumHeap<T>::IsEmpty() {
    return CurSize == 0;
}

template<class T>
void MaxiumHeap<T>::TrickleUp(int index) {
    int parindex = (index - 1) / 2;
    T temp = HeapArray[index];
    while (index > 0 && HeapArray[parindex] < temp) {
        index = parindex;
        parindex = (parindex - 1) / 2;
    }
    HeapArray[index] = temp;
}

template<class T>
const T &MaxiumHeap<T>::Top() const {
    return HeapArray[0];
}

template<class T>
void MaxiumHeap<T>::Pop() {
    HeapArray[0] = HeapArray[--CurSize];
    TrickleDown(0);
}

template<class T>
void MaxiumHeap<T>::TrickleDown(int index) {
    int largeindex;
    T temp = HeapArray[index];
    while (index < CurSize / 2) {
        int leftindex = 2 * index + 1;
        int rightindex = leftindex + 1;
        if (rightindex < CurSize && HeapArray[leftindex] < HeapArray[rightindex])
            largeindex = rightindex;
        else largeindex = leftindex;
        if (temp >= HeapArray[largeindex])
            break;
        HeapArray[index] = HeapArray[largeindex];
        index = largeindex;
    }
    HeapArray[index] = temp;

}


#endif //DB_HEAP_HPP
