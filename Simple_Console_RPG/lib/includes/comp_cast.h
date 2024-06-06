#pragma once

#include <vector>
#include <memory>

#include "lib_primitives.h"

#include "cast_spell.h"
#include "cast_pray.h"
#include "cast_song.h"

struct Cast_Comp {

	ID m_ownerID;
	std::vector<Spell> m_spells;
	std::vector<Pray> m_prays;
	std::vector<Song> m_songs;

};

typedef std::unique_ptr<Cast_Comp> Cast_ptr;