#include "includes\spell.h"

Spell::Spell(std::string name, std::string description, bool isTeleport, bool isPortal, bool isArea, bool isAll, uint8_t damageType, uint8_t cost) {

	this->m_name = name;
	this->m_description = description;
	this->m_isTeleport = isTeleport;
	this->m_isPortal = isPortal;
	this->m_isArea = isArea;
	this->m_isAll = isAll;
	this->m_damageType = damageType;
	this->m_cost = cost;

}

Spell& Flare::get() {
	static Flare flare(
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
	static Freeze freeze(
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
	static Shock shock(
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
	static Teleport teleport(
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
	static Flame flame(
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
	static Ice ice(
		"Ice",
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
	static Lightning lightning(
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
	static Portal portal(
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
	static Inferno inferno(
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
	static Cocitus cocitus(
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
	static Tempest tempest(
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