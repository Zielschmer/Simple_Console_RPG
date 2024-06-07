#include "Renderer.h"

#include <iostream>
#include <windows.h>
#include <sstream>

void Renderer::setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Renderer::setChar(int x, int y, char c) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        buffer[y][x] = c;
    }
}

void Renderer::setString(int x, int y, const std::string& str) {
    for (size_t i = 0; i < str.size() && x + i < width; ++i) {
        setChar(x + i, y, str[i]);
    }
}

void Renderer::printInSection(const Section& section, const std::string& text) {

    std::istringstream iss(text);
    std::string word;
    int currentWidth = 0;
    int currentX = section.x;
    int currentY = section.y;

    while (iss >> word) {
        int wordLength = word.length();
        if (currentWidth + wordLength > section.width) {
            currentY++;
            currentX = section.x;
            currentWidth = 0;
            if (currentY >= section.height) {
                break;
            }
            setString(currentX, currentY, (word + " "));
        }
        setString(currentX, currentY, (word + " "));
        currentX += wordLength + 1;
        currentWidth += wordLength + 1;
    }
}

void Renderer::drawHorLine(int width, int posiX, int posiY) {

    for (int x = 0; x < width; x++) {
        if (x == 0 || x == width - 1) {
            buffer[posiY][posiX + x] = '+';
        }
        else
        {
            buffer[posiY][posiX + x] = '-';
        }
    }
}

void Renderer::drawVerLine(int height, int posiX, int posiY) {

    for (int y = 0; y < height; y++) {
        if (y == 0 || y == height - 1) {
            buffer[posiY + y][posiX] = '+';
        }
        else
        {
            buffer[posiY + y][posiX] = '|';
        }
    }
}

void Renderer::drawBox(int width, int height, int posiX, int posiY) {

    drawHorLine(width, posiX, posiY);
    drawHorLine(width, posiX, (posiY + height - 1));

    drawVerLine(height, posiX, posiY);
    drawVerLine(height, (posiX + width - 1), posiY);

}

void Renderer::clearSection(const Section& section) {
    for (int i = 0; i < section.height; ++i) {
        std::fill(buffer[section.y + i].begin() + section.x,
            buffer[section.y + i].begin() + section.x + section.width, ' ');
    }
}

void Renderer::renderSection(const Section& section) {
    for (int i = 0; i < section.height; ++i) {
        COORD coord = { short(section.x), short(section.y + i) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout.write(&buffer[section.y + i][section.x], section.width);
    }
}

void Renderer::render() {
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int y = 0; y < height; ++y) {
        std::cout << buffer[y];
        if (y < height - 1) {
            std::cout << std::endl;
        }
    }
}

Renderer::Renderer(MessageBus& bus, int width, int height) : bus(bus), width(width), height(height), buffer(height, std::string(width, ' ')) {
    drawBox(width, height, 0, 0);
    drawHorLine(width, 0, 2);
    render();
};