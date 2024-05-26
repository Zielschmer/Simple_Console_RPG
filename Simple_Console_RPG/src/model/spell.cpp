#include "includes\spell.h"

Spell::Spell(std::string name, std::string description, bool isTeleport, bool isPortal, bool isArea, bool isAll, uint8_t damageType, uint8_t cost) {

	std::string m_name = name;
	std::string m_description = description;
	bool m_isTeleport = isTeleport;
	bool m_isPortal = isPortal;
	bool m_isArea = isArea;
	bool m_isAll = isAll;
	uint8_t m_damageType = damageType;
	uint8_t m_cost = cost;

}

Spell& Flare::get() {
	static Spell flare(
		"Flare",
		"Set one enemy ablaze.",
		false,
		false,
		false,
		false,
		0,
		1
	);
	return flare;
}

Spell& Freeze::get() {
	static Spell freeze(
		"Freeze",
		"Freeze one enemy.",
		false,
		false,
		false,
		false,
		1,
		1
	);
	return freeze;
}

Spell& Shock::get() {
	static Spell shock(
		"Shock",
		"Eletrecute one enemy.",
		false,
		false,
		false,
		false,
		2,
		1
	);
	return shock;
}

Spell& Teleport::get() {
	static Spell teleport(
		"Teleport",
		"EScape the dungeon.",
		true,
		false,
		false,
		false,
		0,
		1
	);
	return teleport;
}

Spell& Flame::get() {
	static Spell flame(
		"Flame",
		"Set an enemy and adjacents ablaze.",
		false,
		false,
		true,
		false,
		0,
		2
	);
	return flame;
}

Spell& Ice::get() {
	static Spell ice(
		"Flame",
		"Freeze an enemy and adjacents.",
		false,
		false,
		true,
		false,
		1,
		2
	);
	return ice;
}

Spell& Lightning::get() {
	static Spell lightning(
		"Lightning",
		"Eletrocute an enemy and adjacents.",
		false,
		false,
		true,
		false,
		2,
		2
	);
	return lightning;
}

Spell& Portal::get() {
	static Spell portal(
		"Portal",
		"Create a portal to the city and back.",
		false,
		true,
		false,
		false,
		0,
		2
	);
	return portal;
}

Spell& Inferno::get() {
	static Spell inferno(
		"Inferno",
		"Set all enemies ablaze.",
		false,
		false,
		false,
		true,
		0,
		3
	);
	return inferno;
}

Spell& Cocitus::get() {
	static Spell cocitus(
		"Cocitus",
		"Freeze all enemies.",
		false,
		false,
		false,
		true,
		1,
		3
	);
	return cocitus;
}

Spell& Tempest::get() {
	static Spell tempest(
		"Inferno",
		"Electrocute all enemies.",
		false,
		false,
		false,
		true,
		2,
		3
	);
	return tempest;
}