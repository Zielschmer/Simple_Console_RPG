#ifndef SCENE_DUNGEON_H
#define SCENE_DUNGEON_H

#include "Scene.h"

class SceneDungeon : public Scene {
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
