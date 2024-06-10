#ifndef COMP_CAST
#define COMP_CAST

#include "..\utils.h"
#include "Component.h"

struct CompCast : public Component {
	using Component::Component;
	std::vector<ID> m_spells;
	std::vector<ID> m_prays;
	std::vector<ID> m_songs;
};

using Cast_ptr = std::unique_ptr<CompCast>;

#endif