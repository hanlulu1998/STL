//
// Created by HanLulu on 2019/10/16.
//

#ifndef DB_ALGORITHM_HPP
#define DB_ALGORITHM_HPP

#include <iostream>
#include <list>
template<class T>
void BubbleSort(T *s, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (s[j] >= s[j + 1])
                std::swap(s[j], s[j + 1]);
        }
    }
}

template<class T>
void SelectSort(T *s, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (s[min] >= s[j]) {
                min = j;
            }
            std::swap(s[min], s[i]);
        }
    }

}

template<class T>
void InsertSort(T *s, int n) {
    int inner, outer;
//    默认s[0]为inner的第一个元素,从s[1]开始出去
    for (int outer = 1; outer < n; ++outer) {
        int temp;
        temp = s[outer];
        inner = outer;
        while (s[inner - 1] >= temp && inner > 0) {
            s[inner] = s[inner - 1];
            --inner;
        }
        s[inner] = temp;
    }
}

template<class T>
void QuickSort(T *s, int left, int right) {
//    选定left为枢轴

    int i = left;
    int j = right + 1;
    if (i < j) {
        do {
            do i++; while (s[i] < s[left]);
            do j--; while (s[j] > s[left]);
            if (i < j) {
                std::swap(s[i], s[j]);
            }
        } while (i < j);
        std::swap(s[left], s[j]);
        QuickSort(s, left, j - 1);
        QuickSort(s, j + 1, right);
    }
}

template<class T>
void Merge(T *pT, T *pT1, int l, int m, int n) {
    int i1 = 0, i2 = 0, iResult = 0;
    for (i1 = l, i2 = m + 1, iResult = l; i1 <= m && i2 <= n; iResult++) {
        if (pT[i1] <= pT[i2]) {
            pT1[iResult] = pT[i1];
            i1++;
        } else {
            pT1[iResult] = pT[i2];
            i2++;
        }
    }
    std::copy(pT + i1, pT + m + 1, pT1 + iResult);
    std::copy(pT + i2, pT + n + 1, pT1 + iResult);
}

template<class T>
void MergePass(T *oldArry, T *newArry, int n, int s) {
    int i;
    for (i = 1; i <= n - 2 * s + 1; i = i + 2 * s) {
        Merge<T>(oldArry, newArry, i, i + s - 1, i + 2 * s - 1);
    }
    if ((i + s - 1) < n)
        Merge<T>(oldArry, newArry, i, i + s - 1, n);
    else
        copy(oldArry + i, oldArry + n + 1, newArry + i);

}

template<class T>
void MergeSort(T *a, int n) {
    T *temp = new T[n + 1];
    for (int l = 1; l < n; l *= 2) {
        MergePass(a, temp, n, l);
        l *= 2;
        MergePass(temp, a, n, l);
    }
    delete[] temp;
}

//radix sort
template<class T>
int MaxDigit(T *a, int n) {
    int d = 1, p = 10;
    for (int i = 0; i < n; ++i) {
        while (a[i] >= p) {
            d++;
            p *= 10;
        }

    }
    return d;

}

template<class T>
void RadixSort(T *a, int n) {
    int d = MaxDigit(a, n);
    list <T> lists[10];
    int i, j, k, factor;
    for (i = 1, factor = 1; i <= d; factor *= 10, ++i) {
        for (j = 0; j < n; ++j) {
            lists[(a[j] / factor) % 10].push_back(a[j]);
        }
        for (j = k = 0; j < 10; j++) {
            while (!lists[j].empty()) {
                a[k++] = lists[j].front();
                lists[j].pop_front();
            }
        }

    }

}

#endif //DB_ALGORITHM_HPP
