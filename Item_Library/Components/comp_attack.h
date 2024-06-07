#ifndef COMP_ATTACK
#define COMP_ATTACK

#include "..\utils.h"

struct CompAttack {
	ID m_ownerID;
	Range m_range;
	ScoreList m_mod;
	DiceList m_dmgDice;
	DamageList m_dmgType;
	bool m_twoHand;
	bool m_light;
};

#endif