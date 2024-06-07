#ifndef RENDERER_H
#define RENDERER_H

#include <Windows.h>

#include "..\Message.h"

struct Section {
	int x, y, width, height;
};

struct ColoredChar {
	char character;
	WORD color;

	ColoredChar(char ch = ' ', WORD col = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
		: character(ch), color(col) {}
};

class Renderer {

public:
	Renderer(MessageBus& bus, int width, int height);
	void setColor(int color);
	void drawHorLine(int width, int posiX, int posiY);
	void drawVerLine(int height, int posiX, int posiY);
	void drawBox(int width, int height, int posiX, int posiY);
	void setChar(int x, int y, char c);
	void setString(int x, int y, const std::string& str);
	void printInSection(const Section& section, const std::string& text);
	void clearSection(const Section& section);
	void renderSection(const Section& section);
	void render();
	virtual void updateSection(const Message& message) = 0;
protected:
	MessageBus& bus;
	std::vector<std::string> buffer;
	int width;
	int height;
};
#endif
