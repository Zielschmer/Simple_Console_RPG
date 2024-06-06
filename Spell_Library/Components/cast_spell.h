#pragma once

#include <string>

struct Spell {

	std::string m_name;
	std::string m_description;
	bool m_isTeleport;
	bool m_isPortal;
	bool m_isArea;
	bool m_isAll;
	int m_damageType;
	int m_cost;

};

enum SpellList {

	MAGIC_MISSILES,
	FLARE,
	FREEZE,
	SHOCK,
	TELEPORT,
	FLAME,
	BLIZZARD,
	BOLT,
	PORTAL,
	INFERNO,
	COCITUS,
	STORM

};

Spell getSpell(SpellList spellList);

std::string spellLibrary(SpellList spellList);