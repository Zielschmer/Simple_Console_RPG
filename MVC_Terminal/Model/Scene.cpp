#include "Scene.h"
#include <iostream>

Scene::Scene(MessageBus& bus) : bus(bus), running(true) {}

bool Scene::isRunning() {
    return this->running;
}