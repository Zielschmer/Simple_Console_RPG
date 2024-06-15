#ifndef COMP_CONSUMABLE
#define COMP_CONSUMABLE

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompConsumable : public Component {
	using Component::Component;
	TargetList m_target;
};

using Consumable_ptr = std::unique_ptr<CompConsumable>;

#endif