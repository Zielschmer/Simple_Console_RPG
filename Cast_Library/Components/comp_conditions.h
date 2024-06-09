#ifndef COMP_CONDITIONS
#define COMP_CONDITIONS

#include "..\utils.h"
#include "Component.h"

struct Condition {
	ConditionList m_name;
	Turns m_turns;
};

struct CompConditions : public Component {
	using Component::Component;
	std::vector<Condition> m_conditions;
};

using Conditions_ptr = std::unique_ptr<CompConditions>;

#endif