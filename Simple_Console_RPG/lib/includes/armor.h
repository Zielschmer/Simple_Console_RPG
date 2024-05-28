#pragma once

#include <stdint.h>

struct Armor {

	int m_ownerID;
	std::string m_name;
	int m_baseArmor;
	int m_armorModifier;
	bool m_fastCast;
	bool m_dexterityDebuff;

};