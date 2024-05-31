#pragma once

#include <vector>

#include "spell.h"
#include "miracle.h"
#include "melody.h"

struct Cast {

	int m_ownerID;
	std::vector<Spell> m_spells;
	std::vector<Miracle> m_miracles;
	std::vector<Melody> m_melodies;

};