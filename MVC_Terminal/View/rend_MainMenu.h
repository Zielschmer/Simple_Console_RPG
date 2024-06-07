#ifndef REND_MAINMENU
#define REND_MAINMENU

#include "Renderer.h"

class Rend_MainMenu : public Renderer {
public:
	Rend_MainMenu(MessageBus& bus, int width, int height);
	void updateSection(const Message& message);
private:
	const Section topBar{ 1, 1, (width - 2), 1 };
	const Section options{ (width - 78), (height - 10), (width - 44), 1 };
	const Section tittle{ ((width / 2) - 25), (abs(height / 2) - 7), (width / 2), (height / 2) };
};

#endif
