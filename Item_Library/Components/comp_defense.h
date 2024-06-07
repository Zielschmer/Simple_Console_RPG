#ifndef COMP_DEFENSE
#define COMP_DEFENSE

#include "..\utils.h"

struct CompDefense {
	ID m_ownerID;
	AC m_AC;
	Resistance m_resist;
	Weakness m_weak;
	bool m_heavy;
};

#endif