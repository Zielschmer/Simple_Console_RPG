#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "..\Message.h"

class Controller {
public:
    Controller(MessageBus& bus);
    void getInput();

private:
    MessageBus& bus;
};

#endif