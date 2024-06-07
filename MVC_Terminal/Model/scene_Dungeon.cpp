#include "scene_Dungeon.h"

#include <iostream>

void SceneDungeon::enter() {
    //bus.publish({ MessageType::Render, "Entering Dungeon..." });
}
void SceneDungeon::update() {
    // Dungeon logic (moving, looting, encounters)
    if (running) {
        //bus.publish({ MessageType::Render, "Update complete" });
    }
}
void SceneDungeon::handleInput(const Message& message) {
    if (std::any_cast<std::string>(message.data) == "quit") {
        this->exit();
        running = false;
    }
}
void SceneDungeon::exit() {
    //bus.publish({ MessageType::Render, "Exiting Dungeon..." });
}
