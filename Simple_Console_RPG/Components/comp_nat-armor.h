#ifndef COMP_NAT_ARMOR
#define	COMP_NAT_ARMOR

#include <memory>

#include "..\utils.h"

struct NatArmor_Comp {

	ID m_ownerID;
	AC m_AC;

};

using NatArmor_ptr = std::unique_ptr<NatArmor_Comp>;

#endif