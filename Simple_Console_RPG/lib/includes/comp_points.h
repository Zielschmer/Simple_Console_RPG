#pragma once

#include <memory>

#include "lib_primitives.h"

struct Points_Comp {

	ID m_ownerID;
	int m_maxHP;
	int m_currentHP;
	int m_maxSP;
	int m_currentSP;

};

typedef std::unique_ptr<Points_Comp> Points_ptr;