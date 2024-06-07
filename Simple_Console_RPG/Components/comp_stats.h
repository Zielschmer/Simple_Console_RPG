#ifndef COMP_STATS
#define COMP_STATS

#include <memory>

#include "..\utils.h"

struct Stats_Comp {

	ID m_ownerID;

};

using Stats_ptr = std::unique_ptr<Stats_Comp>;

#endif