#ifndef COMP_CONDITIONS
#define COMP_CONDITIONS

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompConditions : public Component {
	using Component::Component;
	std::vector<Condition> m_conditions;
};

using Conditions_ptr = std::unique_ptr<CompConditions>;

#endif