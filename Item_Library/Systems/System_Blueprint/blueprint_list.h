#ifndef ITEM_BLUEPRINTS
#define ITEM_BLUEPRINTS

#include "blueprint.h"
#include "..\..\Components\comp_consumable.h"
#include "..\..\Components\comp_points-regen.h"
#include "..\..\Components\comp_equipable.h"
#include "..\..\Components\comp_attack.h"
#include "..\..\Components\comp_damage.h"
#include "..\..\Components\comp_defense.h"
#include "..\..\Components\comp_ammunition.h"
#include "..\..\Components\comp_cast-focus.h"
#include "..\..\Components\comp_conditions.h"

static ID ITEM_ID = 1001;

//Potions
const ID& createHealingPotion(ID& nextID, const ID& ownerID);

//Swords
const ID& createShortSword(ID& nextID, const ID& ownerID);

#endif