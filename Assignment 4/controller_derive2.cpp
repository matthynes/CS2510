// Matthew Hynes (201200318)

#include <iostream>
#include "controller.h"

class ControllerDerive2 : public Controller {
private:
    bool is_on;
public:
    bool on() override { return is_on; }

    bool off() override { return !is_on; }

    void show() override {
        std::cout << "Is the object on? " << on() << " Is the object off? " << off() << "\n";
    }

    void set_level(int n){}
};