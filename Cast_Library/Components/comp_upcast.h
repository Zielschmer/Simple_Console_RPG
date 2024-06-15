#ifndef COMP_UPCAST
#define COMP_UPCAST

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompUpcast : public Component {
	using Component::Component;
	uint16_t m_times;
	bool m_targets;
	bool m_damage;
};

using Upcast_ptr = std::unique_ptr<CompUpcast>;

#endif