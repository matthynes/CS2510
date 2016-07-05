// Matthew Hynes (201200318)

#include <iostream>
#include "sphere.cpp"
#include "cylinder.cpp"
#include "rightcircularcone.cpp"
#include "controller_derive1.cpp"

int main() {
//    Sphere *s1 = new Sphere(4.2);
//    Sphere *s2 = new Sphere(34);
//
//    Cylinder *c1 = new Cylinder(4.2, 7.8);
//    Cylinder *c2 = new Cylinder(77.7, 1);
//
//    RightCircularCone *r1 = new RightCircularCone(2.2, 12.6);
//    RightCircularCone *r2 = new RightCircularCone(41.8, 6.3);
//
//    Shape *shapes[6] = {s1, s2, c1, c2, r1, r2};
//
//    for (auto sh:shapes) {
//        std::cout << "This shape is a " << sh->name() << " with an area of " << sh->area() << " and a volume of " <<
//        sh->volume() << ".\n";
//    }
//
//    delete s1, s2, c1, c2, r1, r2;

    ControllerDerive1 cd1;
    cd1.show();

    return 0;
}