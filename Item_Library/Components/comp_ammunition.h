#ifndef COMP_AMMUNITION
#define COMP_AMMUNITION

#include "..\utils.h"
#include "Component.h"

struct CompAmmunition : public Component {
	using Component::Component;
	AmmoList m_ammo;
	bool m_loading;
};

using Ammunition_ptr = std::unique_ptr<CompAmmunition>;

#endif