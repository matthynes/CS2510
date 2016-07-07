// Matthew Hynes (201200318)

#include <iostream>
#include "controller.h"

class ControllerDerive2 : public Controller {
private:
    bool is_on = true;
    int level = 0;
public:
    std::string on() override { return is_on ? "on" : "off"; }

    std::string off() override { return !is_on ? "off" : "on"; }

    void show() override {
        std::cout << "This object is " << off() << ". It's level is " << level;
        if (level % 2 == 0) {
            std::cout << ", which is even.\n";
        }else{
            std::cout << ", which is odd.\n";
        }
    }

    void set_level(int n) {
        level = n;
    }
};