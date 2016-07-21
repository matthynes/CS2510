// Matthew Hynes (201200318)

#include "BigIntDynamic.h"
#include "Number.cpp"

int main() {
    //--------------Testing for Q1 BEGIN
    //note that these tests produce no output, no errors simply means they pass
    BigInt *b = new BigInt("1234567894");
    BigInt *b2 = new BigInt("8365906395");
    BigInt b3{"1234567890"};

    b = b2; //copy assign
    b2 = new BigInt("6543217895"); //copy c'tor

    BigInt b4{b3}; //move c'tor
    b3 = BigInt{"1234567890"}; //move assign

    delete b, b2, b3;
    //--------------Testing for Q1 END

    //--------------Testing for Q2 BEGIN
    Number<int> n1(2);
    Number<int> n2(17);
    Number<double> n3(1.1);
    Number<double> n4(26.9);

    std::cout << (n1 + n2).get() << "\n";
    std::cout << (n2 - n1).get() << "\n";
    std::cout << (n2 / n1).get() << "\n";
    std::cout << (n2 ^ n1).get() << "\n";
    std::cout << (n1 * n2).get() << "\n";
    std::cout << "\n";
    std::cout << (n4 + n3).get() << "\n";
    std::cout << (n4 - n3).get() << "\n";
    std::cout << (n4 / n3).get() << "\n";
    std::cout << (n3 * n4).get() << "\n\n";


    Number<int> n5;
    Number<double> n6;
    std::cout << "Testing deafult c'tor " << n5.get() << "   " << n6.get();
    //--------------Testing for Q2 END

    return 0;
}

