#include "scene_City.h"

#include <iostream>

void SceneCity::enter(){

}
void SceneCity::update(){
    // City logic (hiring, buying, learning)
    if (running) {
        //bus.publish({ MessageType::Render, "Update complete" });
    }
}
void SceneCity::handleInput(const Message& message) {
    switch (std::any_cast<InputList>(message.data))
    {
    case QUIT:
        this->exit();
        running = false;
        break;
    case RETURN:
        bus.publish({ MessageType::SCENE, SceneList::BACK });
        break;
    default:
        break;
    }
}
void SceneCity::exit(){
    //bus.publish({ MessageType::Render, "Exiting City..." });
}

