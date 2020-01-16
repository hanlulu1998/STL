//
// Created by hanlulu on 2020/1/6.
//

#ifndef DB_HASHMAP_HPP
#define DB_HASHMAP_HPP

#include <iostream>
#include <vector>
#include <string>

template<class Key, class Vaule>
class HashMap {
public:
    HashMap(int size = 100) : arr(size) {
        CurSize = 0;

    }

    void Put(const Key &k, const Vaule &v) {
        int Pos = Hash(k);
        arr[Pos] = Data(k, v);
        ++CurSize;
    }

    Vaule Get(const Key &k) {
        int Pos = Hash(k);
        if (arr[Pos].key == k)
            return arr[Pos].vaule;
        else
            return Vaule();
    }

    unsigned int Hash(const Key &value) {
        unsigned int hash = 0;
        unsigned int h = hash;     //缓存以前的hash计算结果
        if (h == 0 && value.length() > 0) {         //value是要计算hash值的字符串
            string val = value;
            for (int i = 0; i < value.length(); i++) {
                h = 31 * h + val[i];
            }
            hash = h;
        }
        return h%100;
    }

private:
    struct Data {
        Key key;
        Vaule vaule;

        Data(const Key &k = Key(), const Vaule &v = Vaule()) : key(k), vaule(v) {

        }
    };

    std::vector<Data> arr;
    int CurSize;
};

#endif //DB_HASHMAP_HPP
