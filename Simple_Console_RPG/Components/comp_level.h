#ifndef COMP_LEVEL
#define COMP_LEVEL

#include <memory>

#include "..\utils.h"

struct Level_Comp {

	ID m_ownerID;
	Lvl m_level;
	EXP m_currentExp;

};

using Level_ptr = std::unique_ptr<Level_Comp>;

#endif