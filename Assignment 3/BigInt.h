// Matthew Hynes (201200318)

#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <string>
#include <iomanip>
#include <ostream>

class BigInt {
public:
    BigInt();

    BigInt(std::string strInt);

    std::vector<int> getBigInt() const;

    friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
        for (int i = 0; i < bi.bigInteger.size(); i++) {
            os << bi.bigInteger[i];
        }
        return os;
    }

private:
    std::vector<int> bigInteger;

};

#endif //BIGINT_H