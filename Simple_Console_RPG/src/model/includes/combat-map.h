#pragma once

#include <string>
#include <array>
#include <vector>
#include <ctime>

extern std::array<std::array<int, 6>, 6> combatArea;

void combatAreaSetup(std::vector<int>& party, std::vector<int>& enemies);

bool moveCharacter(int characterID, std::string coordinate, int speed);