#ifndef COMP_CONSUMABLE
#define COMP_CONSUMABLE

#include "..\utils.h"

struct CompConsumable {
	ID m_ownerID;
	TargetList m_target;
	Range m_range;
};

#endif