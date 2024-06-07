#ifndef COMP_CAST
#define COMP_CAST

#include <vector>
#include <memory>

#include "..\utils.h"

#include "cast.h"

struct Cast_Comp {

	ID m_ownerID;
	std::vector<Spell&> m_spells;
	std::vector<Pray&> m_prays;
	std::vector<Song&> m_songs;

};

using Cast_ptr = std::unique_ptr<Cast_Comp>;

#endif