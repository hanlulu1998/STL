//
// Created by hanlulu on 2019/12/23.
//

#ifndef DB_EXCEPTIONS_HPP
#define DB_EXCEPTIONS_HPP

#include <string>

using namespace std;

class DSException {

public:

    DSException(const string &msg = "") : message(msg) {

    }

    virtual ~DSException() {

    }

    virtual string toString() const {

        return "Exception" + string(":") + what();
    }

    virtual string what() const {

        return message;
    }

private:
    string message;
};

class DuplicateItemException : public DSException {
public:
    DuplicateItemException(const string &msg = "") : DSException(msg) {

    }

private:


};

#endif //DB_EXCEPTIONS_HPP
