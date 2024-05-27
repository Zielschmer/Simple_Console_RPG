#pragma once

#include <vector>

#include "..\..\lib\includes\spell.h"
#include "..\..\lib\includes\miracle.h"
#include "..\..\lib\includes\melody.h"

struct Magic {

	int m_ownerID;
	std::vector<Spell> m_spells;
	std::vector<Miracle> m_miracles;
	std::vector<Melody> m_melodies;

};