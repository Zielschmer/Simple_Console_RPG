#pragma once

#include <memory>

#include "lib_primitives.h"

enum ScoreList {

	NOMOD,
	STR,
	DEX,
	CON,
	INT,
	FTH,
	LCK

};

struct Score_Comp {

	ID m_ownerID;
	int m_str;
	int m_dex;
	int m_con;
	int m_int;
	int m_fth;
	int m_lck;

};

typedef std::unique_ptr<Score_Comp> Score_ptr;