#ifndef REND_CITY
#define REND_CITY

#include "Renderer.h"

class Rend_City : public Renderer {
public:
	Rend_City(MessageBus& bus, int width, int height);
	void updateSection(const Message& message);
private:
	const Section topBar{ 1, 1, (width - 2), 1 };
	const Section middle{ 1, 4, (width - 41), (height - 8) };
	const Section botBar{ 1, (height - 8), (width - 2), 6};
	const Section sideBar{ (width - 40), 3, 14, (height - 5)};
	const Section logBar{ (width - 25), 1, 23, (height - 2)};
};

#endif
