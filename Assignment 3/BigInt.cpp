// Matthew Hynes (201200318)

#include "BigInt.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iterator>


BigInt::BigInt() {
    //initialize to 0000000000
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

    if (bi1 == bi2) {
        //equality fails
        return false;
    }

    for (int i = 0; i < bigInt1.size(); i++) {
        if (bigInt1.at(i) > bigInt2.at(i)) {
            //starts from front (highest digit) and moves to lowest
            // so if any are greater then bigInt2 is larger
            return false;
        }
    }
    return true;
}

BigInt operator+(const BigInt &bi1, const BigInt &bi2) {
    std::vector<int> bigInt1 = bi1.getBigInt();
    std::vector<int> bigInt2 = bi2.getBigInt();

    int carry = 0, tempSum = 0;
    std::vector<int> sum;

    for (int i = 9; i >= 0; i--) {
        tempSum = bigInt1.at(i) + bigInt2.at(i) + carry;

        if (i != 0) {
            //part without carry
            sum.push_back(tempSum % 10);
        } else {
            //last digit to push
            if (tempSum > 9) {
                //last digit pushed is double digits or greater, makes sum too large
                throw std::overflow_error("Number too large.");
            }
            sum.push_back(tempSum);
        }
        carry = tempSum / 10;
    }

    std::stringstream ss;
    //reverse sum and convert to string
    std::reverse_copy(sum.begin(), sum.end(), std::ostream_iterator<int>(ss, ""));
    //create new BigInt with sum string
    return BigInt(ss.str().c_str());
}

int main() {

    BigInt b("1234567890");
    BigInt bb("9876543211");

    std::cout << "BigInt b: " << b << std::endl;
    std::cout << "BigInt bb: " << bb << std::endl;

    std::cout << "Testing equality: " << (b == bb) << std::endl;
    std::cout << "Testing inequality: " << (b != bb) << std::endl;
    std::cout << std::endl;

    bb = BigInt("1234567890");
    std::cout << "BigInt b: " << b << std::endl;
    std::cout << "BigInt bb: " << bb << std::endl;
    std::cout << "Testing equality: " << (b == bb) << std::endl;
    std::cout << "Testing inequality: " << (b != bb) << std::endl;

    std::cout << std::endl;
    std::cout << "Resetting bb." << std::endl;
    bb = BigInt();
    std::cout << "Testing less-than inequality, bb<b: " << (bb < b) << std::endl;
    std::cout << "Testing less-than inequality, b<bb: " << (b < bb) << std::endl;
    bb = b;
    std::cout << "Testing less-than inequality with equal values (b==bb): " << (b < bb) << std::endl;

    std::cout << std::endl;
    bb = BigInt("1234567890");
    std::cout << "Testing addition: " << (b + bb) << std::endl;
    bb = BigInt("9876543211");
    std::cout << "Testing addition too large: ";
    std::cout << (b + bb) << std::endl; //throws overflow_error

    return 0;
}