#ifndef COMBAT_ATTACK
#define COMBAT_ATTACK

#include "..\..\utils.h"
#include "..\System_Inventory\system_inventory.h"

extern Inventory inventory;
extern Party partyID;

void actionAttack(ID& attackerID, ID& targetID);

#endif