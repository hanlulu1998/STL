//
// Created by hanlulu on 2020/1/6.
//

#ifndef DB_HASHMAP_HPP
#define DB_HASHMAP_HPP

#include <iostream>
#include <vector>

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

    unsigned Hash(const Key &k) const {
        unsigned int HashVal = 0;
        const char *keyp = reinterpret_cast<const char *>(&k);
        for (size_t i = 0; i < sizeof(Key); ++i) {
            HashVal = 37 * HashVal + keyp[i];
        }
        HashVal %= arr.size();
        return HashVal;
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
