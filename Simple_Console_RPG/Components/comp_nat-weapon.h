#ifndef COMP_NAT_WEAPON
#define COMP_NAT_WEAPON

#include <vector>
#include <memory>

#include "..\utils.h"
#include "out_weapon.h"

struct NatWeapon_Comp {

	ID m_ownerID;
	std::vector<Weapon> m_weapons;

};

using NatWeapon_ptr = std::unique_ptr<NatWeapon_Comp>;

#endif