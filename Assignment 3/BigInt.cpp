// Matthew Hynes (201200318)

#include "BigInt.h"
#include <cstring>
#include <iostream>


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

int main() {

    BigInt b("0000040000");
    BigInt bb;

    std::cout << (b != bb);

    return 0;
}