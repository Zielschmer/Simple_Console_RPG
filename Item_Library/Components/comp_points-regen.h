#ifndef COMP_POINTS_REGEN
#define COMP_POINTS_REGEN

#include "..\..\..\utilities\utils.h"
#include "Component.h"

struct CompPointsRegen : public Component {
	using Component::Component;
	HP m_regenHP;
	SP m_regenSP;
};

using PointsRegen_ptr = std::unique_ptr<CompPointsRegen>;

#endif