#pragma once

#include <memory>
#include <string>

#include "lib_primitives.h"

#include "comp_score.h"

enum ArmorList {

	NOARMOR,
	ROBE,
	LEATHER_ARMOR,
	RING_MAIL,
	CHAIN_MAIL

};

struct Armor_Comp {

	ID m_ownerID;
	std::string m_name;
	int m_baseArmor;
	ScoreList m_armorMod;
	bool m_fastCast;
	bool m_dexterityDebuff;

};

typedef std::unique_ptr<Armor_Comp> Armor_ptr;