#pragma once

#include <memory>

struct Stats_Comp {

	ID m_ownerID;

};

typedef std::unique_ptr<Stats_Comp> Stats_ptr;