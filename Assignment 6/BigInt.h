#ifndef BIG_INT_HXX
#define BIG_INT_HXX

#include "std_lib_facilities.h"

class BigInt {
public:
    /** c'tor */
    BigInt();

    BigInt(const string &num);

    /** d'tor */
    ~BigInt();

    /** copy c'tor and assignment */
    BigInt(const BigInt &bi);

    BigInt &operator=(const BigInt &bi);

    /** move c'tor and assignment */
    BigInt(BigInt &&bi);

    BigInt &operator=(BigInt &&bi);

    /** equality operators */
    bool operator==(const BigInt &bi) const;

    bool operator!=(const BigInt &bi) const;

    /** less-than operator */
    bool operator<(const BigInt &bi) const;

    /** addition operator */
    BigInt operator+(const BigInt &bi) const;

    /** output operator */
    friend ostream &operator<<(ostream &os, const BigInt &bi) {
        for (int i = 0; i < mySize; ++i) {
            os << bi.myVec[i];
        }

        return os;
    }

private:
    static constexpr int mySize = 10;
    unique_ptr<int[]> myVec;
};

#endif