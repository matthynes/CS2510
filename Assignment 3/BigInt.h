// Matthew Hynes (201200318)

#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <string>

class BigInt {
public:
    BigInt();

    BigInt(std::string strInt);

    std::vector<int> getBigInt() const;

private:
    std::vector<int> bigInteger;

};

#endif //BIGINT_H