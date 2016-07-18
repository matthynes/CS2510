// Matthew Hynes (201200318)

#include "BigIntDynamic.h"

int main() {
    BigInt *b = new BigInt("1234567894");
    BigInt *b2 = new BigInt("8365906395");
    BigInt b3{"1234567890"};

    b = b2; //copy assign
    b2 = new BigInt("6543217895"); //copy c'tor

    BigInt b4{b3}; //move c'tor
    b3 = BigInt{"1234567890"}; //move assign


    return 0;
}

