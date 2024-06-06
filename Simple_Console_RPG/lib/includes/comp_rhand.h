#pragma once

#include <iostream>
#include <memory>

#include "lib_primitives.h"
#include "hand_weapon.h"
#include "..\..\src\model\includes\system_dice.h"

struct RHand_Comp {

	ID m_ownerID;
	std::string m_name;
	Dice m_diceAtk;
	ScoreList m_atkMod;
	bool m_twoHanded;
	int m_range;
	bool m_castSpell;
	bool m_castPray;
	bool m_castSong;

};

typedef std::unique_ptr<RHand_Comp> RHand_ptr;