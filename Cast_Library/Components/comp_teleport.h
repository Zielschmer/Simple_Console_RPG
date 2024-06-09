#ifndef COMP_TELEPORT
#define COMP_TELEPORT

#include "..\utils.h"
#include "Component.h"

struct CompTeleport : public Component {
	using Component::Component;
	bool m_dugeon;
	bool m_portal;
};

using Teleport_ptr = std::unique_ptr<CompTeleport>;

#endif