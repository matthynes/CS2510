// Matthew Hynes (201200318)

#include "BigIntDynamic.h"
#include "Number.cpp"

int main() {
    //--------------Testing for Q1 BEGIN
    BigInt *b = new BigInt("1234567894");
    BigInt *b2 = new BigInt("8365906395");
    BigInt b3{"1234567890"};

    b = b2; //copy assign
    b2 = new BigInt("6543217895"); //copy c'tor

    BigInt b4{b3}; //move c'tor
    b3 = BigInt{"1234567890"}; //move assign
    //--------------Testing for Q1 END

    std::cout << "\n\n";

    //--------------Testing for Q2 BEGIN
    Number<int> n1(2);
    Number<int> n2(17);
    Number<double> n3(1.1);
    Number<double> n4(26.9);

    std::cout << n1.get() + n3.get() << "\n";
    std::cout << n2.get() - n1.get() << "\n";
    std::cout << n2.get() / n3.get() << "\n";
    std::cout << (n1.get() ^ n2.get()) << "\n";
    std::cout << n4.get() - n3.get() << "\n";
    std::cout << n4.get() / n1.get() << "\n";
    std::cout << n3.get() * n2.get() << "\n";
    //--------------Testing for Q2 END

    return 0;
}

