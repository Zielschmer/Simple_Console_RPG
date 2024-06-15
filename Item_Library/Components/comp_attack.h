#ifndef COMP_ATTACK
#define COMP_ATTACK

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompAttack : public Component {
	using Component::Component;
	Range m_range;
	ScoreList m_mod;
};

using Attack_ptr = std::unique_ptr<CompAttack>;

#endif