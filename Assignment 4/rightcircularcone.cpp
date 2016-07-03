// Matthew Hynes (201200318)

#include <cmath>
#include "shape.h"

class RightCircularCone : Shape {
private:
    static constexpr double PI = 3.14159;
    double radius, height;
public:
    RightCircularCone(double r, double h) {
        radius = r;
        height = h;
    }

    std::string name() override {
        return "Right Circular Cone";
    }

    double area() override {
        return (PI * radius * (radius + (sqrt((height * height) + (radius * radius)))));
    }

    double volume() override {
        return (PI * (radius * radius) * (height / 3));
    }
};