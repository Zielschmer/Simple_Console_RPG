#ifndef COMP_MAIN_HAND
#define COMP_MAIN_HAND

#include "..\utils.h"
#include "Component.h"

struct CompMainHand : public Component{
	using Component::Component;
	ID m_weapon;
};

using MainHand_ptr = std::unique_ptr<CompMainHand>;

#endif