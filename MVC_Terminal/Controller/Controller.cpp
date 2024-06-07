#include "Controller.h"
#include <conio.h>

Controller::Controller(MessageBus& bus) : bus(bus) {}

void Controller::getInput() {
    char input = _getch();

    switch (input)
    {
    case 'x':
        bus.publish({ MessageType::INPUT, InputList::QUIT });
        break;
    case 'r':
        bus.publish({ MessageType::INPUT, InputList::RETURN });
        break;
    case 'm':
        bus.publish({ MessageType::INPUT, InputList::MENU });
        break;
    case 's':
        bus.publish({ MessageType::INPUT, InputList::SAVE });
        break;
    case 'l':
        bus.publish({ MessageType::INPUT, InputList::LOAD });
        break;
    case 'a':
        bus.publish({ MessageType::INPUT, InputList::OPTION_A });
        break;
    case 'b':
        bus.publish({ MessageType::INPUT, InputList::OPTION_B });
        break;
    case 'c':
        bus.publish({ MessageType::INPUT, InputList::OPTION_C });
        break;
    case 'd':
        bus.publish({ MessageType::INPUT, InputList::OPTION_D });
        break;
    case 'e':
        bus.publish({ MessageType::INPUT, InputList::OPTION_E });
        break;
    case 'f':
        bus.publish({ MessageType::INPUT, InputList::OPTION_F });
        break;
    case 'g':
        bus.publish({ MessageType::INPUT, InputList::OPTION_G });
        break;
    case 'h':
        bus.publish({ MessageType::INPUT, InputList::OPTION_H });
        break;
    case 'i':
        bus.publish({ MessageType::INPUT, InputList::OPTION_I });
        break;
    case 'j':
        bus.publish({ MessageType::INPUT, InputList::OPTION_J });
        break;
    case 'y':
        bus.publish({ MessageType::INPUT, InputList::YES });
        break;
    case 'n':
        bus.publish({ MessageType::INPUT, InputList::NO });
        break;
    }
}