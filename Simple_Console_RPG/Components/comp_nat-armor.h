#ifndef COMP_NAT_ARMOR
#define	COMP_NAT_ARMOR

#include "..\utils.h"
#include "Component.h"

struct CompNatArmor : public Component{
	using Component::Component;
	AC m_AC;
};

using NatArmor_ptr = std::unique_ptr<CompNatArmor>;

#endif