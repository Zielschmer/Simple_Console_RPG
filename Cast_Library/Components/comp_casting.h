#ifndef COMP_CASTING
#define COMP_CASTING

#include "..\utils.h"
#include "Component.h"

struct CompCasting : public Component {
	using Component::Component;
	SP m_cost;
	Turns m_turns;
	ScoreList m_mod;
	TargetList m_target;
	Range m_range;
};

using Casting_ptr = std::unique_ptr<CompCasting>;

#endif