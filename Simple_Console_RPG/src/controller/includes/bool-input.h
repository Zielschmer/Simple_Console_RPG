#pragma once

enum WeaponEquip {

	TWOHAND_DELETE_L = 0,
	TWOHAND_DELETE_R,
	TWOHAND_DELETE_R_L,
	ONEHAND_DELETE_TWOHAND,
	SHIELD_DELETE_TWOHAND

};

bool validBoolInput(WeaponEquip weaponEquip);