#pragma once

#include <vector>
#include <algorithm>

#include "entity.h"
#include "roll-dice.h"

extern std::vector<int> turnOrder;

void combatInitative(std::vector<int>& partyID, std::vector<int>& enemies);