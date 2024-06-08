#ifndef COMP_EQUIPABLE
#define COMP_EQUIPABLE

#include "..\utils.h"
#include "Component.h"

struct CompEquipable : public Component {
	using Component::Component;
	EquipType m_type;
	bool m_equiped;
	bool m_twoHand;
	bool m_light;
};

using Equipable_ptr = std::unique_ptr<CompEquipable>;

#endif