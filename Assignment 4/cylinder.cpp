// Matthew Hynes (201200318)

#include "shape.h"

class Cylinder : Shape {
private:
    static constexpr double PI = 3.14159;
    double radius, height;
public:
    Cylinder(double r, double h) {
        radius = r;
        height = h;
    }

    std::string name() override {
        return "Cylinder";
    }

    double area() override {
        return ((2 * PI * radius * height) + (2 * PI * (radius * radius)));
    }

    double volume() override {
        return (PI * (radius * radius) * height);
    }
};