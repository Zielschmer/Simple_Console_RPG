#include "rend_MainMenu.h"

Rend_MainMenu::Rend_MainMenu(MessageBus& bus, int width, int height) : Renderer(bus, width, height) {

    setString(tittle.x, tittle.y,       R"( ____ ____ ____ ____ ____ ____ ____ ____ ____       )");
    setString(tittle.x, (tittle.y + 1), R"(||L |||a |||b |||r |||y |||n |||t |||h |||s ||      )");
    setString(tittle.x, (tittle.y + 2), R"(||__|||__|||__|||__|||__|||__|||__|||__|||__||      )");
    setString(tittle.x, (tittle.y + 3), R"(|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|      )");
    setString(tittle.x, (tittle.y + 4), R"( ____ _________ ____ ____ ____ ____ ____ ____ ____  )");
    setString(tittle.x, (tittle.y + 5), R"(||& |||       |||W |||y |||v |||e |||r |||n |||s || )");
    setString(tittle.x, (tittle.y + 6), R"(||__|||_______|||__|||__|||__|||__|||__|||__|||__|| )");
    setString(tittle.x, (tittle.y + 7), R"(|/__\|/_______\|/__\|/__\|/__\|/__\|/__\|/__\|/__\| )");

    setString(topBar.x, topBar.y, "[X]Exit   [R]Return   ");
    setString(options.x, options.y, R"([A]New Game   [B]Continue   [C]Load   [D]Options)");

    bus.subscribe(MessageType::RENDER, [this](const Message& message) { this->updateSection(message); });

    render();

}

void Rend_MainMenu::updateSection(const Message& message) {
    auto it = std::any_cast<RenderMail>(message.data);
    switch (it.type)
    {
    case TOPBAR:
        clearSection(topBar);
        setString(topBar.x, topBar.y, it.string);
        renderSection(topBar);
        break;
    case BOTBAR:
        clearSection(options);
        setString(options.x, options.y, it.string);
        renderSection(options);
        break;
    }
}