#include "rend_City.h"

Rend_City::Rend_City(MessageBus& bus, int width, int height) : Renderer(bus, width, height) {

    drawVerLine(height, (width - 40), 0);
    drawVerLine(height, (width - 26), 0);
    drawHorLine(15, (width - 40), 2);
    drawHorLine((width - 39), 0, (height - 9));

    setString(topBar.x, topBar.y, "[M]Menu [S]Save [L]Load [R]Return [X]Exit");
    printInSection(middle, "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

    bus.subscribe(MessageType::RENDER, [this](const Message& message) { this->updateSection(message); });

    system("cls");

}

void Rend_City::updateSection(const Message& message) {
    auto it = std::any_cast<RenderMail>(message.data);
    switch (it.type)
    {
    case TOPBAR:
        clearSection(topBar);
        setString(topBar.x, topBar.y, it.string);
        renderSection(topBar);
        break;
    case MIDDLE:
        clearSection(middle);
        setString(middle.x, middle.y, it.string);
        renderSection(middle);
        break;
    case BOTBAR:
        clearSection(botBar);
        setString(botBar.x, botBar.y, it.string);
        renderSection(botBar);
        break;
    }
}