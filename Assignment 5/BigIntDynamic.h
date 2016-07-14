// Matthew Hynes (201200318)
// Adapted from soltuon provided for Assignment 3

#ifndef BIG_INT_HXX
#define BIG_INT_HXX

#include <string>

class BigInt {
public:
    /** c'tor */
    BigInt();

    BigInt(const std::string &num);

    /** equality operators */
    bool operator==(const BigInt &c) const;

    bool operator!=(const BigInt &c) const;

    /** less-than operator */
    bool operator<(const BigInt &c) const;

    /** addition operator */
    BigInt operator+(const BigInt &c) const;

    /** output operator */
    friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
        int
        [] arr = bi.myArr;
            for () {
                os << i;
            }

            return os;
        }

private:
    static constexpr int mySize = 10;
    int *myArr = new int[mySize];
};

#endif