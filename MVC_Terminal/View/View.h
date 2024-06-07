#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include "..\Message.h"
#include "rend_MainMenu.h"
#include "rend_City.h"

class View {
public:
    View(MessageBus& bus, int width, int height);
    void setRenderer(const Message& message);
private:
    MessageBus& bus;
    int width;
    int height;
    std::vector<std::shared_ptr<Renderer>> rendererStack;
};

#endif