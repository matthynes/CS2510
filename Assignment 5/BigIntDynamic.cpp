// Matthew Hynes (201200318)
// Adapted from soltuon provided for Assignment 3

#include <sstream>
#include <stdexcept>
#include "BigIntDynamic.h"

// ------------------------------------------------------------
BigInt::BigInt() : BigInt("0000000000") { }

// ------------------------------------------------------------
BigInt::BigInt(const std::string &num) {
    myVec.resize(mySize);
    for (int i = 0; i < mySize; ++i) {
        myVec[i] = num[i] - '0';
    }
}

// ------------------------------------------------------------
bool BigInt::operator==(const BigInt &c) const {
    for (int i = 0; i < c.myVec.size(); ++i) {
        if (myVec[i] != c.myVec[i]) {
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
    for (int i = 0; i < myVec.size(); ++i) {
        int diff = myVec[i] - c.myVec[i];
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
    std::vector<int> result(myVec.size());
    int carry = 0;
    for (int i = myVec.size() - 1; i >= 0; --i) {
        int add = myVec[i] + c.myVec[i] + carry;
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

