// Matthew Hynes (201200318)

#ifndef CS2510_CONTROLLER_H
#define CS2510_CONTROLLER_H

class Controller {
public:
    virtual bool on() = 0;

    virtual bool off() = 0;

    virtual void set_level(int n) = 0;

    virtual void show() = 0;
};

#endif //CS2510_CONTROLLER_H
