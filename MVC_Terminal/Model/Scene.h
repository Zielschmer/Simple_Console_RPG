#ifndef SCENE_H
#define SCENE_H

#include "..\Message.h"

class Scene {
public:
    Scene(MessageBus& bus);
    virtual void enter() = 0;
    virtual void update() = 0;
    virtual void handleInput(const Message& message) = 0;
    virtual void exit() = 0;
    virtual bool isRunning();
    virtual ~Scene() = default;
protected:
    bool running;
    MessageBus& bus;
};

#endif
