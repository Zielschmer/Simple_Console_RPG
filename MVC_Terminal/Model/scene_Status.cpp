#include "scene_Status.h"

#include <iostream>

void SceneStatus::enter() {
}
void SceneStatus::update() {
    // Status screen logic (next, previous, confirm)
    if (running) {
        //bus.publish({ MessageType::Render, "Update complete" });
    }
}
void SceneStatus::handleInput(const Message& message) {
    
    /*switch (std::any_cast<std::string>(message.data))
    {
    default:
        break;
    }
   "quit"
    this->exit();
    running = false;*/
}
void SceneStatus::exit() {
    //bus.publish({ MessageType::Render, "Exiting City..." });
}