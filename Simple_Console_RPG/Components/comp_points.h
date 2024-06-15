#ifndef COMP_POINTS
#define COMP_POINTS

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompPoints : public Component {
	using Component::Component;
	HP m_maxHP;
	HP m_currentHP;
	SP m_maxSP;
	SP m_currentSP;
};

using Points_ptr = std::unique_ptr<CompPoints>;

#endif