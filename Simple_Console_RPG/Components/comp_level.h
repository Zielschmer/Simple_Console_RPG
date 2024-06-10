#ifndef COMP_LEVEL
#define COMP_LEVEL

#include "..\utils.h"
#include "Component.h"

struct CompLevel : public Component{
	using Component::Component;
	Lvl m_level;
	EXP m_currentExp;
};

using Level_ptr = std::unique_ptr<CompLevel>;

#endif