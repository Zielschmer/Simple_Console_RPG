#pragma once

#include <vector>
#include <memory>

#include "lib_primitives.h"
#include "hand_weapon.h"

struct NatWeapon_Comp {

	ID m_ownerID;
	std::vector<Weapon> m_weapons;

};

typedef std::unique_ptr<NatWeapon_Comp> NatWeapon_ptr;