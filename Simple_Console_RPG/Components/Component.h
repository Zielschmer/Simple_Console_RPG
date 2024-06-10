#ifndef COMPONENT
#define COMPONENT

#include "..\utils.h"

struct Component {
	Component(const ID& ownerID);
	const ID m_ownerID;
};

#endif