#pragma once

#include <memory>

#include "lib_primitives.h"

struct NatArmor_Comp {

	ID m_ownerID;
	int m_armorClass;

};

typedef std::unique_ptr<NatArmor_Comp> NatArmor_ptr;