#ifndef CONDITION_EFFECT
#define CONDITION_EFFECT

#include "..\..\..\utilities\utils.h"

class CondEffect {
	Turns m_turns;
	virtual void condUpdate(Turns turns) = 0;
};

#endif
