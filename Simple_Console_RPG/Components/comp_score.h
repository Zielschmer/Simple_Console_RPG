#ifndef COMP_SCORE
#define COMP_SCORE

#include <memory>

#include "..\utils.h"

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
	Scr m_str;
	Scr m_dex;
	Scr m_con;
	Scr m_int;
	Scr m_fth;
	Scr m_lck;

};

using Score_ptr = std::unique_ptr<Score_Comp>;

#endif