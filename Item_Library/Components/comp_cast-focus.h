#ifndef COMP_CAST_FOCUS
#define COMP_CAST_FOCUS

#include "..\utils.h"
#include "Component.h"

struct CompCastFocus : public Component {
	using Component::Component;
	bool m_spell;
	bool m_pray;
	bool m_song;
};

using CastFocus_ptr = std::unique_ptr<CompCastFocus>;

#endif#pragma once
