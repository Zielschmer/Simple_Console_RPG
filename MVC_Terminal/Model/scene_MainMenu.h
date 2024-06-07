#ifndef SCENE_MAINMENU_H
#define SCENE_MAINMENU_H

#include "Scene.h"

class MainMenu : public Scene {
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
