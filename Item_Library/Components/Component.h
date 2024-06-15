#ifndef COMPONENT
#define COMPONENT

#include "..\..\..\utilities\utils.h"

struct Component {
	Component(const ID& ownerID);
	const ID m_ownerID;
};

#endif