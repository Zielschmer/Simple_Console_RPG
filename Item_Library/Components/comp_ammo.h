#ifndef COMP_AMMO
#define COMP_AMMO

#include "..\utils.h"
#include "Component.h"

struct CompAmmo : public Component {
	using Component::Component;
	AmmoList m_ammoType;
};

using Ammo_ptr = std::unique_ptr<CompAmmo>;

#endif