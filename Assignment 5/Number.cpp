// Matthew Hynes (201200318)

#include <cmath>
#include <iostream>

template<typename T>
class Number {
private:
    const T val;

public:
    Number() : val{0} { }

    Number(T n) : val{n} { }

    T get() const {
        return val;
    }

    Number<T> operator+(Number<T> &n2) {
        return Number<T>{val + n2.get()};
    }

    Number<T> operator-(Number<T> &n2) {
        return Number<T>{val - n2.get()};
    }

    Number<T> operator*(Number<T> &n2) {
        return Number<T>{val * n2.get()};
    }

    Number<T> operator/(Number<T> &n2) {
        return Number<T>{val / n2.get()};
    }

    Number<T> operator^(Number<T> &n2) {
        return Number<T>{std::pow(val, n2.get())};
    }
};
