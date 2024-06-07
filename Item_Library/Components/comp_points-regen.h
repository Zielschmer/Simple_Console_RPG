#ifndef COMP_POINTS_REGEN
#define COMP_POINTS_REGEN

#include "..\utils.h"

struct CompTarget {
	ID m_ownerID;
	Turns m_turns;
	HP m_regenHP;
	SP m_regenSP;
};

#endif