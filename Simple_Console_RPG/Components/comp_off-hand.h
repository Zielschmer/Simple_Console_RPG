#ifndef COMP_OFF_HAND
#define COMP_OFF_HAND

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompOffHand : public Component {
	using Component::Component;
	ID m_weapon;
};

using OffHand_ptr = std::unique_ptr<CompOffHand>;

#endif