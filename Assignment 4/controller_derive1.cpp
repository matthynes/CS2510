// Matthew Hynes (201200318)

#include <iostream>
#include "controller.h"

class ControllerDerive1 : public Controller {
private:
    bool is_on = false;
    int level = 0;
public:
    std::string on() override { return is_on ? "on" : "off"; }

    std::string off() override { return !is_on ? "off" : "on"; }

    void show() override {
        std::cout << "This object is " << on() << ". It's level is " << level << ".\n";
    }

    void set_level(int n) {
        level = n;
    }
};