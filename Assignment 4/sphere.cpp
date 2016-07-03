// Matthew Hynes (201200318)

#include <iostream>
#include "shape.h"
#include "cylinder.cpp"
#include "rightcircularcone.cpp"

class Sphere : Shape {
private:
    static constexpr double PI = 3.14159;
    double radius;
public:
    Sphere(double r) {
        radius = r;
    }

    std::string name() override {
        return "Sphere";
    }

    double area() override {
        return (4 * PI * (radius * radius));
    }

    double volume() override {
        return ((4 / 3) * PI * (radius * radius * radius));
    }
};

int main() {
    Sphere s(4.2);
    std::cout << s.name() << "   " << s.area() << "  " << s.volume() << "\n";

    Cylinder c(4.2, 7.8);
    std::cout << c.name() << "   " << c.area() << "  " << c.volume() << "\n";

    RightCircularCone r(2.2, 12.6);
    std::cout << r.name() << "   " << r.area() << "  " << r.volume() << "\n";
    return 0;
}