#ifndef COMP_CONDITIONS
#define COMP_CONDITIONS

#include "..\utils.h"
#include "Component.h"

struct Condition : public Component {
	using Component::Component;
	ConditionList m_name;
	Turns m_turns;
};

struct CompConditions {
	std::vector<Condition> m_conditions;
};

using Conditions_ptr = std::unique_ptr<CompConditions>;

#endif