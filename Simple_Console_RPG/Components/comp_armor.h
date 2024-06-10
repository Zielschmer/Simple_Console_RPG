#ifndef COMP_ARMOR
#define COMP_ARMOR

#include "..\utils.h"
#include "Component.h"

struct CompArmor : public Component {
	using Component::Component;
	ID m_armor;
};

using Armor_ptr = std::unique_ptr<CompArmor>;

#endif
