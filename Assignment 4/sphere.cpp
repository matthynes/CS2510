// Matthew Hynes (201200318)

#include "shape.h"

class Sphere : public Shape {
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
