#ifndef COMP_DEFENSE
#define COMP_DEFENSE

#include "..\utils.h"
#include "Component.h"

struct CompDefense : public Component {
	using Component::Component;
	AC m_AC;
	Resistance m_resist;
	Weakness m_weak;
	bool m_heavy;
};

using Defense_ptr = std::unique_ptr<CompDefense>;

#endif