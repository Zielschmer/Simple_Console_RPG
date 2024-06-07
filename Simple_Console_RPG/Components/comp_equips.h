#ifndef COMP_EQUIPS
#define COMP_EQUIPS

#include <memory>

#include "..\utils.h"
#include "weapon.h"

struct Equips_Comp {

	ID m_ownerID;
	Weapon m_mainHand;
	Weapon m_offHand;

};

using Equips_ptr = std::unique_ptr<Equips_Comp>;

#endif