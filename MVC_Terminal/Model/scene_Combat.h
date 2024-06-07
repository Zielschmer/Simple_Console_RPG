#ifndef SCENE_COMBAT_H
#define SCENE_COMBAT_H

#include "Scene.h"

class SceneCombat : public Scene {
public:

    using Scene::Scene;
    using Scene::isRunning;

    void enter() override;
    void update() override;
    void handleInput(const Message& message);
    void exit() override;

    using Scene::bus;

};

#endif