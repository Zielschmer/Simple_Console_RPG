#pragma once

#include <memory>

#include "lib_primitives.h"

struct Level_Comp {

	ID m_ownerID;

};

typedef std::unique_ptr<Level_Comp> Level_ptr;