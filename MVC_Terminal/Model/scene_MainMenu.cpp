#include "scene_MainMenu.h"

#include <iostream>

#include "..\message.h"

void MainMenu::enter(){

}
void MainMenu::update(){
    // City logic (hiring, buying, learning)
    if (running) {
        //bus.publish({ MessageType::Render, "Update complete" });
    }
}
void MainMenu::handleInput(const Message& message) {
    switch (std::any_cast<InputList>(message.data))
    {
    case QUIT:
        this->exit();
        running = false;
        break;
    case OPTION_A:
        bus.publish({ MessageType::SCENE, SceneList::CITY });
        break;
    default:
        break;
    }
}
void MainMenu::exit(){
    //bus.publish({ MessageType::Render, "Exiting Menu..." });
}


