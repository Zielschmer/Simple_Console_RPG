#ifndef SCENE_STATUS_H
#define SCENE_STATUS_H

#include "Scene.h"

class SceneStatus : public Scene {
public:

    using Scene::Scene;
    using Scene::isRunning;

    void enter() override;
    void update() override;
    void handleInput(const Message& message);
    void exit() override;

};

#endif
