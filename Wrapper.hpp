//
// Created by hanlulu on 2020/1/2.
//

#ifndef DB_WRAPPER_HPP
#define DB_WRAPPER_HPP

#include "Wrapper.hpp"

template<class T>
class Cite {
public:
    Cite() : p(nullptr) {

    }

    explicit Cite(const T &x) : p(&x) {

    }

    bool IsNull() const {
        return p == nullptr;
    }

    const T &Get() const {
        if (this->IsNull())
            throw NullPointerException();
        else
            return *p;

    }

private:
    const T *p;


};

#endif //DB_WRAPPER_HPP
