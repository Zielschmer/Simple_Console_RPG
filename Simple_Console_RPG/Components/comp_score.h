#ifndef COMP_SCORE
#define COMP_SCORE

#include "..\utils.h"
#include "Component.h"

struct CompScore : public Component {
	using Component::Component;
	Scr m_str;
	Scr m_dex;
	Scr m_con;
	Scr m_int;
	Scr m_fth;
	Scr m_lck;
};

using Score_ptr = std::unique_ptr<CompScore>;

#endif