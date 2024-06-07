#ifndef COMP_ARMOR
#define COMP_ARMOR

#include <memory>

#include "..\utils.h"

struct CompArmor {

	ID m_ownerID;
	AC m_AC;

};

using Armor_ptr = std::unique_ptr<CompArmor>;

#endif
