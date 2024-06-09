#ifndef COMP_THROWABLE
#define COMP_THROWABLE

#include "..\utils.h"
#include "Component.h"

struct CompThrowable : public Component {
	using Component::Component;
	DiceList m_dmgDice;
	DamageList m_dmgType;
	ScoreList m_mod;
	Range m_range;
};

using Throwable_ptr = std::unique_ptr<CompThrowable>;

#endif