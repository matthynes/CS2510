// Matthew Hynes (201200318)

#include <string>

#ifndef SHAPE_H

class Shape {
public:
    virtual std::string name() = 0;

    virtual double area() = 0;

    virtual double volume() = 0;
};

#define SHAPE_H

#endif //SHAPE_H
