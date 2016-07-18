// Matthew Hynes (201200318)
// Adapted from solution provided for Assignment 3

#include <sstream>
#include <stdexcept>
#include "BigIntDynamic.h"

// ------------------------------------------------------------
BigInt::BigInt() : BigInt("0000000000") { }

// ------------------------------------------------------------
BigInt::BigInt(const std::string &num) {
    for (int i = 0; i < mySize; ++i) {
        myArr[i] = num[i] - '0';
    }
}

//copy c'tor
BigInt::BigInt(const BigInt &obj) {
    myArr = new int[mySize];
    *myArr = *obj.myArr;
}

BigInt::~BigInt() { delete[] myArr; }

// ------------------------------------------------------------

//copy assgn
BigInt &BigInt::operator=(const BigInt &obj) {
    if (this != &obj) {
        int *i = new int[obj.mySize];
        std::copy(obj.myArr, obj.myArr + obj.mySize, i);
        delete[] myArr;
        myArr = i;
    }
}

bool BigInt::operator==(const BigInt &c) const {
    for (int i = 0; i < mySize; ++i) {
        if (myArr[i] != c.myArr[i]) {
            return false;
        }
    }

    return true;
}

// ------------------------------------------------------------
bool BigInt::operator!=(const BigInt &c) const {
    // Make use of the already implemented '==' operator
    return !(*this == c);
}

// ------------------------------------------------------------
bool BigInt::operator<(const BigInt &c) const {
    for (int i = 0; i < mySize; ++i) {
        int diff = myArr[i] - c.myArr[i];
        if (diff < 0) {
            return true;
        } else if (diff > 0) {
            return false;
        }
    }

    return false;
}

// ------------------------------------------------------------
BigInt BigInt::operator+(const BigInt &c) const {
    // Perform the addition in columns from LSB to MSB
    int result[mySize];
    int carry = 0;
    for (int i = mySize - 1; i >= 0; --i) {
        int add = myArr[i] + c.myArr[i] + carry;
        result[i] = add % 10;
        carry = add / 10;
    }

    // At the end of the computation, if 'carry' is non-zero,
    // it means we need another digit to store the result
    // (aka, overflow)
    if (carry > 0) {
        throw std::overflow_error("overflow");
    }

    // Convert vector back to a string
    std::ostringstream buf;
    for (auto i: result) {
        buf << i;
    }

    // And return a new BigInt based on the string
    return BigInt(buf.str());
}

