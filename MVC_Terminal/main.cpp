#include <windows.h>

#include "Model\SceneManager.h"
#include "View\View.h"
#include "Controller\Controller.h"

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 35

int main() {

    MessageBus bus;
    SceneManager sceneManager(bus);
    View view(bus,SCREEN_WIDTH, SCREEN_HEIGHT);
    Controller controller(bus);

    while (true) {
        
        auto currentScene = sceneManager.getScene();
        controller.getInput();
        if (!currentScene->isRunning()) {
            break;
        }

    }

    return 0;
}