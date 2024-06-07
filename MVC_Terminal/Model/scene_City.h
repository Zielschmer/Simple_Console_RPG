#ifndef SCENE_CITY_H
#define SCENE_CITY_H

#include "Scene.h"

class SceneCity : public Scene {
public:

    using Scene::Scene;
    using Scene::isRunning;

    void enter() override;
    void update() override;
    void handleInput(const Message& message);
    void exit() override;

};

#endif