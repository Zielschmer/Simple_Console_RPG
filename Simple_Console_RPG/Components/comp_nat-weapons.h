#ifndef COMP_NAT_WEAPON
#define COMP_NAT_WEAPON

#include "..\utils.h"
#include "Component.h"

struct CompNatWeapons : public Component{
	using Component::Component;
	std::vector<ID> m_weapons;
};

using NatWeapons_ptr = std::unique_ptr<CompNatWeapons>;

#endif