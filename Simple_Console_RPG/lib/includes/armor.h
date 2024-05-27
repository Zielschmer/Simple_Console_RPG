#pragma once

#include <stdint.h>

struct Armor {

	int m_ownerID;
	uint8_t m_baseArmor;
	uint8_t m_armorModifier;
	bool fastCast;
	bool dexterityDebuff;

};