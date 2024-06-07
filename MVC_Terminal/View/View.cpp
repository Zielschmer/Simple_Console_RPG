#include "View.h"
#include <windows.h>

View::View(MessageBus& bus, int width, int height) : bus(bus), width(width), height(height) {

    bus.subscribe(MessageType::SCENE, [this](const Message& message) { this->setRenderer(message); });

    // Set console size
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = { 0, 0, width - 1, height - 1 };
    COORD bufferSize = { width, height };

    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // Initialize console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Hide Cursor
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);

    rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_MainMenu(bus, width, height)));

}

void View::setRenderer(const Message& message) {

    switch (std::any_cast<SceneList>(message.data))
    {
    case BACK:
        rendererStack.pop_back();
        break;
    case MAINMENU:
        rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_MainMenu(bus, width, height)));
        break;
    case STATUS:
        //rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_Status(bus, width, height)));
        break;
    case CITY:
        rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_City(bus, width, height)));
        break;
    case COMBAT:
        //rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_Combat(bus, width, height)));
        break;
    case DUNGEON:
        //rendererStack.push_back(std::shared_ptr<Renderer>(new Rend_Dungeon(bus, width, height)));
        break;
    default:
        break;
    }
    rendererStack.back()->render();
}

