// Matthew Hynes (201200318)
// Adapted from solution provided for Assignment 3

#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>
#include <iostream>

class BigInt {
public:
    /** c'tor */
    BigInt();

    BigInt(const std::string &num);

    BigInt(const BigInt &obj);

    ~BigInt();

    BigInt &operator=(const BigInt &obj);

    /** equality operators */
    bool operator==(const BigInt &c) const;

    bool operator!=(const BigInt &c) const;

    /** less-than operator */
    bool operator<(const BigInt &c) const;

    /** addition operator */
    BigInt operator+(const BigInt &c) const;

    /** output operator */
    friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
        int *arr = bi.myArr;
        for (int i = 0; i < mySize; i++) {
            os << *arr + i;
        }
        return os;
    }

private:
    static constexpr int mySize = 10;
    int *myArr = new int[mySize];
};

#endif