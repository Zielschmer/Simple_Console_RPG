#ifndef SYSTEM_ITEM_CONTAINER
#define SYSTEM_ITEM_CONTAINER

#include "..\..\utils.h"

bool testComponent(ID itemID, ItemCompList comp);

std::string getItemName(ID itemID);

AC getEquipAC(ID itemID);

ScoreList getWeaponMod(ID itemID);

DiceList getEquipDmg(ID itemID);

#endif