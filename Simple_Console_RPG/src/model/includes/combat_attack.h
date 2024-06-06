#pragma once

#include "..\..\..\lib\includes\lib_primitives.h"
#include "system_inventory.h"

extern Inventory inventory;
extern Party partyID;

void actionAttack(ID& attackerID, ID& targetID);