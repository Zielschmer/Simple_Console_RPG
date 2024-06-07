#include "scene_Combat.h"

#include <iostream>

void SceneCombat::enter() {
    //bus.publish({ MessageType::Render, "Entering Combat..." });
}
void SceneCombat::update() {
    // Combat logic (movement, attacks, spells)
    if (running) {
       // bus.publish({ MessageType::Render, "Update complete" });
    }
}
void SceneCombat::handleInput(const Message& message) {
    if (std::any_cast<std::string>(message.data) == "quit") {
        this->exit();
        running = false;
    }
}
void SceneCombat::exit() {
    //bus.publish({ MessageType::Render, "Exiting Combat..." });
}