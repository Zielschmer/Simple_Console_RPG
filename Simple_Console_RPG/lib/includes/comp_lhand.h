#pragma once

#include <iostream>
#include <memory>

#include "lib_primitives.h"
#include "hand_weapon.h"

struct LHand_Comp {

	ID m_ownerID;
	std::string m_name;
	int m_diceAtk;
	int m_atkMod;
	int m_armorClass;
	bool m_castSpell;
	bool m_castPray;

};

typedef std::unique_ptr<LHand_Comp> LHand_ptr;