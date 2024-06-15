#ifndef COMBAT_MAP
#define COMBAT_MAP

#include <string>
#include <array>
#include <vector>
#include <ctime>

#include "..\..\..\utilities\utils.h"

extern Map<6> map;

void mapSetup(Party& partyID, Party& enemiesID);

bool moveCharacter(ID entityID, std::string coordinate, int speed);

bool checkRange(ID attackerID, int range, Party& targetParty, std::vector<int>& inRangeTargets);

#endif