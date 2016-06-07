// Matthew Hynes (201200318)

#include "BigInt.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <error.h>


BigInt::BigInt() {
    bigInteger.assign(10, 0);
}

BigInt::BigInt(std::string strInt) {
    char strIntArr[strInt.size()];
    strcpy(strIntArr, strInt.c_str());
    for (int c:strIntArr) {
        bigInteger.push_back(c - '0');
    }
}

//BigInt::~BigInt() {
//
//}

std::vector<int> BigInt::getBigInt() const {
    return bigInteger;
}

bool operator==(const BigInt &bi1, const BigInt &bi2) {
    std::vector<int> bigInt1 = bi1.getBigInt();
    std::vector<int> bigInt2 = bi2.getBigInt();
    for (int i = 0; i < bigInt1.size(); i++) {
        if (bigInt1.at(i) != bigInt2.at(i)) {
            return false;
        }

    }
    return true;

}

bool operator!=(const BigInt &bi1, const BigInt &bi2) {
    return !(bi1 == bi2);
}

bool operator<(const BigInt &bi1, const BigInt &bi2) {
    std::vector<int> bigInt1 = bi1.getBigInt();
    std::vector<int> bigInt2 = bi2.getBigInt();
    for (int i = 0; i < bigInt1.size(); i++) {
        if (bigInt1.at(i) > bigInt2.at(i)) {
            return false;
        }

    }
    return true;
}

std::vector<int> operator+(const BigInt &bi1, const BigInt &bi2) {
    std::vector<int> bigInt1 = bi1.getBigInt();
    std::vector<int> bigInt2 = bi2.getBigInt();

    int len = std::max(bigInt1.size(), bigInt2.size());

    int carry = 0, tempSum = 0;
    std::vector<int> sum;

    for (int i = len - 1; i >= 0; i--) {
        tempSum = bigInt1.at(i) + bigInt2.at(i) + carry;

        if (i != 0) {
            sum.push_back(tempSum % 10);
        } else {
            sum.push_back(tempSum);
        }
        carry = tempSum / 10;
    }

    if (sum.size() > 10) {
        throw std::overflow_error("Sum is too large.");
    }
    return sum;
}

int main() {

    BigInt b("1234967821");
    BigInt bb("43278345386");

    std::vector<int> sum = b + bb;

    return 0;
}