// Matthew Hynes (201200318)

#include <cmath>

template<typename T>
class Number {
private:
    T val;

public:
    Number() {
        Number(0);
    }

    Number(T n) : val{n} { }

    T get() const {
        return val;
    }

    T operator+(T n2) {
        return val + n2;
    }

    T operator-(T n2) {
        return val - n2;
    }

    T operator*(T n2) {
        return val * n2;
    }

    T operator/(T n2) {
        return val / n2;
    }

    T operator^(T n2) {
        return std::pow(val, n2);
    }
};
