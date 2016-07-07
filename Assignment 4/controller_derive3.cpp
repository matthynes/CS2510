// Matthew Hynes (201200318)

#include <iostream>
#include "controller.h"

class ControllerDerive3 : public Controller {
private:
    bool is_on = false;
    int level = 0;
public:
    std::string on() override { return is_on ? "on" : "off"; }

    std::string off() override { return !is_on ? "off" : "on"; }

    void show() override {
        std::cout << "This object is " << off() << ". It's modified level is " << level <<
        ". Can you guess what it's original level was?\n";
    }

    void set_level(int n) {
        srand(time(0));
        level = n + 2 * (rand() % 99);
    }
};