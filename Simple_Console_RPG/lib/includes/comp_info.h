#pragma once

#include <iostream>
#include <memory>

#include "lib_primitives.h"

struct Info_Comp {

	ID m_ownerID;
	std::string m_name;
	std::string m_desc;

};

typedef std::unique_ptr<Info_Comp> Info_ptr;