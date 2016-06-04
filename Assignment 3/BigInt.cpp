// Matthew Hynes (201200318)

#include "BigInt.h"
#include <cstring>


BigInt::BigInt() {
    bigInteger[10];
}

BigInt::BigInt(std::string strInt) {
    char strIntArr[strInt.size()];
    strcpy(strIntArr, strInt.c_str());
}

std::vector<int> BigInt::getBigInt() const { return bigInteger; }

int main() {
    BigInt b();
    return 0;
}
