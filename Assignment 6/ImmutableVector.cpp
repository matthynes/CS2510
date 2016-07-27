// Matthew Hynes (201200318)


#include <initializer_list>
#include <vector>
#include <functional>
#include <iostream>

template<class T>
class ImmutableVector {
public:
    // This type will hold a lambda function that takes a
    // 'const vector<T>&' reference as a parameter and returns a
    // 'T' result
    using VectorFunction = std::function<T(const std::vector<T> &)>;

    // c'tor, which initializes an immutable (unchangeable)
    // vector of type 'T'
    ImmutableVector(std::initializer_list<T> l) : myVec(l) {}

    // This method takes a lambda function which evaluates a specific
    // operation on the internal vector
    T op(const VectorFunction &func) { return func(myVec); }

private:
    std::vector<T> myVec;
};

int main(int ac, char *av[]) {
    // Add doubles to the ImmutableVector
    ImmutableVector<double> vec = {1.2, 4.7, 3.4, 5.2, 0.8, 7.5, 6.7};

    // Create lambdas for max, min, and sum functions
    // ...

    std::cout << "Maximum value: " << // ...
              std::cout << "Minimum value: " << // ...
              std::cout << "Actual sum   : " << // ...
              std::cout << "Middle sum   : " << // ...

    return 0;
}

