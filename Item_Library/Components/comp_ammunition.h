#ifndef COMP_TARGET
#define COMP_TARGET

#include "..\utils.h"

struct CompAmmunition {
	ID m_ownerID;
	AmmoList m_ammo;
	bool m_loading;
};

#endif