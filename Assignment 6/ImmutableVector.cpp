// Matthew Hynes (201200318)


#include <initializer_list>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>

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
    auto max_elem = [](std::vector<double> v) {
        return *std::max_element(v.begin(), v.end());
    };

    auto min_elem = [](std::vector<double> v) {
        return *std::min_element(v.begin(), v.end());
    };

    auto sum = [](std::vector<double> v) {
        double n = 0;
        for (double &d: v) {
            n += d;
        }
        return n;
    };

    auto mid_sum = [&](std::vector<double> v) {
        //sort array and remove first (smallest) and last (largest) elements
        std::sort(v.begin(), v.end());
        v.erase(v.begin());
        v.erase(v.end() - 1);

        return sum(v);
    };

    std::cout << "Maximum value: " << vec.op(max_elem) << "\n";
    std::cout << "Minimum value: " << vec.op(min_elem) << "\n";
    std::cout << "Actual sum: " << vec.op(sum) << "\n";
    std::cout << "Middle sum: " << vec.op(mid_sum) << "\n";

    return 0;
}

