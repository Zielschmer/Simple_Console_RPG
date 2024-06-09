#ifndef COMP_HEALING
#define COMP_HEALING

#include "..\utils.h"
#include "Component.h"

struct CompHealing : public Component {
	using Component::Component;
	HP m_regenHP;
	bool m_full;
	bool m_revive;
	std::vector<ConditionList> m_remove;
};

using Healing_ptr = std::unique_ptr<CompHealing>;

#endif