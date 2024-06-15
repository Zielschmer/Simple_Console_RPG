#ifndef COMP_RANGE
#define COMP_RANGE

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompRange : public Component {
	using Component::Component;
	ScoreList m_mod;
	Range m_range;
};

using Range_ptr = std::unique_ptr<CompRange>;

#endif