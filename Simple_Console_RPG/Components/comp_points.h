#ifndef COMP_POINTS
#define COMP_POINTS


#include <memory>

#include "..\utils.h"

struct Points_Comp {

	ID m_ownerID;
	HP m_maxHP;
	HP m_currentHP;
	SP m_maxSP;
	SP m_currentSP;

};

using Points_ptr = std::unique_ptr<Points_Comp>;

#endif