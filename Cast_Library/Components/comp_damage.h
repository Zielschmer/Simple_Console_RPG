#ifndef COMP_DAMAGE
#define COMP_DAMAGE

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompDamage : public Component {
	using Component::Component;
	DiceList m_dmgDice;
	DamageList m_dmgType;
};

using Damage_ptr = std::unique_ptr<CompDamage>;

#endif