#pragma once

#include "entity.h"
#include "..\..\controller\includes\bool-input.h"
#include "..\..\controller\includes\options-input.h"
#include "components-handling.h"

enum WeaponList {

	NONE,
	SWORD,
	DAGGER,
	MACE,
	HAMMER,
	BOW,
	STAFF,
	ROSARY,
	HARP,
	SHIELD

};

void equipWeapon(Entity& equippingCharacter, WeaponList weaponChoice);